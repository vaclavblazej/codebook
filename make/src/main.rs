use std::{env, path::{PathBuf, Path}};

// use notify::{Event, RecursiveMode, Watcher, EventKind::Modify, event::{ModifyKind::Data, DataChange::Any}};
// use std::sync::mpsc;
use regex::Regex;

pub mod file;

#[derive(Debug, Default)]
struct Snippet {
    title: Option<String>,
    time: Option<String>,
    description: Option<String>,
    content: String,
    part: String,
}

#[derive(Debug, PartialEq, Eq, Clone)]
enum Property {
    Author,
    License,
    History,
    Title,
    Description,
    Time,
}

#[derive(Debug)]
enum ParsingState{
    Before,
    Properties,
    Content,
    After,
}

fn load_code(code_folder: &Path, filepath: &PathBuf, part: String) -> anyhow::Result<Snippet> {
    let path = code_folder.join(filepath);
    let beginning_simple = format!("// {}", part);
    let beginning = format!("/** {}", part);
    let ending = format!("/// {}", part);
    let mut snippet = Snippet{
        part,
        ..Default::default()
    };
    // todo - preload the snippet from the beginning of the file
    let filelines = file::read_file_content(&path)?;
    let mut state = ParsingState::Before;
    let mut last_property: Option<Property> = None;
    let mut property: Option<Property> = None;
    let mut value_vec: Vec<String> = Vec::new();
    let mut new_value_line: Option<String> = None;
    let property_regex = Regex::new(r" \* (?<property>[^:]+): (?<value>.*)").unwrap();
    // r"'(?<title>[^']+)'\s+\((?<year>\d{4})\)
    for rawline in filelines.split("\n") {
        let line = String::from(rawline);
        match state {
            ParsingState::Before => {
                // println!("before {}", line);
                if line == beginning {
                    state = ParsingState::Properties;
                } else if line ==  beginning_simple {
                    state = ParsingState::Content;
                }
            },
            ParsingState::Properties => {
                // println!("properties {}", line);
                let write =
                    if line == " */" {
                        state = ParsingState::Content;
                        true
                    } else if let Some(captures) = property_regex.captures(&line) {
                        let property_name = captures.name("property").expect("unable to load property").as_str();
                        let value_line = captures.name("value").expect("unable to load value").as_str();
                        new_value_line = Some(String::from(value_line.trim()));
                        // println!("loading {:?}", property_name);
                        match property_name {
                            "Author" => property = Some(Property::Author),
                            "License" => property = Some(Property::License),
                            "History" => property = Some(Property::History),
                            "Title" => property = Some(Property::Title),
                            "Description" => property = Some(Property::Description),
                            "Time" => property = Some(Property::Time),
                            _ => {
                                property = None;
                                println!("unknown property '{}'", property_name);
                            },
                        }
                        if let (Some(a), Some(b)) = (&last_property, &property) {
                            a != b
                        } else {
                            false
                        }
                    } else {
                        new_value_line = Some(String::from(line[3..].trim()));
                        false
                    };
                if write {
                    if let Some(p) = &last_property {
                        let value = value_vec.join(" ");
                        // println!("saving {:?}", p);
                        match p {
                            Property::Description => snippet.description = Some(value),
                            Property::Time => snippet.time = Some(value),
                            Property::Title => snippet.title = Some(value),
                            Property::Author => {},
                            Property::License => {},
                            Property::History => {}
                        }
                    }
                    value_vec = Vec::new();
                }
                last_property = property.clone();
                if let Some(line) = new_value_line {
                    value_vec.push(line);
                }
                new_value_line = None;
            },
            ParsingState::Content => {
                // println!("content {}", line);
                if line == ending {
                    state = ParsingState::After;
                } else {
                    snippet.content += &format!("{}\n", line);
                }
            },
            ParsingState::After => {
                // println!("after {}", line);
            },
        }
    }
    Ok(snippet)
}

fn replace(code_folder: &Path, content: &str) -> anyhow::Result<String> {
    let todos = Regex::new(r"\\todo\([^\)]+\)\n").unwrap();
    let res_1 = todos.replace_all(content, |_: &regex::Captures| { "" });
    let res_1_str = String::from(res_1);
    let pattern = Regex::new(r"\\code\((?P<filepath>[^\)]+),(?P<part>[^\)]+)\)").unwrap();
    let res_2 = pattern.replace_all(&res_1_str, |caps: &regex::Captures| {
        let filepath = caps.name("filepath").expect("the \\code command requires filepath as an argument").as_str();
        println!("found match {}", filepath);
        let part: Option<regex::Match> = caps.name("part");
        let file = PathBuf::from(filepath);
        if code_folder.join(&file).is_file() {
            let rpart: String = part.map(|x| String::from(x.as_str())).unwrap();
            println!("  successfully replaced with the content of {:?}", filepath);
            let snippet = load_code(code_folder, &file, rpart).unwrap();
            let mut res = String::new();
            if let Some(title) = snippet.title {
                res += &format!("\n### {}\n\n", title);
            }
            if let Some(description) = snippet.description {
                res += &format!("\n*Description:* {}\n", description);
            }
            if let Some(time) = snippet.time {
                res += &format!("\n*Time:* {}\n", time);
            }
            res += &format!("\n{},{}\n", filepath, snippet.part);
            res += &format!("\n```cpp\n{}```\n\n", snippet.content);
            res
        } else {
            println!("  error replacing {:?}", filepath);
            format!("error replacing {:?}", filepath)
        }
    });
    let res_2_str = String::from(res_2);
    Ok(res_2_str)
}

fn process(code_folder: &Path, target_path: &PathBuf, file: &PathBuf) -> anyhow::Result<()> {
    let content = file::read_file_content(file)?;
    let new_content = replace(code_folder, &content)?;
    file::write_file_content(target_path, &new_content)?;
    println!("completed {:?}", target_path);
    Ok(())
}

fn main() -> anyhow::Result<()> {
    println!("replacing");
    let current = env::current_dir().unwrap();
    let main_folder = current.parent().unwrap();
    let content_folder = main_folder.join("content");
    let code_folder = main_folder.join("solutions");
    let markdown_folder = main_folder.join("web").join("content");
    let files: Vec<PathBuf> = file::iterate_folder_recursively(&content_folder);
    for file in &files {
        if file.is_file() {
            let target_path = file::reparent(file, &content_folder, &markdown_folder)?;
            process(&code_folder, &target_path, file)?;
        }
    }
    // println!("watching for changes");
    // let (tx, rx) = mpsc::channel::<notify::Result<Event>>();
    // let mut watcher = notify::recommended_watcher(tx)?;
    // watcher.watch(&content_folder, RecursiveMode::Recursive)?;
    // for res in rx {
        // match res {
            // Ok(event) => {
                // if let Modify(Data(Any)) = event.kind {
                    // for path in event.paths {
                        // if path.is_file() {
                            // let target_path = file::reparent(&path, &content_folder, &markdown_folder)?;
                            // process(&code_folder, &target_path, &path)?;
                        // }
                    // }
                // }
            // },
            // Err(e) => println!("watch error: {:?}", e),
        // }
    // }
    Ok(())
}

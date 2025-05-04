
use std::path::PathBuf;


pub struct Page {
    pub title: String,
    pub url: PathBuf,
    pub intro: Option<String>,
}

impl Page {
    pub fn new(title: &str, url: &PathBuf, intro: Option<&str>) -> Self {
        Self {
            title: String::from(title),
            url: url.clone(),
            intro: intro.map(|x|String::from(x)),
        }
    }
}

pub struct Tag {
    pub name: String,
}

pub struct Provider {
    pub name: String,
}

pub struct Reference {
    pub provider: Provider,
    pub name: Option<String>,
    pub url: String,
}

pub struct Content {
    pub name: String,
    pub description: String,
    pub frequency: u8,
    pub tags: Vec<Tag>,
    pub references: Vec<Reference>,
}

// todo: untie technique from snippets? unsure how exactly do this when snippets are in files and
// they also contain title, description, etc.; I think the particular code should be untied from
// the general technique, but it also demonstrates the technique

#[derive(Debug, Default)]
pub struct Snippet {
    pub title: Option<String>,
    pub time: Option<String>,
    pub description: Option<String>,
    pub content: String,
    pub part: String,
}


pub struct Section {
    pub name: String,
    pub content: Vec<Content>,
}

impl Section {
    pub fn new(name: &str) -> Self {
        Self {
            name: String::from(name),
            content: Vec::new(),
        }
    }
}

pub struct Chapter {
    pub name: String,
    pub sections: Vec<Section>,
}

impl Chapter {
    pub fn new(name: &str) -> Self {
        Self {
            name: String::from(name),
            sections: Vec::new()
        }
    }
}

pub struct Cell {
    pub content: String,
    pub width: u8,
}

pub struct Row {
    pub cells: Vec<Cell>,
}

pub struct Table {
    pub header: Vec<String>,
    pub content: Vec<Row>,
}

// ## Algorithm's Complexity

// * Amortized time complexity - Mathematical notation that simplifies how we denote the number of operations performed (or memory used) by an algorithm. [USACO](https://usaco.guide/bronze/time-comp), [Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)

pub struct Data {
    pub chapters: Vec<Chapter>,
}


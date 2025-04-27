+++
title = "Language & Style"
+++

Many languages are used by teams for competitive programming but `c++` enjoys the widest adoption, hence, this book uses `c++` as the main language.
Also see [USACO: Choosing a language](https://usaco.guide/general/choosing-lang).
However, there are a few (somewhat rare) cases where other languages may provide significantly shorter solutions.


* expression evaluation
	* python `eval`
* big integers
	* java `BigInteger`
	* python native

## Code style

Aim of the code style in the book is to be unambiguous and short.
Whitespaces are added for clarity and are omitted to express tightly linked meaning.

* [K&R style](https://en.wikipedia.org/wiki/Indentation_style#K&R) brackets to use less lines while clearly marking span of the block
* `for`, `while`, etc. with no curly brackets `{}` contain the expression on the same line to avoid errors through line insertion
* generally one line per expression but expressions that strongly belong to each other may occupy the same line
* custom structures are capitalized
* for clarity, spaces around assignment operators `=`, `+=`, `*=` etc. (except inside `for`), colon `:` in `for`, brackets after `while`, `if`, `for`
* space after `,` in parameter lists; can be left out of constructors `{a,b}` as values have tightly linked meaning
* optional spaces around boolean and integer operators to convey logical meaning `a+b*b == c+(x==q)`
* expressions can be spread over multiple lines and have extra spaces to mark important similarities
* line comments `//` can occupy separate lines or have two spaces before and one after double slash

For purely typesetting reasons the code is indented with tabs.
Tabs are displayed with 4 spaces for clarity.
Any extra padding to display aligned code is done with spaces.

Number of symbols on a line is generally limited to 50.
In cases where long lines considerably improve clarity the line length is limited to 100.

```cpp
while (--t) {
	...
}
for (ll &el : a) cin >> el;
for (ll i=0; i<N; ++i) {
...
vector<Res> func(Graph &g, ll start) {
	ll N = g.size();
	vector<Res> res(N, {-1,INF});  // previous, cost
	res[start] = {start,0};
	priority_queue<El> q;
	q.push({start,0});
	while (!q.empty()) {
		El el = q.top(); q.pop();
		ll id = el.id;
		if (todo[x+y] && todo[x+z]
		 || todo[x-y] && todo[x-z]) {
			for (auto e : g[id]) {
				if (ne < res[v].len) {
					q.push({v,ne});
				}
			}
		}
	}
	return res;
}
```

### Rules of thumb

While the following techniques are short, they may be confusing to people that are less familiar with the language.
We replace left expression with the equivalent right expression for clarity.

Forget operator as rhs.

<div class="multicols">
<div class="col50">

```cpp
return e.process(), f;
```

</div>
<div class="col50">

```cpp
e.process();
return f;
```

</div>
</div>

Bitwise negation as a `-1` check.

<div class="multicols">
<div class="col50">

```cpp
if (~a) { ...
```

</div>
<div class="col50">

```cpp
if (a != -1) { ...
```

</div>
</div>


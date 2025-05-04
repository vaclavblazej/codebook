+++
title = 'Input & output'
+++

`c++` has two ways to process input and output.

* `c++`-style `cin` and `cout` -- slower, convenient
* `c`-style `scanf` and `printf` -- fast, a bit harder to write

When a problem requires to read input which is big then we may be forced to use faster input reading method (e.g. [CF 463C Gargari and Bishops](https://codeforces.com/problemset/problem/463/C)).
Read more on [USACO: Input & Output](https://usaco.guide/general/input-output) and [USACO: Fast Inpyt & Output](https://usaco.guide/general/fast-io).

## Cin & cout

`cin` and `cout` are objects with overloaded bitshift operators `>>` and `<<` for many types.
The operation `cin >> a` returns `cin` so we can apply the operator it repeatedly.
These operators are left-associative so `cin >> a >> b` is `(cin >> a) >> b`, similarly for `cout`.

<div class="multicols">
<div class="col50">

```cpp
ll N;
string greet;
cin >> N >> greet;
vector<ll> a(N);
for (ll &e : a) cin >> e;
for (ll e : a) cout << e << ' ';
cout << endl;
```

</div>
<div class="col50">

```txt
>>> input >>>
7 hello
1 2 3 4 5 6 7
<<< output <<<
1 2 3 4 5 6 7 
```

</div>
</div>

Loading the standard types `ll` and `string` first skips whitespaces.
One may need to use `getline` if it is important to load lines first, and parse them later.

```cpp
string line;
getline(cin, line);
```

The following code speeds up io by breaking synchronization.
One should *not* use `scanf`, `printf` if this is applied.
Moreover, for interactive problems one needs to be careful to *flush* the output.

```cpp
ios_base::sync_with_stdio(false); // disables C and C++ i/o synchronization
cin.tie(nullptr);                 // disables cin and cout synchronization
```

## Files

We can change default input and output to be to files instead of standard input and output.
This means one can code with `cin` and `cout` as normally by adding the following lines at the beginning of the main function.

```cpp
freopen("file.in","r",stdin);
freopen("file.out","w",stdout);
```

## Scanf & printf

```cpp
ll N;
char greet[25];
scanf("%lld%s", &N, greet);
printf("%s", greet);
vector<ll> a(N);
for (ll &e : a) scanf("%lld", &e);
for (ll e : a) printf("%lld ", e);
printf("\n");
```

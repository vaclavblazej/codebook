
`c++` has two ways to process input and output.

* `c++`-style `cin` and `cout` -- slower, convenient
* `c`-style `scanf` and `printf` -- fast, a bit harder to write

When a problem requires to read input which is big then we may be forced to use faster input reading method (e.g. [CF 463C Gargari and Bishops](https://codeforces.com/problemset/problem/463/C)).

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
for(ll &e : a) cin >> e;
for(ll e : a) cout << e << ' ';
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


The following code speeds up `cin`, `cout` by breaking synchronization.
One should *not* use `scanf`, `printf` if this is applied.

```cpp
ios_base::sync_with_stdio(0); // disables C and C++ i/o synchronization
cin.tie(0);                   // disables cin and cout synchronization
```

## Scanf & printf

```cpp
ll N;
char greet[25];
scanf("%lld%s", &N, greet);
printf("%s", greet);
vector<ll> a(N);
for(ll &e : a) scanf("%lld", &e);
for(ll e : a) printf("%lld ", e);
printf("\n");
```

+++
title = 'The Book of Code'
+++

This text is a quick competitive programming reference for `c++` coders.
The most useful material is contained here.
[Follow links]() to see discussion, examples, and references.

Before reading, be sure to know about
[this document & basic terminology](about),
[competitive programming](comprog),
[coding language & style](language),
[coding environment](setup),
[custom templates](template),
[input & output](io),
[compiling & running](run).
<!-- [problemsolving checklist](checklist), -->
<!-- [list of techniques](techniques). -->

---

The following [template](template) is assumed in all of the codes within this book.

\code(template.h,template)

{{< toc >}}

# Introduction

## Quick reference

### Standard library functions

<tt>
<table>
<tr><th> function call </th><th> complexity </th><th> meaning </th></tr>

<tr><td> sort(a.begin(), a.end()) </td><td> $O(N \log N)$ </td><td> sorts the array increasingly </td></tr>
<tr><td colspan=2> sort(s.begin(), s.end(), greater&lt;ll&gt;()); </td><td> ... decreasingly </td></tr>
<tr><td colspan=2> sort(s.begin(), s.end(), custom); </td><td> custom sorting </td></tr>
<tr><td colspan=3> struct { bool operator()(int a, int b) const { return a < b; } } custom; </td></tr>

<tr><td> swap(a, b)    </td><td> $O(1)$           </td><td> swaps elements </td></tr>
<tr><td> iota(a.begin(), a.end(), val) </td><td> $O(N)$ </td><td> fills with gradually increasing ++val </td></tr>
<tr><td> reverse(a.begin(), a.end()) </td><td> $O(N)$ </td><td> reverses contents of the array </td></tr>
<tr><td> rotate(a.begin(), a.begin()+shift, a.end()) </td><td> $O(N)$ </td><td> left shifts contesnts of the array </td></tr>
<tr><td> tie(a1, ..., aN) </td><td> $O(N)$ </td><td> return elements as a lhs tuple (allows assignment) </td></tr>

</table>
</tt>

### Standard library data structures

<tt>
<table>
<tr><th> structure     </th><th> operation     </th><th> returns       </th><th> complexity    </th><th> note </th></tr>

<tr><td> vector&lt;V&gt;   </td><td colspan=4> dynamically-resizable array, fast element access </td></tr>
<tr><td>               </td><td> assign(len,def)  </td><td> V              </td><td> len           </td><td>   </td></tr>
<tr><td>               </td><td> operator[idx]    </td><td> V              </td><td> $O(1)$        </td><td>   </td></tr>
<tr><td>               </td><td> push_back(V)     </td><td> --             </td><td> $O'(1)$ amortized      </td><td>   </td></tr>
<tr><td>               </td><td> pop_back()       </td><td> --             </td><td> $O(1)$        </td><td>   </td></tr>
<tr><td>               </td><td> back()           </td><td> V              </td><td> $O(1)$        </td><td>   </td></tr>
<tr><td>               </td><td> reserve(size)    </td><td> --             </td><td> size          </td><td>   </td></tr>
<tr><td>               </td><td> resize(size,def) </td><td> --             </td><td> size          </td><td>   </td></tr>

<tr><td> set&lt;V&gt; </td><td colspan=4> collection of unique keys, iterable by sorted keys </td></tr>
<tr><td>               </td><td> insert(V)      </td><td> pair<it,ok> </td><td> $O(\log N)$ </td><td> pair(it, was inserted?) </td></tr>
<tr><td>               </td><td> find(V)        </td><td> it          </td><td> $O(\log N)$ </td><td> not found => end </td></tr>
<tr><td>               </td><td> lower_bound(V) </td><td> it          </td><td> $O(\log N)$ </td><td> finds first $\ge$      </td></tr>
<tr><td>               </td><td> upper_bound(V) </td><td> it          </td><td> $O(\log N)$ </td><td> finds first $>$       </td></tr>
<tr><td>               </td><td> count(V)       </td><td> #found      </td><td> $O(\log N)$ </td><td> #found = 0 or 1   </td></tr>
<tr><td>               </td><td> erase(V)       </td><td> #erased     </td><td> $O(\log N)$ </td><td> #erased = 0 or 1  </td></tr>
<tr><td>               </td><td> erase(it)      </td><td> next it     </td><td> $O(\log N)$ </td><td>                    </td></tr>

<tr><td> multiset&lt;V&gt; </td><td colspan=4> collection of keys, iterable by sorted keys, has all tde same operations as set<V>, but all behave slightly differently</td><tr>
<tr><td> unordered_set&lt;V&gt;, unordered_multiset </td><td colspan=4> variants which use hash_tables instead of search trees, tdis makes operations faster $O(1)$, but disables sorted iterating; there is no find, lower_bound, upper_bound</td><tr>

<tr><td>map&lt;K,V&gt;  </td><td colspan=4> key-value pairs, unique keys, iterable by sorted keys</td></tr>
<tr><td>          </td><td> operator[K]    </td><td> V        </td><td> $O(\log N)$ </td><td> creates nonexistent</td></tr>
<tr><td>          </td><td> find(K)        </td><td> it       </td><td> $O(\log N)$ </td><td> find | end</td></tr>
<tr><td>          </td><td> lower_bound(V) </td><td> it       </td><td> $O(\log N)$ </td><td> find first $\ge$</td></tr>
<tr><td>          </td><td> upper_bound(V) </td><td> it       </td><td> $O(\log N)$ </td><td> find first $>$</td></tr>
<tr><td>          </td><td> count(V)       </td><td> #found   </td><td> $O(\log N)$ </td><td> #found = 0 or 1</td></tr>
<tr><td>          </td><td> erase(V)       </td><td> #erased  </td><td> $O(\log N)$ </td><td> #erased = 0 or 1</td></tr>
<tr><td>          </td><td> erase(it)      </td><td> next it  </td><td> $O(\log N)$ </td><td> </td></tr>

<tr><td> multimap&lt;K,V&gt; </td><td colspan=4> key-value pairs, iterable by sorted keys, has all the same operations as set<V>, but all behave slightly differently</td><tr>
<tr><td> unordered_map&lt;V&gt;, unordered_multimap </td><td colspan=4> variants which use hash_tables instead of search trees, this makes operations faster $O(1)$, but disables sorted iterating; there is no find, lower_bound, upper_bound</td><tr>

<tr><td> stack&lt;V&gt;  </td><td colspan=4> last in first out, (is a deque wrapper) </td></tr>
<tr><td></td><td> push(V)         </td><td> --        </td><td> $O(1)$      </td><td> = push_back() </td></tr>
<tr><td></td><td> top()           </td><td> V         </td><td> $O(1)$      </td><td> = back() </td></tr>
<tr><td></td><td> pop()           </td><td> --        </td><td> $O(1)$      </td><td> = pop_back() </td></tr>

<tr><td> queue&lt;V&gt;  </td><td colspan=4> first in first out, (is a deque wrapper) </td></tr>
<tr><td></td><td> push(V)         </td><td> --        </td><td> $O(1)$      </td><td> = push_back() </td></tr>
<tr><td></td><td> front()         </td><td> V         </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> back()          </td><td> V         </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> pop()           </td><td> --        </td><td> $O(1)$      </td><td> = pop_front() </td></tr>

<tr><td> deque&lt;V&gt;  </td><td colspan=4> double-ended queue, quick access to beginning and end} </td></tr>
<tr><td></td><td> push_front(V)  </td><td> --        </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> front()        </td><td> V         </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> pop_front()    </td><td> --        </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> push_back(V)   </td><td> --        </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> back()         </td><td> V         </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> pop_back()     </td><td> --        </td><td> $O(1)$      </td><td>  </td></tr>

<tr><td> priority_queue&lt;V&gt; </td><td colspan=4> constant time lookup of the largest element </td></tr>
<tr><td></td><td colspan=4> minimal pq = priority_queue&lt;V,vector&lt;V&gt;,greater&lt;V&gt;&gt;  </td></tr>
<tr><td></td><td> push(V)       </td><td> --        </td><td> $O(\log N)$  </td><td>  </td></tr>
<tr><td></td><td> top()         </td><td> V         </td><td> $O(1)$       </td><td>  </td></tr>
<tr><td></td><td> pop()         </td><td> --        </td><td> $O(\log N)$  </td><td>  </td></tr>

<tr><td> string </td><td colspan=4> array of characters </td></tr>
<tr><td></td><td> substr(start)        </td><td> string </td><td> $O({\rm len}-{\rm start})$  </td><td> suffix of a string </td></tr>
<tr><td></td><td> substr(start, count) </td><td> string </td><td> $O({\rm count})$  </td><td> substring between [start, start+count) </td></tr>

</table>
</tt>

* number of elements: `empty()`, `size()`,
* resetting the structure: `clear()`,
* iterators: `begin()` and `end()`, (for reversed `rbegin()` and `rend()`),
* accessing the elements: `operator[]` or `at`.

### Ascii table

<div class="multicols">
<div class="col50">

| num | binary   | meaning     | num | binary   | meaning     |
| --- | ------   | -------     | --- | ------   | -------     |
| 0   | 00000000 | (NULL)      | 32  | 00100000 | `Space`     |
| 1   | 00000001 | (--)        | 33  | 00100001 | `!`         |
| 2   | 00000010 | (--)        | 34  | 00100010 | `"`         |
| 3   | 00000011 | (--)        | 35  | 00100011 | `#`         |
| 4   | 00000100 | (--)        | 36  | 00100100 | `$`         |
| 5   | 00000101 | (--)        | 37  | 00100101 | `%`         |
| 6   | 00000110 | (--)        | 38  | 00100110 | `&`         |
| 7   | 00000111 | (--)        | 39  | 00100111 | `'`         |
| 8   | 00001000 | (backspace) | 40  | 00101000 | `(`         |
| 9   | 00001001 | (hor. tab)  | 41  | 00101001 | `)`         |
| 10  | 00001010 | (LF)        | 42  | 00101010 | `*`         |
| 11  | 00001011 | (ver. tab)  | 43  | 00101011 | `+`         |
| 12  | 00001100 | (new page)  | 44  | 00101100 | `,`         |
| 13  | 00001101 | (CR)        | 45  | 00101101 | `-`         |
| 14  | 00001110 | (--)        | 46  | 00101110 | `.`         |
| 15  | 00001111 | (--)        | 47  | 00101111 | `/`         |
| 16  | 00010000 | (--)        | 48  | 00110000 | `0`         |
| 17  | 00010001 | (--)        | 49  | 00110001 | `1`         |
| 18  | 00010010 | (--)        | 50  | 00110010 | `2`         |
| 19  | 00010011 | (--)        | 51  | 00110011 | `3`         |
| 20  | 00010100 | (--)        | 52  | 00110100 | `4`         |
| 21  | 00010101 | (--)        | 53  | 00110101 | `5`         |
| 22  | 00010110 | (--)        | 54  | 00110110 | `6`         |
| 23  | 00010111 | (--)        | 55  | 00110111 | `7`         |
| 24  | 00011000 | (--)        | 56  | 00111000 | `8`         |
| 25  | 00011001 | (--)        | 57  | 00111001 | `9`         |
| 26  | 00011010 | (--)        | 58  | 00111010 | `:`         |
| 27  | 00011011 | (escape)    | 59  | 00111011 | `;`         |
| 28  | 00011100 | (--)        | 60  | 00111100 | `<`         |
| 29  | 00011101 | (--)        | 61  | 00111101 | `=`         |
| 30  | 00011110 | (--)        | 62  | 00111110 | `>`         |
| 31  | 00011111 | (--)        | 63  | 00111111 | `?`         |

</div>
<div class="col50">

| num | binary   | meaning     | num | binary   | meaning     |
| --- | ------   | -------     | --- | ------   | -------     |
| 64  | 01000000 | `@`         | 96  | 01000000 | ```         |
| 65  | 01000001 | `A`         | 97  | 01000001 | `a`         |
| 66  | 01000010 | `B`         | 98  | 01000010 | `b`         |
| 67  | 01000011 | `C`         | 99  | 01000011 | `c`         |
| 68  | 01000100 | `D`         | 100 | 01000100 | `d`         |
| 69  | 01000101 | `E`         | 101 | 01000101 | `e`         |
| 70  | 01000110 | `F`         | 102 | 01000110 | `f`         |
| 71  | 01000111 | `G`         | 103 | 01000111 | `g`         |
| 72  | 01001000 | `H`         | 104 | 01001000 | `h`         |
| 73  | 01001001 | `I`         | 105 | 01001001 | `i`         |
| 74  | 01001010 | `J`         | 106 | 01001010 | `j`         |
| 75  | 01001011 | `K`         | 107 | 01001011 | `k`         |
| 76  | 01001100 | `L`         | 108 | 01001100 | `l`         |
| 77  | 01001101 | `M`         | 109 | 01001101 | `m`         |
| 78  | 01001110 | `N`         | 110 | 01001110 | `n`         |
| 79  | 01001111 | `O`         | 111 | 01001111 | `o`         |
| 80  | 01010000 | `P`         | 112 | 01010000 | `p`         |
| 81  | 01010001 | `Q`         | 113 | 01010001 | `q`         |
| 82  | 01010010 | `R`         | 114 | 01010010 | `r`         |
| 83  | 01010011 | `S`         | 115 | 01010011 | `s`         |
| 84  | 01010100 | `T`         | 116 | 01010100 | `t`         |
| 85  | 01010101 | `U`         | 117 | 01010101 | `u`         |
| 86  | 01010110 | `V`         | 118 | 01010110 | `v`         |
| 87  | 01010111 | `W`         | 119 | 01010111 | `w`         |
| 88  | 01011000 | `X`         | 120 | 01011000 | `x`         |
| 89  | 01011001 | `Y`         | 121 | 01011001 | `y`         |
| 90  | 01011010 | `Z`         | 122 | 01011010 | `z`         |
| 91  | 01011011 | `[`         | 123 | 01011011 | `{`         |
| 92  | 01011100 | `\`         | 124 | 01011100 | (pipe)      |
| 93  | 01011101 | `]`         | 125 | 01011101 | `}`         |
| 94  | 01011110 | `^`         | 126 | 01011110 | `~`         |
| 95  | 01011111 | `_`         | 127 | 01011111 | `DEL`       |

</div>
</div>

### Numerical constants

| SYMBOL (`c++`)                    | value                                   |
| -------------------------------   | -------                                 |
| Chapernowne's n.                  | $0.12345678910111213141516171819202122$ |
| $\log_{10}2$                      | $0.30102999566398119521373889472449302$ |
| Catalan's c.                      | $0.91596559417721901505460351493238411$ |
| $\zeta(3)$                        | $1.20205690315959428539973816151144999$ |
| $\ln \pi$                         | $1.14472988584940017414342735135305871$ |
| $\sqrt{2}$                        | $1.41421356237309504880168872420969807$ |
| $\log_2{3}$                       | $1.58496250072115618145373894394781650$ |
| $\phi$ (gold.r.) `=(1+sqrt(5))/2` | $1.61803398874989484820458683436563811$ |
| $\zeta(2)=\pi/6$                  | $1.64493406684822643647241516664602518$ |
| $\sqrt{3}$                        | $1.73205080756887729352744634150587236$ |
| $\sqrt{\pi}$                      | $1.77245385090551602729816748334114518$ |
| $\sqrt{5}$                        | $2.23606797749978969640917366873127623$ |
| $\sqrt{2\pi}$                     | $2.50662827463100050241576528481104525$ |
| $\sqrt{7}$                        | $2.64575131106459059050161575363926042$ |
| Hilbert's n. $2^{\sqrt 2}$        | $2.66514414269022518865029724987313984$ |
| $e$                               | $2.71828182845904523536028747135266249$ |
| $\pi$ `=M_PI`, `=4*atan(1.)`      | $3.14159265358979323846264338327950288$ |
| $\sqrt{10}$                       | $3.16227766016837933199889354443271853$ |
| $\sqrt{11}$                       | $3.31662479035539984911493273667068668$ |
| $\log_2{10}$                      | $3.32192809488736234787031942948939017$ |
| $2 \pi=\tau$                      | $6.28318530717958647692528676655900576$ |
| $\pi^2$                           | $9.86960440108935861883449099987615113$ |
| $\pi^e$                           | $22.4591577183610454734271522045437350$ |
| $e^\pi$                           | $23.1406926327792690057290863679485473$ |


## Primes, Factorization, and Divisors

\code(math/primes.cpp,eratosthenes)
\code(math/primes.cpp,factorization)
\code(math/primes.cpp,sumdivisors)
\code(math/divisors.cpp,divisors)

\code(math/gcd.cpp,shortgcdlcm)
\code(math/gcd.cpp,extendedgcd)

## Combinatorics & Modular arithmetic

Many modular functions require a global prime `mod`.

```cpp
const ll mod = 1000000007ll; // prime
ll d(ll n) { return n%mod; }
```

\todo(chinese remainder theorem)

\code(math/modular_arithmetics.cpp,powmod)
\code(math/modular_arithmetics.cpp,combmod)

### Binomial identities

[Pascal's identity](https://en.wikipedia.org/wiki/Pascal%27s_rule)
$\binom {n-1}{k-1} + \binom {n-1}k = \binom nk$

[Hockey-stick identity](https://en.wikipedia.org/wiki/Hockey-stick_identity)
$\binom kk + \binom {k+1}k + \dots + \binom {n-1}k + \binom nk = \binom{n+1}{k+1}$

$\sum_{k=0}^n \binom nk = 2^n$

## Searches

<div class="multicols">
<div class="col50">
\code(arrays/search/search_binary.cpp,lsearch)
</div>
<div class="col50">
\code(arrays/search/search_binary.cpp,dsearch)
</div>
</div>

\code(arrays/search/search_binary.cpp,comp)

<div class="multicols">
<div class="col50">
\code(arrays/search/search_ternary.cpp,ternary)
</div>
<div class="col50">
\code(arrays/search/search_ternary.cpp,dternary)
</div>
</div>

## Simple range queries

\code(arrays/array_sum.cpp,array_sum)

\code(data_structures/fenwick.cpp,fenwick)

Fenwick can be used to keep sorted set of small elements with $O(\log n)$ add and remove (direct indexing, change value by +1/-1), with $O(\log^2 n)$ query (binary search the position).

\code(data_structures/segment_tree.cpp,segtree)

# Basics

\todo(## Arrays)

## Trees

\code(trees/lca.cpp,lca)

## Graphs

\code(data_structures/unionfind.cpp,unionfind)
\code(graphs/spanning_tree.cpp,kruskal)
\code(graphs/spanning_tree.cpp,prim)

\todo(## Interval updates)

\todo(lazy segment tree)

## Strings

\todo(regex)

\todo(strings/kmp.cpp,kmp)

\todo(hashing)
\todo(edit distance)
\todo(suffix array, lcp)
\todo(palindrome)

\code(strings/aho-corasick.cpp,aho-corasick)

## Geometry

\code(geometry/basics.cpp,basics)
\code(geometry/basics.cpp,point)

\todo(lines)
\todo(segments)
\todo(circles)
\todo(rotating calipers)

\todo(# Advanced)

\todo(hld)

\todo(## 3D Geometry)

# Other

\code(graphs/cycle_trees.cpp,cycletrees)


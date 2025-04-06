+++
title = 'The Book of Code'
+++

This text is a quick competitive programming reference for `c++` coders.
The most useful material is contained here.
[Follow links]() to see discussion, examples, and references.

Preparation checklist:
[about this document & basic terminology](about),
[competitive programming](comprog),
[coding language & style](language),
[coding environment](setup),
[custom template](template),
[input & output](io),
[compiling & running](run).
<!-- [problemsolving checklist](checklist), -->
<!-- [common techniques](techniques). -->

---

The following [template](template) is assumed in all of the codes within this book.

\code(template.h,template)

### C++ standard library data structures

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
<tr><td>               </td><td> insert(V)      </td><td> pair<it,ok> </td><td> $O(\log N)$ </td><td> was inserted? </td></tr>
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

<tr><td> deque&lt;V&gt;  </td><td colspan=4> double-ended queue, quick access to beginning and end} </td></tr>
<tr><td></td><td> push_front(V)  </td><td> --        </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> front()        </td><td> V         </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> pop_front()    </td><td> --        </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> push_back(V)   </td><td> --        </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> back()         </td><td> V         </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> pop_back()     </td><td> --        </td><td> $O(1)$      </td><td>  </td></tr>

<tr><td> queue&lt;V&gt;  </td><td colspan=4> first in first out, (is a deque wrapper) </td></tr>
<tr><td></td><td> push(V)         </td><td> --        </td><td> $O(1)$      </td><td> = push_back() </td></tr>
<tr><td></td><td> front()         </td><td> V         </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> back()          </td><td> V         </td><td> $O(1)$      </td><td>  </td></tr>
<tr><td></td><td> pop()           </td><td> --        </td><td> $O(1)$      </td><td> = pop_front() </td></tr>

<tr><td> stack&lt;V&gt;  </td><td colspan=4> last in first out, (is a deque wrapper) </td></tr>
<tr><td></td><td> push(V)         </td><td> --        </td><td> $O(1)$      </td><td> = push_back() </td></tr>
<tr><td></td><td> top()           </td><td> V         </td><td> $O(1)$      </td><td> = back() </td></tr>
<tr><td></td><td> pop()           </td><td> --        </td><td> $O(1)$      </td><td> = pop_back() </td></tr>

<tr><td> priority_queue&lt;V&gt; </td><td colspan=4> constant time lookup of the largest element </td></tr>
<tr><td></td><td colspan=4> minimal pq = priority_queue&lt;V,vector&lt;V&gt;,greater&lt;V&gt;&gt;  </td></tr>
<tr><td></td><td> push(V)       </td><td> --        </td><td> $O(\log N)$  </td><td>  </td></tr>
<tr><td></td><td> top()         </td><td> V         </td><td> $O(1)$       </td><td>  </td></tr>
<tr><td></td><td> pop()         </td><td> --        </td><td> $O(\log N)$  </td><td>  </td></tr>

</table>
</tt>

Most of the above structures support the following functions.

* number of elements: `empty()`, `size()`,
* iterators: `begin()`, `end()`, `rbegin()`, `rend()`,
* reseting the structure: `clear()`,

Beware of using `lower_bound` and `upper_bound` on iterators -- it takes $O(N)$ time!

Structures as `set`, `map`, and function `sort` uses `bool operator<(const S &s)const` to compare elements.

You don't need `array` (use global arrays instead) nor `list` (use `vector` or `deque`).

### Ascii Table

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

## Arrays and sequences

\code(arrays/sort/default_library_sort.cpp,base)

\code(arrays/sort/counting_sort.cpp,csort)

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

\code(arrays/array_sum.cpp,array_sum)

\code(data_structures/fenwick.cpp,fenwick)

Fenwick can be used to keep sorted set of small elements with $O(\log n)$ add and remove (direct indexing, change value by +1/-1), with $O(\log^2 n)$ query (binary search the position).

\code(data_structures/segment_tree.cpp,segtree)

\code(data_structures/lca.cpp,lca)


<div class="multicols">
<div class="col50">
\code(data_structures/dynamic_programming.cpp,basis)
</div>
<div class="col50">
\code(data_structures/dynamic_programming.cpp,dp)
</div>
</div>


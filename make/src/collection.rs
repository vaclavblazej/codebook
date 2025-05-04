
use std::path::PathBuf;

use crate::model::{Chapter, Section, Data, Page};

fn build_data() -> Data {
    let root = PathBuf::new();

    let main_page = Page::new("The Book of Code", &root, Some(r#"
This text is a quick competitive programming reference for `c++` coders.
The most useful material is contained here.
[Follow links]() to see discussion, examples, and references.

Before reading, be sure to know about
[this document & basic terminology](about),
[list of techniques](techniques).
<!-- [problemsolving checklist](checklist), -->
            "#));

    let techniques_page = Page::new("List of Techniques", &root.join("techniques"), Some(r#"
While the Book of Code gives a quick reference for implementations of various techniques, this list is an overview of the concepts one should be familiar with in the respective chapters.
            "#));


    let mut intro_chapter = Chapter::new("Introduction");

    let complexity = Section::new("Algorithm's Complexity");
    intro_chapter.sections.push(complexity);

    // * Amortized time complexity - Mathematical notation that simplifies how we denote the number of operations performed (or memory used) by an algorithm. [USACO](https://usaco.guide/bronze/time-comp), [Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
    // * Algorithm analysis - Determine algorithm's time and space complexity.
    // * Master theorem - A simple rule to determine complexity of a recursive algorithm. [Wikipedia](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms)

    // \todo(table of complexities?)

    let mut reference_sec = Section::new("Quick reference");

    // let mut stl_fun = Section::new();
    // intro_chapter.sections.push(stl_fun);


// <table>
// <tr><th> function call </th><th> complexity </th><th> meaning </th></tr>

// <tr><td> sort(a.begin(), a.end()) </td><td> $O(N \log N)$ </td><td> sorts the array increasingly </td></tr>
// <tr><td colspan=2> sort(s.begin(), s.end(), greater&lt;ll&gt;()); </td><td> ... decreasingly </td></tr>
// <tr><td colspan=2> sort(s.begin(), s.end(), custom); </td><td> custom sorting </td></tr>
// <tr><td colspan=3> struct { bool operator()(int a, int b) const { return a < b; } } custom; </td></tr>

// <tr><td> swap(a, b)    </td><td> $O(1)$           </td><td> swaps elements </td></tr>
// <tr><td> iota(a.begin(), a.end(), val) </td><td> $O(N)$ </td><td> fills with gradually increasing ++val </td></tr>
// <tr><td> reverse(a.begin(), a.end()) </td><td> $O(N)$ </td><td> reverses contents of the array </td></tr>
// <tr><td> rotate(a.begin(), a.begin()+shift, a.end()) </td><td> $O(N)$ </td><td> left shifts contesnts of the array </td></tr>
// <tr><td> tie(a1, ..., aN) </td><td> $O(N)$ </td><td> return elements as a lhs tuple (allows assignment) </td></tr>


    // let mut stl_ds = Section::new();
    // intro_chapter.sections.push(stl_ds);

    // ## C++ standard library functions

    // ## C++ standard library data structures

    // * Beware of using `lower_bound` and `upper_bound` on iterators -- it takes $O(N)$ time!
    // * Structures as `set`, `map`, and function `sort` uses `bool operator<(const S &s)const` to compare elements.
    // * You don't need `array` (use global arrays instead) nor `list` (use `vector` or `deque`).

    // ## Techniques

    // * Brute-force / Complete search ([USACO](https://usaco.guide/bronze/intro-complete))
    // * Ad-Hoc ([USACO](https://usaco.guide/bronze/ad-hoc))
    // * Simulation ([USACO](https://usaco.guide/bronze/simulation))
    // * Greedy ([USACO](https://usaco.guide/bronze/intro-greedy))

    // ## Basic awareness of topics

    // * Graph theory

    // ## Primes, Factorization, and Divisors

    // ## Combinatorics & Modular arithmetic

    // * Binary search - Find the first value where a function evaluates to true.
    // * Ternary search - Find the global minimum value, requires function value changes with each step.

    let mut basics_chapter = Chapter::new("Basics");

    // ## General techniques

    // * Recursion
    // * Divide and conquer
    // * Finding interesting points in N log N

    // ## Number theory

    // * Integer parts
    // * Divisibility
    // * Euclidean algorithm [CPA](https://cp-algorithms.com/algebra/euclid-algorithm.html)
    // * Extended Euclidean algorithm [CPA](https://cp-algorithms.com/algebra/extended-euclid-algorithm.html)
    // * Chinese remainder theorem
    // * Linear Diophantine equations [CPA](https://cp-algorithms.com/algebra/linear-diophantine-equation.html)
    // * Fibonacci numbers [CPA](https://cp-algorithms.com/algebra/fibonacci-numbers.html)
    // * Binary Exponentiation [CPA](https://cp-algorithms.com/algebra/binary-exp.html)
    // * Modular arithmetic
    // * Modular multiplication
    // * Modular inverses
    // * Modular exponentiation by squaring
    // * Fermat's little theorem
    // * Euler's theorem
    // * Phi function

    // ## Vectors and matrices

    // * Gaussian elimination
    // * Exponentiation by squaring

    // ## Sorting

    // * Counting sort
    // * Radix sort
    // * Quick sort
    // * Heap sort
    // * Insertion sort
    // * Bubble sort
    // * Selection sort

    // ## Combinatorics

    // * Brute-force with pruning
    // * Meet in the middle
    // * Best-first (A*)
    // * Bidirectional search
    // * Iterative deepening DFS / A*
    // * Pigeon-hole principle
    // * Inclusion/exclusion
    // * Catalan number

    // ## Graph theory

    // * Dynamic graphs (extra book-keeping)
    // * Breadth first search
    // * Depth first search
    // * Normal trees / DFS trees
    // * Dijkstra's algorithm
    // * Minimum spanning tree
    // * Kruskal's algorithm
    // * Prim's algorithm
    // * Bellman-Ford
    // * Konig's theorem and vertex cover
    // * Min-cost max flow
    // * Lovasz toggle
    // * Matrix tree theorem
    // * Maximal matching, general graphs
    // * Hopcroft-Karp
    // * Hall's marriage theorem
    // * Graphical sequences
    // * Floyd-Warshall
    // * Euler cycles
    // * Flow networks
    // * Augmenting paths
    // * Edmonds-Karp
    // * Bipartite matching
    // * Min. path cover
    // * Topological sorting
    // * Strongly connected components
    // * 2-SAT
    // * Cut vertices, cut-edges and biconnected components
    // * Edge coloring
    // * Trees
    // * Vertex coloring
    // * Bipartite graphs (=> trees)
    // * 3^n (special case of set cover)
    // * Diameter and centroid
    // * K'th shortest path
    // * Shortest cycle

    // ## Dynamic programming (DP)

    // * Knapsack
    // * Coin change
    // * Longest common subsequence
    // * Longest increasing subsequence
    // * Number of paths in a dag
    // * Shortest path in a dag
    // * Dynprog over intervals
    // * Dynprog over subsets
    // * Dynprog over probabilities
    // * Dynprog over trees
    // * 3^n set cover
    // * Divide and conquer
    // * Knuth optimization
    // * Convex hull optimizations
    // * RMQ (sparse table a.k.a 2^k-jumps)
    // * Bitonic cycle
    // * Log partitioning (loop over most restricted)

    // ## Strings

    // * Longest common substring
    // * Palindrome subsequences
    // * Knuth-Morris-Pratt
    // * Tries
    // * Rolling polynomial hashes
    // * Suffix array
    // * Suffix tree
    // * Aho-Corasick
    // * Manacher's algorithm
    // * Letter position lists

    // ## Game theory

    // * Combinatorial games
    // * Game trees
    // * Mini-max
    // * Nim
    // * Games on graphs
    // * Games on graphs with loops
    // * Pairing strategy
    // * Grundy numbers
    // * Bipartite games without repetition
    // * General games without repetition
    // * Alpha-beta pruning

    // ## Geometry

    // * Coordinates and vectors
    // * Cross product and scalar product
    // * Convex hull
    // * Pick's theorem
    // * Polygon cut
    // * Closest pair
    // * All segment-segment intersection
    // * Coordinate-compression
    // * Discretization (convert to events and sweep)
    // * Angle sweeping
    // * Line sweeping
    // * Quadtrees
    // * KD-trees

    let mut advanced_chapter = Chapter::new("Advanced");

    // ## Number theory

    // * Miller-Rabin

    // ## Geometry

    // * Voronoi diagram

    let mut other_chapter = Chapter::new("Other");

    // ## Number theory

    // * Frobenius number
    // * Quadratic reciprocity
    // * Pollard-Rho
    // * Hensel lifting
    // * Vieta root jumping

    // ## Todo topics

    // * Probability theory
    // * Discrete second derivatives
    // * Unimodality and convex functions
    // * Binary search on derivative

    // ------------------------------------------------------------

    // # TODO

    // ## Greedy algorithm

    // * Greedy scheduling - Given a list of tasks that have start and end times it is best to schedule the ones that end sooner.
    // * Max contiguous subvector sum
    // * Invariants
    // * Huffman encoding

    // ## Numerical methods

    // * Numeric integration
    // * Newton's method
    // * Root-finding with binary/ternary search
    // * Golden section search

    // ## Data structures

    // * LCA (2^k-jumps in trees in general)
    // * Pull/push-technique on trees
    // * Heavy-light decomposition
    // * Centroid decomposition
    // * Lazy propagation
    // * Self-balancing trees - AVL, Red-black
    // * Convex hull trick (wcipeg.com/wiki/Convex_hull_trick)
    // * Monotone queues / monotone stacks / sliding queues
    // * Sliding queue using 2 stacks
    // * Persistent segment tree

    Data {
        chapters: vec![
            intro_chapter,
            basics_chapter,
            advanced_chapter,
            other_chapter,
        ],
    }
}


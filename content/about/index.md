+++
title = "About"
+++

This document presents short and efficient implementations of standard techniques used in competitive programming.
The main page serves as a quick overview usable during contests -- online as a website or offline as a printout.
The main page contains links that lead to offshoot pages that bluntly introduce the concepts and list references for more detailed explanations.

## Competitive Programming

Read a task, think of a correct solution, correctly code the solution.
This summarizes what solving a single competitive programming task consists of.
Want to know more?: [USACO](https://usaco.guide/general/intro-cp), [Wikpedia](https://en.wikipedia.org/wiki/Competitive_programming)

## Structure of the Book

We divide the content into chapters based on difficulty level.
It is assumed one is familiar with `c++`, or is at least able to find the relevant [documentation](https://en.cppreference.com/w/).

* Introduction - Contains useful overview and rudimentary algorithms. (0-1400)
* Basics - Goes through many common topics and for each lists the main algorithms. (1400-1900)
* Advanced - More complex techniques that are either quite hard or are combining several structures together. (1900+)
* Other - Techniques that do not appear often. (1600+)

---

## Used notation

* Algorithm time and space complexity is described using asymptotic big $O$ notation. E.g. $O(n)$, $O(n \cdot \log n)$, $2^{O(n)}$, see [wikipedia](https://en.wikipedia.org/wiki/Big_O_notation).
* The codes are made to be [beginning inclusive, ending exclusive) -- similarly as the `c++` standard library.

## Resources

For comprehensive explanations refer to books:

* Competitive Programmer’s Handbook by Antti Laaksonen
    * available on https://cses.fi/book.pdf
* Competitive Programming v4 (Book 1 and Book 2)
    * official page https://cpbook.net/ however no link to download
* [USACO Guide](https://usaco.guide/)
* e-maxx's algorithm collection
    * originally in Russian http://e-maxx.ru/algo/
    * cp-algorithms: English translation is available on GitHub https://github.com/cp-algorithms/cp-algorithms

We also acknowledge existence of other resources.

* list of resources [USACO](https://usaco.guide/general/resources-cp)
* Morass's list of problems by concepts https://codeforces.com/blog/-Morass-

## Inspiration

This project is heavily influenced by:

* [KACTL](https://github.com/kth-competitive-programming/kactl) - KTH's ICPC team reference document

## License

The source codes used to generate this website and other parts of the project are under MIT.

The presented codes are licensed under CC0 so that they can be freely used in contests.
More precise licensing of the codes is available in the repository source files.

## Technology

This website is an artifact of an open source [GitHub repository](https://github.com/vaclavblazej/codebook).
The repository contains:

* `solutions` -- `c++` source codes that are presented here
* `content` -- this website's markdown content with custom commands
* `make` -- Rust process which takes `content`, applies the custom commands (that put codes from `solutions` to `content`), and places the result to `web/content`
* `web` -- static website in Hugo which gets the generated content
* `.github` -- GitHub actions setup which deploys this website

The codes in this book are pulled directly from source files (in `solutions` folder) so they can be compiled and run.

Source codes are in `c++ 17`.
Compile with `g++ -std=c++17 file.cpp`.


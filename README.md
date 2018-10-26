# Conrad Bailey's HackerRank Solutions #
This repository holds my original solutions
to [HackerRank](https://hackerrank.com) problems.

Some have corresponding blog posts at
my [website](https://cbailey.tech/hard_probs).

## Building ##
* Running `$ make` in any problem directory will automatically
  download the problem statement, download trivial test cases, and
  build the solution. `$ make clean` will remove all binaries and
  downloaded files.

* Running `make check` will run the solution against all of the
  testcases. If anything fails it will be reported; otherwise the
  tests run silently.

* All problem directories support these `make` targets
  * `all`
  * `clean`
  * `prob.pdf`
  * `answer`
  * `tests`
  * `check`
  * `clean`

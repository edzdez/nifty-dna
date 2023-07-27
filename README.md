# Nifty DNA

A DNA sequence matching tool, based on [this](http://nifty.stanford.edu/2020/dna/) nifty.
Written in C++ 20.

## Example Output

`data.csv`
```csv
name,AGAT,AATG,TATC
Alice,5,2,8
Bob,3,7,4
Charlie,6,1,5
```

`sequence.txt`
```
CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC
```

```shell
$ ./bin/profile data.csv sequence.txt
Charlie
```

## Build

This project was built in C++ 20 with `make` as the build system.
Only tested on Fedora 38 with g++ 13.1.1

```shell
# clone the repo
$ git clone "https://github.com/edzdez/nifty-dna"
$ cd nifty-dna

# set up build dir
$ mkdir bin

# build
$ make bin/profile

# or alternatively, build and run in one step
$ make exec

# run tests
$ make tests # or just `make`, as tests are the default target
```

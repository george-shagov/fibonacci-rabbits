# Fibonacci Rabbits
> Both two and three state machines of Fibonacci Rabbits
> Implemented in C++

[![Build Status][travis-image]][travis-url]

Two state Fibonacci Rabbit's machine is well known and widely used at the moment. As to the three state I have found only a couple of number attempts to implement one, yet these were not successful. This project provides C++17 code base for both two and three state Fibonacci Rabbit's machines.

## Practical Usage

* Mathematical modeling and Educational purpose
* Finite/non-finite state machines (in Quantum Computing for instance)
* Probabilities, Combination and Permutation
* Random Number Generators
* Trading Prediction Algorithms
* Security and Cryptography

## Installation

Manual at the moment, tested only on Ubuntu

Linux:

```sh
make clean && make
```

## Usage

### Two state (Standard) Machine

Please find more info on [Fibonacci Rabbits](https://duckduckgo.com/?q=fibonacci+rabbit)

#### Prerequisites and Terminology

```
0 - Junior Pair of Rabbits
1 - Mature Pair of Rabbits
```


#### Algo

The algo is the simplicity itself:

* Junior Pair of Rabbits (0) breeds Mature Pair of Rabbits (1)
    * **0->1**
* Mature Pair of Rabbits (1) breeds Mature (1) (that is themselves) and Junior Pair (0)
    * **1->10** 
* _Rabbits never die_

#### Running and Testing

Into ./r-seq folder you will find one initial file for Rabbit Sequence: r-seq.001
```sh
$ cat ./r-seq/r-seq.001
1
```
After the code is compiled the simplest way in running a binary file is:

```sh
$ ./rabbit-seq ./r-seq/r-seq.001
```

And the output:
```sh
$ ./rabbit-seq ./r-seq/r-seq.001 

Growing ./r-seq/r-seq.001 to: ./r-seq/r-seq.002 ... Done.
```

And the result is:
```sh
$ find ./r-seq/ -type f -name "r-seq.*"         \
        -exec echo -n "{}:\"" \;                \
        -exec cat {} \;                         \
        -exec echo "\"" \;                      \
        | sort
./r-seq/r-seq.001:"1"
./r-seq/r-seq.002:"10"
```

For better convenience there is a script:
```sh
# growing one level only
$ ./grower.sh 1
Growing ./r-seq/r-seq.002 to: ./r-seq/r-seq.003 ... Done.

# growing four levels
$ ./grower.sh 4
Growing ./r-seq/r-seq.003 to: ./r-seq/r-seq.004 ... Done.
Growing ./r-seq/r-seq.004 to: ./r-seq/r-seq.005 ... Done.
Growing ./r-seq/r-seq.005 to: ./r-seq/r-seq.006 ... Done.
Growing ./r-seq/r-seq.006 to: ./r-seq/r-seq.007 ... Done.
```

Checking the result:
```sh
$ find ./r-seq/ -type f -name "r-seq.*"         \
          -exec echo -n "{}:\"" \;              \
          -exec cat {} \;                       \
          -exec echo "\"" \;                    \
          | sort
./r-seq/r-seq.001:"1"
./r-seq/r-seq.002:"10"
./r-seq/r-seq.003:"101"
./r-seq/r-seq.004:"10110"
./r-seq/r-seq.005:"10110101"
./r-seq/r-seq.006:"1011010110110"
./r-seq/r-seq.007:"101101011011010110101"
```
#### Phi Number

or **Golden Number** or **Golden Ration**

Please find more info on [Fibonacci Phi Number](https://duckduckgo.com/?q=fibonacci+phi)

There is an additional script to check **phi** Number:

```sh
./phi.sh
0 2/1
1 3/2
2 5/3
3 8/5
4 13/8
5 21/13
6 34/21
7 55/34
8 89/55
9 144/89
10 233/144
11 377/233
12 610/377
13 987/610
14 1597/987
15 2584/1597
```

```sh
./phi.sh | awk '{print $2 "-1.618033988749895"}' | bc -l
.38196601125010500000
-.11803398874989500000
.04863267791677166666
-.01803398874989500000
.00696601125010500000
-.00264937336527961539
.00101363029772404761
-.00038692992636558824
.00014782943192318181
-.00005646066000735956
.00002156680566055555
-.00000823767693362661
.00000314652861958885
-.00000120186464909837
.00000045907178686423
-.00000017534976976519
```

Forks like magic.

### Three state Machine

#### Terminology

```
0 - Juior Pair of Rabbits
1 - Mature Pair of Rabbits
2 - Deceased Pair of Rabbits
```

I have found two algos satisfying the task:

#### Algo A

* Junior Pair of Rabbits (0) breeds Mature Pair of Rabbits (1)
    * **0->1**
* Mature Pair of Rabbits (1) breeds Deceased Pair (2), Mature (1) and Junior Pair (0)
    * **1->210** 
* Deceased Pair disappears
    * **2->**

#### Algo B

* Junior Pair of Rabbits (0) breeds Mature Pair of Rabbits (1) and Junior Pair (0)
    * **0->10**
* Mature Pair of Rabbits (1) breeds Deceased Pair (2) and Junior Pair (0)
    * **1->20**
* Deceased Pair disappears
    * **2->**

#### Running and Testing

I am going to run the tests only for Algo A. As to Algo B, the result is identical, I do encourage you to make this exercise yourself.

In order to switch from two state to three state it will take some manual changes into the code and recompilation of cause.

Change:
```cpp
        /////////////////////////////////////////////////////////////////
        //! this is an Entry Point for Rabbit Generator
        //! two state machine
        processor<gens::st2::gen>(inFileStream, outFileStream);
        //! three state maehine algo A
        // processor<gens::st3::gen_a>(inFileStream, outFileStream);
        //! three state maehine algo B
        // processor<gens::st3::gen_b>(inFileStream, outFileStream);
```
to
```cpp

        /////////////////////////////////////////////////////////////////
        //! this is an Entry Point for Rabbit Generator
        //! two state machine
        // processor<gens::st2::gen>(inFileStream, outFileStream);
        //! three state machine algo A
        processor<gens::st3::gen_a>(inFileStream, outFileStream);
        //! three state machine algo B
        // processor<gens::st3::gen_b>(inFileStream, outFileStream);
```
for algo A

Recompiling:

```sh
$ make clean && make
```

Lets grow some rabbits first:

```sh
# removing from prev. experiments:
$ for f in `ls ./r-seq/r-seq.* | grep -v 001`; do rm -f $f; done

# growing
$ ./grower.sh 15
Growing ./r-seq/r-seq.001 to: ./r-seq/r-seq.002 ... Done.
Growing ./r-seq/r-seq.002 to: ./r-seq/r-seq.003 ... Done.
Growing ./r-seq/r-seq.003 to: ./r-seq/r-seq.004 ... Done.
Growing ./r-seq/r-seq.004 to: ./r-seq/r-seq.005 ... Done.
Growing ./r-seq/r-seq.005 to: ./r-seq/r-seq.006 ... Done.
Growing ./r-seq/r-seq.006 to: ./r-seq/r-seq.007 ... Done.
Growing ./r-seq/r-seq.007 to: ./r-seq/r-seq.008 ... Done.
Growing ./r-seq/r-seq.008 to: ./r-seq/r-seq.009 ... Done.
Growing ./r-seq/r-seq.009 to: ./r-seq/r-seq.010 ... Done.
Growing ./r-seq/r-seq.010 to: ./r-seq/r-seq.011 ... Done.
Growing ./r-seq/r-seq.011 to: ./r-seq/r-seq.012 ... Done.
Growing ./r-seq/r-seq.012 to: ./r-seq/r-seq.013 ... Done.
Growing ./r-seq/r-seq.013 to: ./r-seq/r-seq.014 ... Done.
Growing ./r-seq/r-seq.014 to: ./r-seq/r-seq.015 ... Done.
Growing ./r-seq/r-seq.015 to: ./r-seq/r-seq.016 ... Done.
```

Checking the result:

```sh
$ find ./r-seq/ -type f -name "r-seq.*"         \
            -exec echo -n "{}:\"" \;              \
            -exec cat {} \;                       \
            -exec echo "\"" \;                    \
            | sort | head -10
./r-seq/r-seq.001:"1"
./r-seq/r-seq.002:"210"
./r-seq/r-seq.003:"2101"
./r-seq/r-seq.004:"2101210"
./r-seq/r-seq.005:"21012102101"
./r-seq/r-seq.006:"210121021012101210"
./r-seq/r-seq.007:"21012102101210121021012102101"
./r-seq/r-seq.008:"21012102101210121021012102101210121021012101210"
./r-seq/r-seq.009:"2101210210121012102101210210121012102101210121021012102101210121021012102101"
./r-seq/r-seq.010:"210121021012101210210121021012101210210121012102101210210121012102101210210121012102101210121021012102101210121021012101210"

```

Looks fairly good.

Checking phi:

```sh
./phi.sh | awk '{print $2 "-1.618033988749895"}' | bc -l 
1.38196601125010500000
-.28470065541656166667
.13196601125010500000
-.04660541732132357143
.01832964761374136363
-.00692287763878388889
.00265566642251879310
-.00101271215415031915
.00038706388168394736
-.00014780988810638212
.00005646351141153266
-.00002156638964655280
.00000823773762899232
-.00000314651976451365
.00000120186594077712
```
looks good too.

## Release History

* 1.0
    * Work in progress

## Meta

Distributed under the GPLv3 license. See ``gpl-3.0`` for more information.

[https://github.com/george-shagov/fibonacci-rabbits](https://github.com/george-shagov/fibonacci-rabbits)

<!-- Markdown link & img dfn's -->
[travis-image]: https://img.shields.io/travis/dbader/node-datadog-metrics/master.svg?style=flat-square
[travis-url]: https://travis-ci.org/dbader/node-datadog-metrics
[wiki]: https://github.com/yourname/yourproject/wiki

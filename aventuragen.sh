# Ivan Andrei OJI 2025 11-12
#!/bin/bash

# INPUT

g++ aventuragen.cpp

# subtask 1

./a.out 5 10 1 > testsaventura/input_01.in #8
./a.out 5 10 1 > testsaventura/input_02.in #9

# subtask 2

./a.out 5 2000 2 > testsaventura/input_03.in #7
./a.out 5 2000 2 > testsaventura/input_04.in #6
./a.out 5 2000 2 > testsaventura/input_05.in #6

# subtask 3

./a.out 5 2000 3 > testsaventura/input_06.in #6
./a.out 5 2000 3 > testsaventura/input_07.in #6
./a.out 5 2000 3 > testsaventura/input_08.in #6
./a.out 5 2000 3 > testsaventura/input_09.in #5
./a.out 5 2000 3 > testsaventura/input_10.in #5
./a.out 5 2000 3 > testsaventura/input_11.in #5

# subtask 4

./a.out 5 500000 4 > testsaventura/input_12.in #6
./a.out 5 500000 4 > testsaventura/input_13.in #6
./a.out 5 500000 4 > testsaventura/input_14.in #6
./a.out 5 500000 4 > testsaventura/input_15.in #6
./a.out 5 500000 4 > testsaventura/input_16.in #7

rm a.out

# OUTPUT

g++ sursaaventura100.cpp

for i in $(seq -w 1 16); do
    ./a.out < testsaventura/input_$i.in > testsaventura/output_$i.out;
done

rm a.out

cd testsaventura/

if [[ -f teste.zip ]]; then
    rm teste.zip
fi

zip teste.zip *

cd ..
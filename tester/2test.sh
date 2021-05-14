make && ARG="1 2 5 3 6 4" &&  ./push_swap $ARG | ./checker $ARG
make && ARG="11 24 34 26 44 29 46 47 14 22 23 30 15 37 16 4" && ./push_swap $ARG | ./checker $ARG
make && ARG="36 39 -6 6 2 28 -5 33 10 41 19 42 1 22 25 21 17 3 24 -3 26 -2 -7 11 7 5 37 -8 15 -4 -1 27 23 13 32 12 16 30 29 35 38 14 9 40 4 8 31 18 20 0 34" && ./push_swap $ARG | ./checker $ARG
make && ARG="" &&  ./push_swap $ARG | ./checker $ARG

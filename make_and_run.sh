#/bin/bash
echo "making..."
g++ -lpthread -lwiringPi -std=c++14 *.cpp && echo "running:" && ./a.out | tee log.dat

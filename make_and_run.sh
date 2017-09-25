#/bin/bash
echo "making..."
g++ -lpthread -lwiringPi -std=c++14 *.cpp ../spi/spi.cpp && echo "running:" && ./a.out | tee log.dat

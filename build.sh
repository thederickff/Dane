#!/bin/sh

rm ./app.out
cd Dane
cmake .
make
cd ../Sandbox
cmake .
make
mv ./Sandbox ../app.out
cd ../
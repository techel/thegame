#!/bin/sh

g++ ./src/*.cpp -o ./bin/proc -I./src/ `pkg-config --libs sfml-all box2d` -std=c++14

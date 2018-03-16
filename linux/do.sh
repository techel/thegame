#!/bin/sh

g++ ./src/*.cpp -o ./bin/debug/proc -I./src/ `pkg-config --libs sfml-all box2d` -std=c++14

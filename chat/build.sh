#!/bin/sh

cc -std=gnu99 -O0 -g -o client client.c `pkg-config --libs libuv`

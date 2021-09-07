#!/bin/bash

source ../build.common

set -x

$CXX $CXX_OPTS reversed_example.cpp -o reversed_example


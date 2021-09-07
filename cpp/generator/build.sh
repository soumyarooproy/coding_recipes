#!/bin/bash

source ../build.common

set -x

$CXX $CXX_OPTS arange_example.cpp -o arange_example


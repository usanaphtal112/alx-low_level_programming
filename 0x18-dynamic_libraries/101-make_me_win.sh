#!/bin/bash
wget -p .. https://raw.githubusercontent.com/usanaphtal112/alx-low_level_programming/master/0x18-dynamic_libraries/libinjection_file.so
export LD_PRELOAD="$PWD/../libinjection_file.so"

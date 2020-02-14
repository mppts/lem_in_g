#!/bin/bash
#./generator --big-superposition > map2
cat map2 | grep 'required'
./lem-in < map2 | grep L |wc -l

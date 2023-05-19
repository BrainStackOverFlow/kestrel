#!/bin/bash

KESTREL=$1

gdb -ex "target remote localhost:1234" -ex "file $KESTREL"

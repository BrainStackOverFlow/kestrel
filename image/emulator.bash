#!/bin/bash

IMAGE=$1
MODE=$2

if [[ $MODE = "run" ]]; then
    qemu-system-x86_64 -M pc -m 2G -cdrom $IMAGE -boot d
elif [[ $MODE = "debug" ]]; then
    qemu-system-x86_64 -M pc -m 2G -cdrom $IMAGE -boot d -s -S
else
    exit 1
fi

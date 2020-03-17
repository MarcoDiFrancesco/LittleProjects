#!/bin/bash

if [[ "$(hostname)" == "bump" ]]; then
    echo "bump"
elif [[ "$(hostname)" == "vm" ]]; then
    echo "vm"
fi
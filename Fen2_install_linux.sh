#!/bin/bash
echo "Creating Installation Directory"
sudo mkdir /Fen2

#Get Download Directory:
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

#Move all files to /Fen2

sudo export PATH="/Fen2:$PATH"

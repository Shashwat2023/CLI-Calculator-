#!/bin/bash

echo "Compiling ABC..."

g++ cal.cpp -o abc

echo "Installing ABC..."

sudo install -Dm755 abc /usr/local/bin/abc

echo "Installation complete!"
echo "You can now run the program using: abc"
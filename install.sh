#!/bin/bash

echo "Compiling CLI Calculator..."

g++ cal.cpp -o clic

echo "Installing CLI Calculator..."

sudo install -Dm755 clic /usr/local/bin/clic

echo "Installation complete!"
echo "You can now run the program using: clic"
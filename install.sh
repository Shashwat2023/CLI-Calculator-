#!/bin/bash

PROGRAM_NAME="clic"
INSTALL_PATH="/usr/local/bin/$PROGRAM_NAME"

echo "Compiling CLI Calculator..."

g++ cal.cpp -o "$PROGRAM_NAME"

if [ $? -ne 0 ]; then
echo "Compilation failed!"
exit 1
fi

if [ -f "$INSTALL_PATH" ]; then
echo "Existing installation found."
echo "Updating CLI Calculator..."
else
echo "Installing CLI Calculator..."
fi

sudo install -Dm755 "$PROGRAM_NAME" "$INSTALL_PATH"

echo "Installation/update complete!"
echo "You can now run the program using: $PROGRAM_NAME"

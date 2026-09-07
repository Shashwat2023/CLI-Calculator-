#!/bin/bash

PROGRAM_NAME="clic"
INSTALL_PATH="/usr/local/bin/$PROGRAM_NAME"

if [ -f "$INSTALL_PATH" ]; then
echo "Uninstalling CLI Calculator..."

```
sudo rm "$INSTALL_PATH"

echo "CLI Calculator has been successfully uninstalled."
```

else
echo "CLI Calculator is not installed."
fi

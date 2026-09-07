# CLI Calculator

A simple command-line calculator written in C++.

CLI Calculator evaluates mathematical expressions directly from the terminal and supports basic arithmetic operations, operator precedence, and bracketed expressions.

## Features

* Addition (`+`)
* Subtraction (`-`)
* Multiplication (`*`)
* Division (`/`)
* Operator precedence
* Supports brackets:

  * Parentheses `()`
  * Square brackets `[]`
  * Curly brackets `{}`
* Division-by-zero detection
* Continuous calculator mode
* Linux installation script
* Uses traditional C++ arrays and strings for expression parsing

## Supported Expressions

Examples:

```text
24-2
2+3*4
2+(24-2)
10/(8-3)
2*{4+3}
```

## Operator Precedence

The calculator follows standard arithmetic precedence:

1. Bracket expressions
2. Multiplication and Division
3. Addition and Subtraction

For example:

```text
2+3*4
```

Produces:

```text
14
```

because multiplication is evaluated before addition.

## Building Manually

Make sure you have `g++` installed.

Compile the program using:

```bash
g++ cal.cpp -o clic
```

Run it from the current directory:

```bash
./clic
```

## Installation

The project includes an `install.sh` script for installing the calculator system-wide.

First, make the script executable:

```bash
chmod +x install.sh
```

Then run:

```bash
./install.sh
```

After installation, the calculator can be launched from anywhere using:

```bash
clic
```

## Uninstallation

The project also includes an `uninstall.sh` script.

Make it executable:

```bash
chmod +x uninstall.sh
```

Then run:

```bash
./uninstall.sh
```

## Usage

Start the calculator:

```bash
clic
```

You will see:

```text
CLI Calculator says
Welcome to the terminal calculator!!
```

Enter a mathematical expression:

```text
2+(24-2)
```

Output:

```text
Result: 24
```

The calculator continues running and accepts new expressions until the program is manually terminated.

## Project Structure

```text
CLI-Calculator/
│
├── cal.cpp
├── install.sh
├── uninstall.sh
└── README.md
```

## Requirements

* Linux
* Bash
* GNU C++ Compiler (`g++`)

## Installation Location

The executable is installed at:

```text
/usr/local/bin/clic
```

This allows the program to be executed globally from any terminal.

## Author

Shashwat Tripathi

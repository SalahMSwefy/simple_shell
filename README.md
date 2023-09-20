# 0x16. C - Simple Shell

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [Installation](#installation)

## Description
A simple Unix shell implementation written in C as part of the 0x16 - C - Simple Shell project. This shell provides basic command execution and features similar to popular Unix shells like `bash` or `sh`.

## Features
- Command execution
- Simple built-in commands (e.g., `cd`, `exit`)
- Path resolution for external commands
- Background process support (e.g., `command &`)
- I/O redirection (e.g., `command > file.txt`)
- Pipelines (e.g., `command1 | command2`)
- Error handling and signal handling

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/0x16-c-simple-shell.git
2. Compile the shell:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
3. Run the shell:
   ```bash
   ./hsh
4. Start using the shell. Example commands:
   ```bash
   $ ls -l
   $ echo "Hello, World!"
   $ ls | wc -l
   $ ./custom_script.sh

## Installation
   No additional installation is required beyond compiling the source code as mentioned in the Usage section.

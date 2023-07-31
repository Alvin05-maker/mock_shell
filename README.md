# Simple Shell Project
Simple Shell is a lightweight and user-friendly C-based shell implementation for Unix-like systems.It allows users to enter commands and execute them in a Unix-like environment. It provides a basic interface for interacting with the operating system, running various commands, and performing tasks efficiently. This project has been developed under stringent measures for memory management and good practices

## How to Use
To use the program, follow the following steps:
- Clone the repo to your local machine:
    - `git clone  https://github.com/obimbasmart/simple_shell.git`
- Compile the C files in the simple_shell directory to generate an executable:
    - `gcc -Wall -Wextra - Werror -pedantic -std=gnu89 *.c -o hsh`
- Run the executable:
    - `./hsh`

Once the interpreter is running, you can type commands and press Enter to execute them. The interpreter will process the command and perform the appropriate actions

Here are some list of supported commands amongst others:
- `ls` - List files and directories in the current directory
- `cd` - Change the current working directory to the specified directory
- `mkdir` : Create a new directory with the given name. rm

## Files
- `mainc` - This is the entry point of the program
- `main.h` - Header file for the project

## Learning
While building SimpleShell, We had the opportunity to learn and apply various technologies and concepts, including:
- Process management
- Memory management
- System calls
- Signals and interrupt

## Authors
- Alvin Agaromba: https://github.com/Alvin05-maker
- Obimba Smart: https://github.com/obimbasmart
- 
## Contributing
Contributions are welcome to improve the project. If you find any issues or have ideas for enhancements, please open an issue or submit a pull request


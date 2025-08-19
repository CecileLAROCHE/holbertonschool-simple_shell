# README of the project Simple Shell

![Project Status](https://img.shields.io/badge/status-development-yellow)  ![License: Edu](https://img.shields.io/badge/license-Educational-lightgrey)  ![buil with](https://img.shields.io/badge/built_with-❤️‍🔥-df0000)

<p align="center"><img src="https://i.makeagif.com/media/10-15-2019/mpvsbP.gif" alt="Ghost in the Shell (1995)" width="400"><!-- markdownlint-disable-line MD033 --></p>

## 📖 Description

Simple Shell is a C implementation of a basic command interpreter, inspired by the Unix shell.
The project aims to teach and practice:
* the inner workings of a command interpreter,
* process creation and management (`fork`, `execve`, `wait`, etc.),
* the use of environment variables and the `$PATH`,
* input/output and stream management,
* UNIX return code conventions.


The program allows you to:

* Display a prompt and wait for a user command.
* Execute programs located in the current directory or in the `$PATH`.
* Manage simple commands with arguments.
* Provide a compliant exit code.

This project was developed as part of the Holberton School peer programming curriculum, to deepen your understanding of systems programming and collaboration on a low-level project.



## 🧭 Index

1 - [⚙️ Cloning and Compilation](#️-cloning-and-compilation)\
2 - [📚 Files in Repository](#-files-in-repository)\
3 - [📄 Man Page](#-man-page)\
4 - [🗺️ Flowchart](#%EF%B8%8F-flowchart)\
5 - [🧪 Tests and outputs](#-tests-and-output)\
6 - [📁 Project Structure](#-project-structure)\
7 - [👥 Authors](#-authors)\
8 - [📜 License](#-license)

## ⚙️ Cloning and Compilation

### ✅ Prerequisites

**GCC** installed on your system.\
**Ubuntu 20.04 LTS** (or equivalent).

### 📥 Clone and execution

| Task |Command|
|--------------------------------------------|-------------------------------------------------------|
| `Clone repo` | `git clone https://github.com/CecileLAROCHE/holbertonschool-simple_shell.git` |
| `Compile` | `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh` |
| `Run shell:` | `./hsh` |

## 📚 Files in Repository

### 🖥️ Source Code Files

| File                   | Description                                                                                         |
| ---------------------- | --------------------------------------------------------------------------------------------------- |
| `shell.h`              | Header file containing function prototypes, macros, and struct definitions used across the project. |
| `main.c`               | Entry point of the shell, initializes the program and starts the main loop.                         |
| `read_line.c`          | Handles user input by reading a line from standard input.                                           |
| `process_command.c`    | Parses the input line into tokens and prepares the command for execution.                           |
| `print_env.c`          | Prints the current environment variables.                                                           |
| `execute_command.c`    | Handles the execution of built-in and external commands.                                            |
| `_getenv.c`            | Custom implementation of `getenv`, retrieves environment variables.                                 |
| `_find_path_command.c` | Finds the absolute path of a command by searching in the `PATH` environment variable.               |

### 📑 Documentation Files

| File                 | Description                                                       |
| -------------------- | ----------------------------------------------------------------- |
| `man_1_simple_shell` | Manual page describing usage, options, and behavior of the shell. |
| `README.md`          | Main project documentation (this file).                           |
| `AUTHORS`            | List of project contributors.                                     |


## 📋 Man page

## 🗺️ Flowchart

![Flowchart](Picture/Flowchart.png)


## 🧪 Tests and Outputs

#### test terminal :
![screenshot](Picture/terminal.png)

#### test interactiv mod :

![screenshot](Picture/ls_-l.png)

![screenshot](Picture/ls.png)

![screenshot](Picture/cat_print_env.png)

#### test uninteractiv mod :
![screenshot](Picture/uninteractive_mod_echo.png)
![screenshot](Picture/uninteractive_mod_error.png)

## 📁 Project Structure

## 📁 Project Structure

├── AUTHORS                 # List of contributors\
├── README.md               # Main project documentation\
├── man_1_simple_shell      # Manual page for the shell\
├── shell.h                 # Header file with prototypes and macros\
├── main.c                  # Entry point, initializes the shell\
├── read_line.c             # Reads user input from stdin\
├── process_command.c       # Parses and tokenizes the command line\
├── print_env.c             # Prints environment variables\
├── execute_command.c       # Executes built-in and external commands\
├── _getenv.c               # Custom getenv implementation\
└── _find_path_command.c    # Locates command in PATH directories\

## 👥 Authors

This project was collaboratively developed by Holberton students as a peer programming exercise.\
\
**Esteban LEVY** [GitHub](https://github.com/ST-GuY)\
**Thomas SORLI** [GitHub](https://github.com/Pendarium)\
**Cécile LAROCHE** [GitHub](https://github.com/CecileLAROCHE)

## 📜 License

This project is for educational purposes only as part of Holberton School.

# DevLog – Task Management CLI Tool in C

DevLog is a lightweight Command Line Interface (CLI) task management tool built using the C programming language.  
It allows developers to manage daily tasks directly from the terminal with persistent file storage.

This project is designed to strengthen core C programming concepts and system-level thinking.

---

## Features

- Initialize task
- Add new tasks
- List all tasks
- Mark tasks as completed
- Delete tasks
- Clear all tasks
- Persistent storage using file handling

---

## Available Commands

```bash
./devlog add "Complete pointer revision"
./devlog list
./devlog done 2
./devlog delete 3
./devlog clear
```
---

## Core C Concepts Used
This project demonstrates strong understanding of:

- Variables and Data Types
- Pointers
- Arrays and Strings
- Dynamic Memory Allocation (malloc,free)
- File Handling (fopen, fprintf, fscanf, fgets)
- Command Line Arguments (argc, argv)
- Header Files and Modular Programming

---

## Compilation & Execution
- Compile
```bash
gcc main.c task.c file.c -o devlog
```
- Run
```bash
./devlog add "Learn C deeply"
./devlog list
./devlog done 1
./devlog delete 2
```
---

## Learning Outcomes

After completing this project, you will understand:

- How CLI tools are structured
- How to manage persistent data in C
- Memory management in real-world scenarios
- Modular programming practices
- File parsing and structured storage
# get_next_line

Welcome to the `get_next_line` project! In this project, you'll be crafting a function that allows you to read a text file or input from the standard input one line at a time. 

This function becomes a versatile tool for your C programming projects, handling repeated calls to efficiently retrieve lines from a file descriptor.

The function returns the line read, including the terminating `\n` character, except at the end of the file.

## Project Overview

### Key Objectives

- Implement `get_next_line` to read a text file or standard input line by line.
- Ensure that repeated calls (e.g., using a loop) retrieve subsequent lines.
- Return the line read, including the terminating `\n` character, except at the end of the file.
- Handle cases where there is nothing else to read or when an error occurs.

### Why `get_next_line`?

`get_next_line` is more than just a function; it's a gateway to seamless text file processing in your C programs. It enhances your ability to efficiently read and manipulate text data, making it a crucial tool for projects involving file I/O. The function's versatility is evident as it smoothly adapts to reading from both files and standard input.

## Getting Started

### Prerequisites

- Basic knowledge of file I/O in C.
- A code editor of your choice.

### Usage

1. Clone the repository in your project folder:

    ```bash
    git clone https://github.com/tiziaco/get_next_line.git
    ```

2. Integrate the `get_next_line` header into your project:

    ```c
    #include "get_next_line.h"
    ```

3. Utilize the function within loops for repeated line retrieval:

    ```c
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        // Process the line as needed
        // ...
        free(line); // Remember to free the allocated memory
    }
    ```
---
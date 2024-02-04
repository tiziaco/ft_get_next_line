# get_next_line

Welcome to the `get_next_line` project! In this project, you'll be crafting a function that allows you to read a text file or input from the standard input one line at a time. 

This function becomes a versatile tool for your C programming projects, handling repeated calls to efficiently retrieve lines from a file descriptor.

The function returns the line read, including the terminating `\n` character, except at the end of the file.

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

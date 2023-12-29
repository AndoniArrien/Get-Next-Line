# 02-get_next_line

## Overview

The **Get Next Line** project challenges you to implement a function, `get_next_line`, that reads a line from a file descriptor, allowing you to read a text file or standard input one line at a time.

## Mandatory Part

### Function: `get_next_line`

- **Prototype:** `char *get_next_line(int fd);`
- **Turn in Files:** get_next_line.c, get_next_line_utils.c, get_next_line.h
- **Parameters:** `fd` - The file descriptor to read from
- **Return Value:**
  - Read line: Correct behavior
  - `NULL`: Nothing else to read or an error occurred
- **External Functions:** read, malloc, free

### Requirements

- Repeated calls to `get_next_line` should allow reading a text file one line at a time.
- The function should return the line that was read or `NULL` if there is nothing else to read or if an error occurred.
- Works when reading a file or from standard input.
- The returned line should include the terminating `\n` character, except at the end of the file.
- Header file `get_next_line.h` must contain the prototype of the `get_next_line` function.
- Helper functions should be added in `get_next_line_utils.c`.

### Buffer Size Configuration

- Compiler Call Option: `-D BUFFER_SIZE=n` (define the buffer size for `read()`).
- The buffer size value can be modified for testing.
- Consider potential undefined behavior in specific cases.

### Forbidden Actions

- Do not use your `libft` in this project.
- `lseek()` is forbidden.
- Global variables are forbidden.

## Bonus Part

### Bonus Requirements

- Develop `get_next_line` using only one static variable.
- Manage multiple file descriptors simultaneously.
- Append `_bonus.[c|h]` suffix to bonus part files.
- Additional Files:
  - `get_next_line_bonus.c`
  - `get_next_line_bonus.h`
  - `get_next_line_utils_bonus.c`

<div align="center">
<picture>
  <img alt="Libft with bonus" src="https://github.com/ayogun/42-project-badges/blob/main/badges/libftm.png" />
</picture>
  
# Libft static C library

</div>

The Libft project is an essential part of the [Hive Helsinki (42 School Network)](https://www.hive.fi/en/curriculum) core curriculum that involves recreating a custom C library from scratch. It focuses on implementing fundamental functions from the standard C library and not only, such as memory manipulation, string operations, and linked list management.  

The project helps develop a deep understanding of low-level programming, memory management, and efficient coding practices, forming a strong foundation for future projects in systems programming and algorithm optimization.  

> [!NOTE]
> I actively reuse this library for various other projects, and the current version of this repository no longer meets the original requirements of the subject. If, for some reason, you're looking for the version of this repository that matches the original requirements, you can check it [here](https://github.com/ipersids/hive-core-libft/tree/9be91f2f3370d504b02c8e61e1d22d1df8ac8ef8).   

## Features  
This section gives a detailed overview of the libft library functions, organized into expandable categories. Click on each category below to open and view the table of functions with their descriptions:

<details>
<summary><b>Memory Management Functions</b></summary>  
Functions related to memory allocation and manipulation.  

| Function        | Description                                           |
| :--------------: | ----------------------------------------------------- |
| `ft_memchr`      | Locates the first occurrence of a byte in memory.    |
| `ft_memcmp`      | Compares the first n bytes of two memory areas.      |
| `ft_memcpy`      | Copies n bytes from one memory area to another.      |
| `ft_memmove`     | Moves n bytes from one memory area to another.      |
| `ft_memset`      | Fills the first n bytes of the memory area with a constant byte. |

</details>

<details>
<summary><b>Memory Allocation Functions</b></summary>  
Functions related to memory allocation and manipulation.  

| Function        | Description                                           |
| :--------------: | ----------------------------------------------------- |
| `ft_calloc`      | Allocates memory for an array and initializes it to zero. |
| `ft_realloc`     | Reallocates the given area of memory.    |

</details>

<details>
<summary><b>String Manipulation Functions</b></summary>  
Functions for handling and processing strings.  

| Function        | Description                                           |
| :--------------: | ----------------------------------------------------- |
| `ft_strdup`      | Duplicates a string.                                |
| `ft_strchr`      | Locates the first occurrence of a character in a string. |
| `ft_strlcat`     | Appends a string to another with size limit.        |
| `ft_strlcpy`     | Copies a string with size limit.                    |
| `ft_strlen`      | Returns the length of a string.                     |
| `ft_strncmp`     | Compares n bytes of two strings.                    |
| `ft_strcmp`     | Compares two strings.                    |
| `ft_strnstr`     | Finds the first occurrence of a substring in a string. |
| `ft_strrchr`     | Locates the last occurrence of a character in a string. |
| `ft_split`       | Splits a string into an array of substrings.        |
| `ft_substr`      | Extracts a substring from a string.                 |
| `ft_strjoin`     | Concatenates two strings into a new string.         |

</details>
<details>
<summary><b>Number Manipulation Functions</b></summary>  
Functions for handling and processing strings.  

| Function        | Description                                           |
| :--------------: | ----------------------------------------------------- |
| `ft_atoi`        | Converts a string to an integer.                     |
| `ft_atol`        | Converts a string to a long integer.                 |
| `ft_itoa`        | Converts an integer to a string.                    |
| `ft_strtod`      | Converts a string to a double-precision floating-point number. |  

</details>

<details>
<summary><b>Character Classification Functions</b></summary>  
Functions for character testing and conversion.  

| Function        | Description                                          |
| :-------------: | ---------------------------------------------------- |
| `ft_isalnum`     | Checks if a character is alphanumeric.              |
| `ft_isalpha`     | Checks if a character is alphabetic.                |
| `ft_isascii`     | Checks if a character is an ASCII character.        |
| `ft_isdigit`     | Checks if a character is a digit.                   |
| `ft_isprint`     | Checks if a character is printable.                 |
| `ft_isspace`     | Checks if a character is a standard white-space character. |
| `ft_toupper`     | Converts a character to uppercase.                  |
| `ft_tolower`     | Converts a character to lowercase.                  |

</details>

<details>
<summary><b>Writing Formatted Text (ft_prinf Features)</b></summary>  
Functions for printing formatted data to stdout and writing information to file descriptor.    

| Function         | Description                                          |
| :--------------: | ---------------------------------------------------- |
| `ft_printf`      | Formats text and writes it to standard output.       |
| `ft_putchar_fd`  | Writes a character to a file descriptor.             |
| `ft_puthex_fd`   | Writes a hexadecimal number to a file descriptor.    |
| `ft_putnbr_fd`   | Writes an integer to a file descriptor.              |
| `ft_putptr_fd`   | Writes a pointer to a file descriptor.               |
| `ft_putstr_fd`   | Writes a string to a file descriptor.                |
| `ft_putunmb_fd`  | Writes an unsigned integer to a file descriptor.    |

</details>

<details> 
<summary><b>Reading from file descriptor (get_next_line)</b></summary>  
Function reads the content of the file descriptor one line at a time.  

| Function         | Description                                          |
| :--------------: | ---------------------------------------------------- |
| `get_next_line`  |  Get the next line from the file descriptor.         |

</details>

<details> 
<summary><b>Mathematical functions</b></summary>  
Function reads the content of the file descriptor one line at a time.  

| Function         | Description                                          |
| :--------------: | ---------------------------------------------------- |
|     `ft_min`     |  Returns the minimum of two integers.                |
|     `ft_max`     |  Returns the maximum of two integers.                |
|     `ft_rand`    |  Returns the pseudo-random unsigned integer value.   |
|     `ft_abc`     |  Returns the absolute value of the input integer.    |
| `ft_binary_exponentiation` | Computes the power of a number using exponentiation by squaring. |  

</details>

## Project Structure  
Below is an overview of the project's directory structure. The project is currently ongoing, and this information will be updated as development progresses.   

```css
hive-core-libft/
│
├── include/                  # Header files
│   └── libft.h
│
├── src/                      # Source files
│   ├── src/char/
│   │   └── *.c
│   ├── src/ft-printf/
│   │   └── *.c
│   ├── src/get-next-line/
│   │   └── *.c
│   ├── src/linked-list/
│   │   └── *.c
│   ├── src/math/
│   │   └── *.c
│   ├── src/mem-allocation/
│   │   └── *.c
│   ├── src/memory/
│   │   └── *.c
│   ├── src/number/
│   │   └── *.c
│   └── src/string/
│       └── *.c
│
├── Makefile                  # Building project tool
├── README.md
└── LICENSE

```

## Where to start  
### Installation  
To use this library in your project, follow these steps:  
1. **Clone the Repository.**  
  - To clone the version of the code that was originally used for submission, use the submission tag:  
```sh
git clone --branch submission --single-branch --depth 1 git@github.com:ipersids/hive-core-libft.git
cd hive-core-libft
```
  - To clone the most recent version of the library (the latest commit), use:  
```sh
git clone git@github.com:ipersids/hive-core-libft.git
cd hive-core-libft
```
2. **Build the Library.**    
Use the Makefile to compile the source files and create the static library.   
```sh
make all
```
Commands:   
- `make all` will build a static library.  
- `make clean` will remove all '.o' files from the directory.  
- `make fclean` will remove all '.o' and executable files.  
- `make re` will trigger the `fclean` command and rebuild the library.

3. **Include the Header File** in your source code.
```c
#include "libft.h"
```
4. **Include the Library in the Project.**  
Link the static library in your project's build process to use the functions as described in the header file. For example, if using `clang`, you can compile and link your project with the library as follows:
```sh
clang -o program_name program_name.c -I<lib_path/include> -L<lib_path> -lft

```  
Flags and arguments:    
- `-o program_name` is the name of the output file.  
- `program_name.c` is the name of the source file to be compiled.   
- `-I<lib_path/include>` tells the compiler to look in the specified directory for library header file.   
- `-L<lib_path>` tells the linker to look in the specified directory for any libraries specified with the `-l` option.  
- `-lft` tells the linker to link the program with the `libft.a` library (the lib prefix and the `.a` extension are automatically added by the linker).  

Recommended additional flags:  
- `-Wall -Wextra -Werror` to enable warning messages and to tell the compiler.
______________
Developed by **Julia Persidskaia**.   
[LinkedIn](https://www.linkedin.com/in/iuliia-persidskaia/)

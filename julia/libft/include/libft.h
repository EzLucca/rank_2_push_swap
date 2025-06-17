/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:28:38 by ipersids          #+#    #+#             */
/*   Updated: 2025/04/22 13:54:37 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>		// malloc(), free(), NULL macros, RAND_MAX
# include <unistd.h>		// read(), sysconf(_SC_OPEN_MAX) = 1024
# include <limits.h>		// Limits to manage BUFFER_SIZE
# include <stdarg.h>		// va_list, va_start, and va_end

/* ------------------- General Support Struct and Macros ------------------- */

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

/* ----------------------------- Get Next Line ----------------------------- */

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

/**
 * BUFFER_SIZE Memory Guard
 *
 * This guard checks the value of BUFFER_SIZE set at compile time 
 * to prevent errors related to buffer allocation.
 *
 * - If BUFFER_SIZE is <= 0, it undefines the macro, preventing 
 *   `get_next_line` from attempting to allocate an invalid (negative) 
 *   buffer size, which would disrupt program execution.
 * 
 * - If BUFFER_SIZE (+1) exceeds UINT_MAX / OPEN_MAX, it also undefines 
 *   the macro to avoid huge memory allocation requests.
 * 
 * - If BUFFER_SIZE is undefined after these checks, it is defined with 
 *   a default value of 100, simulating `getline` behavior.
 */
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE <= 0 || BUFFER_SIZE >= UINT_MAX / OPEN_MAX
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 100
#  endif
# else
#  define BUFFER_SIZE 100
# endif

char		*get_next_line(int fd, t_bool reset);

/* ------------------------- ft_printf() Functions ------------------------- */

# define SPECIFIERS "cspdiuxX%"

int			ft_printf(const char *format, ...);

size_t		ft_putunbr_fd(unsigned int n, int fd);
size_t		ft_puthex_fd(unsigned int n, int fd, short int is_uppercase);
size_t		ft_putptr_fd(unsigned long long n, int fd);
size_t		ft_putchar_fd(char c, int fd);
size_t		ft_putnbr_fd(int n, int fd);
size_t		ft_putstr_fd(const char *s, int fd);

/* ---------------------- Memory Management Functions ---------------------- */

/*
 * NOTE: If passing a null pointer to any memory-related function
 		 results in a segmentation fault, that's expected behavior, 
 * 		 because function tries to access an invalid memory location,
 * 		 causing the program to crash.
 * 		 This is the way.
*/

void		*ft_memcpy(void *destination, const void *source, size_t num);
void		*ft_memset(void *ptr, int value, size_t num);
void		*ft_memchr(const void *ptr, int value, size_t num);
void		*ft_memmove(void *dest, const void *src, size_t num);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

/* ---------------------- Memory Allocation Functions ---------------------- */

void		*ft_calloc(size_t num, size_t size);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/* --------------------- String Manipulation Functions --------------------- */

size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strchr(const char *str, int ch);
char		*ft_strrchr(const char *str, int ch);
char		*ft_strnstr(const char *big, const char *little, size_t len);

// using memory allocation:

char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *str);

/* --------------------- Number Manipulation Functions --------------------- */

# define MAX_EXPONENT 511	// Largest possible base 10 exponent.

int			ft_atoi(const char *str);
long int	ft_atol(const char *str);
double		ft_strtod(const char *str, char **endptr);

// using memory allocation:

char		*ft_itoa(int n);

/* ------------------- Character Classification Functions ------------------ */

int			ft_isalpha(int ch);
int			ft_isdigit(int ch);
int			ft_isalnum(int ch);
int			ft_isascii(int ch);
int			ft_isprint(int ch);
int			ft_toupper(int ch);
int			ft_tolower(int ch);
int			ft_isspace(int ch);

/* ------------------------ Mathematical Functions ------------------------- */

int			ft_min(int n1, int n2);
int			ft_max(int n1, int n2);
int			ft_rand(void);
int			ft_abc(int num);
double		ft_binary_exponentiation(double base, int exponent);

#endif

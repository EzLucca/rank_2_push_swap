/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:16:57 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:47:08 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_word_counter(char const *s, char c);
static size_t	ft_split_word_len(char const *s, char c);
static char		**ft_split_free_array(char **arr, size_t i);

/**
 * @brief Splits a string using a character as a delimiter.
 * 
 * What the function does:
 * 
 * 1. Checks if the string `s` is NULL. If it is, the function returns NULL.
 * 
 * 2. Counts the number of words separated by the delimiter in the string.
 * 
 * 3. Allocates memory for an array of strings, including a null-terminating
 *    pointer at the end. If memory allocation fails, it returns NULL.
 * 
 * 4. Skips delimiter characters (`c`) to find the start of each word and 
 *    calculates the length of the word. Allocates memory for the word 
 *    (frees everything if allocation fails) and copies the word into the 
 *    newly allocated string.
 * 
 * 5. Repeats step 4 until all words are allocated.
 * 
 * 6. Sets the last pointer in the array to NULL to terminate the array of str 
 *    and returns a pointer to the array.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return char**  An allocated array of strings resulting from the split.
 *                 NULL if allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	size_t	size;
	size_t	len;
	size_t	i;
	char	**arr;

	if (!s)
		return (0);
	size = ft_split_word_counter(s, c);
	arr = (char **) malloc((size + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	while (i < size)
	{
		while (*s == c && *s != '\0')
			s++;
		len = ft_split_word_len(s, c);
		arr[i] = (char *) ft_calloc((len + 1), sizeof(char));
		if (!arr[i])
			return (ft_split_free_array(arr, i));
		ft_memcpy(arr[i++], s, len);
		s = ft_strchr(s, c);
	}
	arr[size] = 0;
	return (arr);
}

// ---------------------------------------------- //
// -------------  SUPPORT FUNCTIONS ------------- //
// ---------------------------------------------- //

/**
 * @brief Counts the number of words separated by a delimiter.
 * 
 * @param s The string to be checked.
 * @param c The delimiter character.
 * @return size_t The number of words separated by the delimiter `c` 
 *                in the string `s`.
 */
static size_t	ft_split_word_counter(char const *s, char c)
{
	size_t		i;
	size_t		cnt;
	short int	is_new_word;

	i = 0;
	cnt = 0;
	is_new_word = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			is_new_word = 1;
			continue ;
		}
		if (is_new_word == 1)
		{
			cnt++;
			is_new_word = 0;
		}
		i++;
	}
	return (cnt);
}

/**
 * @brief Counts the length of a word in the given string 
 *        until the `c` character.
 * 
 * @param s The string to be measured.
 * @param c The delimiter character.
 * @return size_t The length of the word.
 */

static size_t	ft_split_word_len(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] != c && s[cnt] != '\0')
		cnt++;
	return (cnt);
}

/**
 * @brief Frees the memory allocated for an array of strings.
 * 
 * @param arr The array of strings to be freed.
 * @param i The number of elements in the array.
 * @return void This function does not return a value.
 */
static char	**ft_split_free_array(char **arr, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(arr[j]);
	free(arr);
	return (0);
}

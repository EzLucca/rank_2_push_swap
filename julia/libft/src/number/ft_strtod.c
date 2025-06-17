/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:02:45 by ipersids          #+#    #+#             */
/*   Updated: 2025/04/22 13:50:54 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_mantissa(const char **str, int *point_pos, int *mant_size);
static double	get_exponent(const char **str, int *point_pos, int *mant_size);
static int		parse_str_exponent(const char **str);
static void		skip_spaces(const char **str);

/**
 * @brief Converts a string to a double-precision floating-point number.
 * 
 * It skips leading whitespace, handles an optional sign, and processes 
 * the mantissa and exponent parts of the number. If the input string 
 * is invalid or does not contain a valid number, the function returns 0.0.
 * 
 * @note This version DO NOT handle `inf` (`INF`) 
 * 		 or `nan` (`NAN`) key words passes as string.
 * 
 * @param str Pointer to the input string to be converted.
 * @param endptr Pointer to a pointer to the character where parsing stopped.
 *               If not NULL, this pointer is updated to point to the first
 *               character after the number.
 * @return The converted double-precision floating-point number.
 * 
*/
double	ft_strtod(const char *str, char **endptr)
{
	int			sign;
	int			point_pos;
	int			mant_size;
	double		res;
	const char	*s = str;

	if (endptr != NULL)
		*endptr = (char *) s;
	skip_spaces(&s);
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	point_pos = -1;
	mant_size = 0;
	res = get_mantissa(&s, &point_pos, &mant_size);
	if (mant_size == 0)
		return (0.0);
	res = res * get_exponent(&s, &point_pos, &mant_size);
	if (endptr != NULL)
		*endptr = (char *)s;
	return (sign * res);
}

// ---------------------------------------------- //
// -------------  SUPPORT FUNCTIONS ------------- //
// ---------------------------------------------- //

/**
 * @brief Parses the mantissa part of the number.
 * 
 * This helper function extracts the mantissa (the significant digits) 
 * from the input string. The mantissa is split into two parts
 * (fract1 and fract2) to handle precision limitations.
 * 
 * @param str Pointer to the input string being parsed.
 * @param point_pos Pointer to `int` to store the position of the decimal point.
 * @param mant_size Pointer to `int` to store the size of the mantissa.
 * @return The parsed mantissa as a double.
 * 
*/
static double	get_mantissa(const char **str, int *point_pos, int *mant_size)
{
	int	fract1;
	int	fract2;

	fract1 = 0;
	fract2 = 0;
	while (ft_isdigit(**str) || **str == '.')
	{
		if (**str == '.')
		{
			if (*point_pos >= 0)
				break ;
			*point_pos = *mant_size;
			(*str) += 1;
			continue ;
		}
		if (*mant_size < 9)
			fract1 = fract1 * 10 + (**str - '0');
		else if (*mant_size < 18)
			fract2 = fract2 * 10 + (**str - '0');
		(*mant_size) += 1;
		(*str) += 1;
	}
	if (fract2 != 0)
		return ((fract1 * 1.0e9) + fract2);
	return (fract1);
}

/**
 * @brief Parses the exponent part of the number.
 * 
 * This helper function calculates the exponent value based on the position
 * of the decimal point and the size of the mantissa. It also processes the
 * optional scientific notation exponent (e.g., "e10").
 * 
 * @param str Pointer to the input string being parsed.
 * @param point_pos Pointer to the position of the decimal point.
 * @param mant_size Pointer to the size of the mantissa.
 * @return The calculated exponent as a double.
 * 
*/
static double	get_exponent(const char **str, int *point_pos, int *mant_size)
{
	int	frac_exp;

	if (*point_pos < 0)
		*point_pos = *mant_size;
	frac_exp = 0;
	if (*mant_size > 18)
	{
		frac_exp = *point_pos - 18;
		*mant_size = 18;
	}
	else
		frac_exp = *point_pos - *mant_size;
	frac_exp = frac_exp + parse_str_exponent(str);
	if (frac_exp > MAX_EXPONENT)
		frac_exp = MAX_EXPONENT;
	return (ft_binary_exponentiation(10, frac_exp));
}

/**
 * @brief Parses the scientific notation exponent from the string.
 * 
 * @param str Pointer to the input string being parsed.
 * @return The parsed exponent as an integer.
 * 
*/
static int	parse_str_exponent(const char **str)
{
	int	exp;
	int	sign;

	exp = 0;
	sign = 1;
	if (**str == 'E' || **str == 'e')
	{
		(*str) += 1;
		if (**str == '-' || **str == '+')
		{
			if (**str == '-')
				sign = -1;
			(*str) += 1;
		}
		while (ft_isdigit(**str))
		{
			exp = exp * 10 + (**str - '0');
			(*str) += 1;
		}
	}
	return (sign * exp);
}

static void	skip_spaces(const char **str)
{
	while (ft_isspace(**str))
		(*str) += 1;
}

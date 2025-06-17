/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:35:41 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/06 13:09:39 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putptr_fd(unsigned long long n, int fd)
{
	size_t	len;
	char	*base;

	if (!n)
		return (write(1, "(nil)", 5));
	base = "0123456789abcdef";
	len = 0;
	if (n > 15)
		len += ft_putptr_fd(n / 16, fd);
	if (len == 0)
		len += write(fd, "0x", 2);
	len += write(fd, &base[n % 16], 1);
	return (len);
}

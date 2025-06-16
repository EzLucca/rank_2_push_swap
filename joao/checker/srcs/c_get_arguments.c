/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_get_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:16:22 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/23 10:32:31 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static char	**oneline_arguments(char **argv)
{
	char	**str;

	str = ft_split(argv[1], ' ');
	if (!str || str[0] == NULL)
		exit_failure("Error\n");
	return (str);
}

static char	**multiple_arguments(int argc, char **argv)
{
	char	**str;
	int		i;

	i = 0;
	str = malloc(sizeof(char *) * argc);
	if (!str)
		exit_failure("Malloc failure.");
	while (argv[i + 1])
	{
		str[i] = ft_strdup(argv[i + 1]);
		if (!str[i])
		{
			ft_free_char_array(str);
			exit_failure("Strdup failure.");
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**get_arguments(int argc, char **argv)
{
	char	**str;

	if (argc == 2)
		str = oneline_arguments(argv);
	else
		str = multiple_arguments(argc, argv);
	return (str);
}

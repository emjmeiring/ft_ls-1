/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 13:24:36 by jomeirin          #+#    #+#             */
/*   Updated: 2016/06/17 15:47:00 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse(int argc, char **argv, t_reader *reader)
{
	char	*dot;

	dot = ".\0";
	init_flags(&(reader->flags));
	if (argc == 1)
		just_display(dot, reader);
	else if (argc == 2 && argv[1][0] != '-')
			just_display(argv[1], reader);
	else
	{
		if (argv[1][0] == '-')
		{
			if (argv[argc - 1][0] == '-')				
			{
				find_flags(argc, argv, &(reader->flags));
				if (init(dot, reader) == -1)
					return ;
				apply_flags(dot, reader);
			}
			else if (init(argv[argc - 1], reader) != -1)
			{
				find_flags(argc, argv, &(reader->flags));
				apply_flags(argv[argc - 1], reader);
			}
		}
	}
}

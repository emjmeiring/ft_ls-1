/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 13:25:15 by jomeirin          #+#    #+#             */
/*   Updated: 2016/06/17 13:25:18 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display(t_reader *reader)
{
	t_list	*runner;
	char 	*print;
	char	tab;

	tab = '\t';
	runner = reader->store->next;
	while (runner)
	{
		print = (char *)((struct dirent *)runner->content)->d_name;
		write(1, print, ft_strlen(print));
		write (1, &tab, 1);
		runner = runner->next;
	}
	printf("\n");
}

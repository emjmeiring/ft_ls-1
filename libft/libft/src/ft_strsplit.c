/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 16:51:32 by jomeirin          #+#    #+#             */
/*   Updated: 2016/05/15 16:52:24 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	d;
	int		start;
	int		end;
	char	**str_table;

	str_table = NULL;
	i = 0;
	d = 0;
	if (s && (str_table = (char **)malloc(sizeof(*str_table) * (ft_strlen(s) / 2 + 2))))
	{
		while (s[i] != '\0')
		{
			while (s[i] && s[i] == c)
			i++;
			start = i;
			while (s[i] && s[i] != c)
			i++;
			end = i;
			if (end > start)
			str_table[d++] = ft_strsub(s, start, (end - start));
		}
	}
	str_table[d] = NULL;
		return (str_table);
}

int main()
{
	char str[] = "***The*String*We**Care about **Right.";
	printf("%s\n", *ft_strsplit(str, '*'));
	return(0);
}

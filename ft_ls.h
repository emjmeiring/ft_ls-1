/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:58:44 by simzam            #+#    #+#             */
/*   Updated: 2016/06/13 09:53:19 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H
#define CURRENT_DIR "."
#define HIDDEN CURRENT_DIR
#define STD_SIZ 4
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dir_files_opener
{
	DIR				*dirp;
	struct dirent	*read;
}					t_opener;

typedef struct		s_dir_files_reader
{
	t_opener		open;
		t_list			*store;
	struct stat		buf;
}					t_reader;

void				parse(int argc, char **argv, t_reader *reader);
void				sort(t_reader *reader);
struct dirent		*alpha_sort(t_reader *reader);
void				display(t_reader *reader);
#endif

#include "ft_ls.h"

void	add_to_record(t_reader *reader)
{
	t_list *lst_alias;
	if (!reader->store->next)
	{
		reader->store->next = ft_lstnew(reader->open.read,
									sizeof(reader->store->next) * STD_SIZ);
	}
	else
	{
		lst_alias = reader->store;
		while(lst_alias->next)
			lst_alias = lst_alias->next;
		lst_alias->next = ft_lstnew(reader->open.read,
									sizeof(reader->store->next) * STD_SIZ);
	}
}

int		init(char *fname, t_reader *reader)
{
	if (!(reader->open.dirp = opendir(fname)))
	{
		perror("ft_ls: cannot access ");
		return (-1);
	}
	else
		reader->store = ft_lstnew((void *)readdir(reader->open.dirp),
									sizeof(reader->open.read));
	return (1);
}

void	populate_list(char *fname, t_reader *reader)
{
	if (init(fname, reader) == -1)
		return ;
	else
	{
		while ((reader->open.read = readdir(reader->open.dirp)))
			if (reader->open.read->d_name[0] != '.')
				add_to_record(reader);
		if (reader->flags.reverse == 'r')
			alpha_sort(reader, &z_to_a);
		else alpha_sort(reader, &a_to_z);
	}
}

void	just_display(char *fname, t_reader *reader)
{
	populate_list(fname, reader);
	display(reader);
}

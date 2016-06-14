#include "ft_ls.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if (!(new_list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content && content_size > 0)
	{
		if(!(new_list->content = malloc(content_size)))
		{
			free(new_list);
			return (NULL);
		}
		memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	else
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	new_list->next = NULL;
	return (new_list);
}

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

void	init(char *fname, t_reader *reader)
{
	if ((reader->open.dirp = opendir(fname)));
		reader->store = ft_lstnew((void *)readdir(reader->open.dirp),
									sizeof(reader->open.read));
}

//TODO: Need an extra method here for error handling.
void	just_display_alphabetically(char *fname, t_reader *reader)
{
	init(fname, reader);
	if (!reader->open.dirp)
		perror("ft_ls: cannot access ../..sd: No such file or directory");
	else
		while ((reader->open.read = readdir(reader->open.dirp)))
			if (reader->open.read->d_name[0] != '.')
				add_to_record(reader);
	reader->open.read = alpha_sort(reader);
	display(reader);
}

void	parse(int argc, char **argv, t_reader *reader)
{
	if (argc == 1)
		just_display_alphabetically(CURRENT_DIR, reader);
	else if (argc == 2 && argv[1][0] != '-')
			just_display_alphabetically(argv[1], reader);
	else
	{
		//TODO: This is where things get really interesting. Need to search for
		// flags, parse them and collect data relevant to each.
		
		printf("Fucks\n");
	}
}

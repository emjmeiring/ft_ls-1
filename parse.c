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
	printf("In add record\n");
	t_list lst_alias;
	if (reader->store)
		reader->store = ft_lstnew(CONTENT, STD_SIZ);
	else
	{
		lst_alias = *reader->store;
		while(lst_alias.next)
			lst_alias = *lst_alias.next;
		lst_alias.next = ft_lstnew(CONTENT, STD_SIZ);
	}
}

void	just_display_alphabetically(char *fname, t_reader *reader)
{
	reader->open.dirp = opendir(fname);
	while ((reader->open.read = readdir(reader->open.dirp)))
	{
		if (reader->open.read->d_name[0] != '.')
			add_to_record(reader);
		//alpha_sort(reader);
	}
//TODO: Need an extra method here for error handling.
	display(reader);
}

void	parse(int argc, char **argv, t_reader *reader)
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '.' && strlen(argv[1]) == 1))
		just_display_alphabetically(CURRENT_DIR, reader);
	else
	{
		//TODO: This is where things get really interesting. Need to search for
		// flags, parse them and collect data relevant to each.
		
		printf("Fucks\n");
	}
}

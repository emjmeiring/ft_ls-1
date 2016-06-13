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
	t_list lst_alias;
	printf("Adding to record in the beginning: %s\n", reader->open.read->d_name);
	if (!reader->store->next)
	{
		reader->store->next = ft_lstnew(CONTENT, STD_SIZ);
		printf("Adding to record: %s\n", ((struct dirent *)reader->store->next->content)->d_name);
	}
	else
	{
		printf("Adding to record2: %s\n", ((struct dirent *)reader->store->next->content)->d_name);
		lst_alias = *reader->store;
		while(lst_alias.next)
			lst_alias = *lst_alias.next;
		lst_alias.next = ft_lstnew(CONTENT, STD_SIZ);
	}
<<<<<<< 8e3e44b62d0e594fdda18dc37114475764bb052e
}
//TODO: Need an extra method here for error handling.
void	just_display_alphabetically(char *fname, t_reader *reader)
{
	reader->open.dirp = opendir(fname);
	if (!reader->open.dirp)
		perror("ft_ls: cannot access ../..sd: No such file or directory");
	else
	{
		reader->open.read = readdir(reader->open.dirp);
		reader->store = ft_lstnew(CONTENT, STD_SIZ);
		while ((reader->open.read = readdir(reader->open.dirp)))
		{
		//	printf("Read this: %s\n...no need to record it\n", (reader->open.read)->d_name);
			if (reader->open.read->d_name[0] != '.')
			{
			//	printf("But recording this: %s\n", (reader->open.read)->d_name);
				add_to_record(reader);
				//alpha_sort(reader);
			}
		}
	}
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
		
		//printf("Fucks\n");
	}
}

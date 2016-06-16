#include "ft_ls.h"

void	display(t_reader *reader)
{
	while (reader->store->next)
	{
		printf("%s ", ((struct dirent *)reader->
										store->next->content)->d_name);
		reader->store = reader->store->next;
	}
	printf("%s    ", ((struct dirent *)reader->store->content)->d_name);
	printf("\n");
}

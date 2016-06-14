#include "ft_ls.h"

//TODO: Need to recover the beginning of this linked list.
//		As things stand, the pointer is pointing to the very
//		last node of the list. This is probably caused by the
//		preceding calls like add_record in parse.c.
//		As a result, any subsequent calls from this will segfault.

void	display(t_reader *reader)
{
	while (reader->store)
	{
		printf("%s    ", ((struct dirent *)reader->store->content)->d_name);
		reader->store = reader->store->next;
	}
	printf("\n");
}

#include "ft_ls.h"

void	recursive_list(char *fname, int depth, t_reader *reader)
{
	char		*path;
	char		*path_name;
	t_list		*runner;
	t_reader	*nreader;

	nreader = (t_reader *)malloc(sizeof(nreader));
	write(1, "\n", 1);
	write(1, fname, ft_strlen(fname));
	write(1, ":\n", 2);
	just_display(fname, reader);
	runner = reader->store->next;
	while (runner)
	{
		path_name= ft_strjoin("/", (char *)((struct dirent *)runner->content)->d_name);
		nreader->open.dirp = opendir(ft_strjoin(fname, path_name));
		if (!nreader->open.dirp)
			runner = runner->next;
		else 
		{
			path = ft_strjoin(fname, "/");
			path = ft_strjoin(path, (char *)((struct dirent *)(runner->content))->d_name);
			recursive_list(path, (depth + 1), nreader);
			runner = runner->next;
		}
	}
	closedir(nreader->open.dirp);
}

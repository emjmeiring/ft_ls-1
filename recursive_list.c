#include "ft_ls.h"

void	recursive_list(const char *fname, int depth, t_reader *reader)
{
	int		path_len;
	char	path[1024];

	path_len = 0;
	if (!(reader->open.dirp = opendir(fname)))
		return ;
	if (!(reader->open.read = readdir(reader->open.dirp)))
		return ;
	while ((reader->open.read = readdir(reader->open.dirp)))
	{
		if (reader->open.read->d_type == DT_DIR)
		{
			path_len = ft_strlen(ft_strjoin(fname,
								reader->open.read->d_name));
			path[path_len] = 0;
			if (!(ft_strcmp(reader->open.read->d_name, ".") == 0 ||
					ft_strcmp(reader->open.read->d_name, "..") == 0))
				printf("%*s[%s]\n", depth * 2, "", reader->open.read->d_name);
				recursive_list(path, depth + 1, reader);
		}
		else
		{
			printf("%*s- %s\n", depth * 2, "", reader->open.read->d_name);
		}
	}
	closedir(reader->open.dirp);
}

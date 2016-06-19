#include "ft_ls.h"

void	apply_flags(char *fname, t_reader *reader)
{
	if (reader->flags.recursive == 'R')
	{
		recursive_list(fname, 0, reader);
		printf("recursive");
	}
}

void	init_flags(t_flags *flags)
{
	flags->recursive = '\0';
	flags->long_list = '\0';
	flags->reverse = '\0';
	flags->time = '\0';
	flags->all = '\0';
}

void	find_flags(int argc, char **argv, t_flags *flags)
{
	int i;

	i = 1;
	while (argv[i] && i < argc)
	{
		if (argv[i] && argv[i][0] == '-' && argv[i][1] == 'R')
		{	
			flags->recursive = 'R';
			i++;
		}
		if (argv[i] && argv[i][0] == '-' && argv[i][1] == 'l')
		{
			flags->long_list = 'l';
			i++;
		}
		if (argv[i] && argv[i][0] == '-' && argv[i][1] == 'r')
		{
			flags->reverse = 'r';
			i++;
		}
		if (argv[i] && argv[i][0] == '-' && argv[i][1] == 't')
		{
			flags->time = 't';
			i++;
		}
		if (argv[i] && argv[i][0] == '-' && argv[i][1] == 'a')
		{
			flags->all = 'a';
			i++;
		}
		i++;
	}
}


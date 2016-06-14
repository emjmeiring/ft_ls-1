#include "ft_ls.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i += 1;
	}
	return (0);
}

void	alpha_sort(t_reader *reader)
{
	int		swap;
	t_list	*runner;
	void	*temp;
	
	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		runner = reader->store;
		while (runner->next != NULL)
		{
			if (ft_strcmp(runner->content, runner->next->content) > 0)
			{
				temp = runner->content;
				runner->content = runner->next->content;
				runner->next->content = temp;
				swap = 1;
			}
			runner = runner->next;
		}
	}
}

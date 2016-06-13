int		ft_strcmp(const char *str1, const char *str2)
{
	int i;
	int s1;
	int s2;

	i = 0;
	s1 = 0;
	s2 = 0;
	while (*(str1 + i))
	{
		s1 = s1 + *(str1 + i);
		i++;
	}
	i = 0;
	while (*(str2 + i))
	{
		s2 = s2 + *(str2 + i);
		i++;
	}
	return (s1 - s2);
}

void	sort(t_reader *reader)
{
	while (read)
	{
		if (ft_strcmp(CMP_FILES) == 0)
		{
			
		}
		else if (ft_strcmp(CMP_FILES) > 0)
		{
			
		}
	}
}

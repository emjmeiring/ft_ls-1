#include <fcntl.h> 
#include <stdio.h> 
#include <sys/stat.h> 
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
//#include "get_next_line.h"
#include "libft.h"
# define BUFF_SIZE 1801

char		*str_terminate(int *str_buff_index, char *line, int *str_line_index)
{
	*str_buff_index = *str_buff_index + 1;
	line[*str_line_index] = '\0';
	*str_line_index = 0;
	return (line);
}

char		*read_zero_or_eof(char *line, int *str_buff_index)
{
	*str_buff_index = -1;
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static int	str_buff_index;
	static int	str_line_index;
	static int	read_bytes;
	static char	buffer[BUFF_SIZE];
	static char	*in_line;

	if (str_buff_index == -1)
		return (-1);
	if (str_buff_index == 0)
	{
		//printf("Read into BUffer: %s", buffer);
		if ((read_bytes = read(fd, buffer, BUFF_SIZE)) == 0)
		{
			//printf("Read into BUffer: %s", buffer);
			read_zero_or_eof(in_line, &str_buff_index);
			return (1);
		}
		//printf("Read into Buffer: %s", buffer);
	}
	if (str_line_index == 0 && !(in_line = (char *)malloc(BUFF_SIZE)))
    	return (-1);
	while (str_buff_index < read_bytes)
	{
		//printf("String buff index: %3d\n\n", str_buff_index);
		if (buffer[str_buff_index] == '\0' || buffer[str_buff_index] == '\n')
		{
			*line = str_terminate(&str_buff_index, in_line, &str_line_index);
			return (1);
		}
		in_line[str_line_index] = buffer[str_buff_index];
		str_buff_index = str_buff_index + 1;
		str_line_index = str_line_index + 1;
		printf("BUFFER\n%s", in_line);
	}
	str_buff_index = 0;
	get_next_line(fd, line);
	*line = in_line;
	//free(in_line);
	return (1);
}

int main (int argc, char** argv) 
{
	int i = 400;
	assert(argc > 0);
	/* The path at which to create the new file.  */
	char* path = *(argv + 1); 
	/* The permissions for the new file.  */ 
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	/* Create the file.  */ 
	int fd = open (path, O_CREAT, mode); 
	if (fd == -1) 
	{
		/* An error occurred. Print an error message and bail.  */ 
		perror ("open");
			return 1;
	}
	char **line = (char **)ft_memalloc(1);
	int j = 1;
	while (i--)
	{
		if (!line)
		line = (char **)ft_memalloc(1);
		get_next_line(fd, line);
		static size_t t;
		t += ft_strlen(*line);
		printf("Read Number %d: %s\n", j++, *line);
		//printf("Read String Length: %zd\n", t);
	}
	free(line);
	//printf("This is the file descriptor: %d\nAnd this is the file path: %s\n", fd, path);
	//printf("This is what was read: %s\n", *line);
	return 0; 
}

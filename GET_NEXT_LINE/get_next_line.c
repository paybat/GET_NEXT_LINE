/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 02:18:17 by hidriouc          #+#    #+#             */
/*   Updated: 2024/01/04 13:33:31 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*found_line(int fd, char **s_ptr)
{
	char	*ln;
	char	*p_of_bufer;
	char	*tmp;
	ssize_t	index;

	ln = NULL;
	index = 1;
	p_of_bufer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!p_of_bufer)
		return (free(*s_ptr), *s_ptr = NULL, NULL);
	while (index > 0)
	{
		index = read(fd, p_of_bufer, BUFFER_SIZE);
		p_of_bufer[index] = 0;
		*s_ptr = str_join(*s_ptr, p_of_bufer);
		if (str_chr(*s_ptr, '\n'))
		{
			ln = premier_ligne(*s_ptr);
			tmp = *s_ptr;
			*s_ptr = str_dup(str_chr(*s_ptr, '\n'));
			(free(p_of_bufer), free(tmp));
			return (ln);
		}
	}
	return (free(p_of_bufer), p_of_bufer = NULL, ln);
}

char	*premier_ligne(char *ptr_of_bfr1)
{
	char	*line;
	size_t	len;
	size_t	i;

	i = 0;
	if (!ptr_of_bfr1 || !*ptr_of_bfr1)
		return (NULL);
	len = str_len(ptr_of_bfr1, '\n');
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line && ptr_of_bfr1)
		return (NULL);
	while (ptr_of_bfr1[i])
	{
		line[i] = ptr_of_bfr1[i];
		if (line[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s_ptr;
	char		*l_ne;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE >= INT_MAX || BUFFER_SIZE <= 0)
	{
		if (s_ptr)
		{
			free(s_ptr);
			s_ptr = NULL;
		}
		return (NULL);
	}
	if (read(fd, 0, 0) == -1)
		return (free(s_ptr), s_ptr = NULL, NULL);
	l_ne = found_line(fd, &s_ptr);
	if (!l_ne && s_ptr)
	{
		tmp = s_ptr;
		l_ne = premier_ligne(s_ptr);
		s_ptr = str_dup(str_chr(s_ptr, '\n'));
		(free(tmp), tmp = NULL);
	}
	return (l_ne);
}

// void f(void)
// {
// 	system("leaks a.out");
// }
// int main()
// {
// 	/* code */
// 	int fd1 = open ("file1.txt", O_RDONLY);
// 	char *s =get_next_line(fd1);
// 	printf ("%s",s); //l1
// 	//close(fd1);
// 	//int fd2 = open ("file1.txt",O_RDONLY);
// 	printf ("%s",s); //NULL
// 	free(s);
// 	printf ("%s",get_next_line(-1)); //NULL
// 	// close(fd2);
// 	// int fd3 = open ("file1.txt",O_RDONLY);
// 	// printf ("%s",get_next_line(fd3)); //l3
// 	// close (fd3);
// 	// int fd4 = open ("file1.txt",O_RDONLY);
// 	// printf ("%s",get_next_line(fd4)); //l4
// 	// close(fd4);
// 	// int fd5 = open ("file1.txt",O_RDONLY);
// 	// printf ("%s",get_next_line(fd5)); //l5
// 	// close(fd5);
// 	atexit(f);
// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 02:18:17 by hidriouc          #+#    #+#             */
/*   Updated: 2023/12/28 19:31:33 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*found_line(int fd, char **s_ptr)
{
	char	*ln;
	char	*p_of_bufer;
	char	*tmp;
	int		index;

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
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
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

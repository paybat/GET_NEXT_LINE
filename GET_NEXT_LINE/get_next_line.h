/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:45:42 by hidriouc          #+#    #+#             */
/*   Updated: 2023/12/28 19:14:47 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*str_dup(char *s1);
char	*ft_strchr(char *s, int c);
char	*str_join(char *s1, char *s2);
char	*premier_ligne(char *ptr_of_bfr2);
char	*found_line(int fd, char **s_ptr);
void	*mem_cpy(void *dst, void *src, size_t n);
size_t	str_len(const char *s, char c);

#endif 
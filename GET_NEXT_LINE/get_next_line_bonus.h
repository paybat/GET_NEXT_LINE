/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:51:00 by hidriouc          #+#    #+#             */
/*   Updated: 2023/12/29 19:22:36 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 14999999
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*str_dup(char *s1);
char	*str_chr(char *s, int c);
char	*str_join(char *s1, char *s2);
char	*premier_ligne(char *ptr_of_bfr2);
char	*found_line(int fd, char **s_ptr);
void	*mem_cpy(void *dst, void *src, size_t n);
size_t	str_len(const char *s, char c);

#endif
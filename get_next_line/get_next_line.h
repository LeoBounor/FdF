/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:42:54 by Leo               #+#    #+#             */
/*   Updated: 2022/01/12 15:18:56 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_strlen_gnl(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd);
char	*ft_fill_buffer(int fd, char *buffer);
char	*ft_get_line(char *buffer);
char	*ft_move_buffer(char *buffer);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
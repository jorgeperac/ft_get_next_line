/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgeperez <jorgeperez@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:06:25 by jorgeperez        #+#    #+#             */
/*   Updated: 2026/01/05 12:18:09 by jorgeperez       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(const char *s, int c);

#endif
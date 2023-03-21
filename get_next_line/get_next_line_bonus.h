/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:57:20 by jeelee            #+#    #+#             */
/*   Updated: 2022/08/20 16:19:46 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buff
{
	int				fd;
	unsigned char	buff[BUFFER_SIZE];
	size_t			idx;
	ssize_t			rd_size;
}	t_buff;

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
size_t	set_line_into(char *new_line, char *line, size_t size);
size_t	get_now(t_buff *buffers, int fd);

#endif
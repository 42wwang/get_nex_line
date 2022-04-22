/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:26:14 by wwang             #+#    #+#             */
/*   Updated: 2022/02/15 15:27:58 by wwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(char *str);
char		*ft_strchr(char*s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
char		*ft_line(char *s);
char		*ft_save(char *s);
char		*ft_read_save(int fd, char *s);
#endif

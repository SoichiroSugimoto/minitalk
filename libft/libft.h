/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:57:50 by sosugimo          #+#    #+#             */
/*   Updated: 2021/10/07 13:31:38 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FAILED -1
# define OK 1
# define TRUE 1
# define FALSE 0
# define INT_MAX_DIGIT 10
# define MATCH 0
# define ERROR -1
# define FAULT 0
# define SUCCESS 1

long long	ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
int			ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
int			all_error_free(char **s1, char **s2);
int			get_next_line(int fd, char **line);
int			error_free(char **buf);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);

#endif

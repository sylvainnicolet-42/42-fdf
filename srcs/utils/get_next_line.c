/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:38:01 by synicole          #+#    #+#             */
/*   Updated: 2022/10/29 14:38:03 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

size_t	ft_gnl_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_gnl_strlcat(char	*dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (len < size && dst[len] != '\0')
		len++;
	if (!src)
		return (len);
	while (len + i + 1 < size && src[i] != '\0')
	{
		dst[len + i] = src[i];
		i++;
	}
	if (len + i < size)
		dst[len + i] = '\0';
	while (src[i] != '\0')
		i++;
	return (len + i);
}

int	ft_read_from_buff(char **current_buff, int fd)
{
	char	*res;
	char	*buff;
	int		len;

	buff = (char *)malloc(sizeof(char) * (1024 + 1));
	if (!buff)
		return (0);
	res = *current_buff;
	while (!ft_gnl_strchr(res, '\n'))
	{
		len = read(fd, buff, 1024);
		if (len < 0 || (ft_gnl_strlen(res) == 0 && len == 0))
		{
			free(buff);
			return (0);
		}
		if (len == 0)
			break ;
		buff[len] = '\0';
		res = ft_gnl_strjoin(res, buff);
		free(*current_buff);
		*current_buff = res;
	}
	free(buff);
	return (1);
}

char	*ft_init_new_buff(char *buff)
{
	char	*end;

	end = ft_gnl_strchr(buff, '\n');
	if (!end)
	{
		free(buff);
		return (NULL);
	}
	end = ft_gnl_strjoin(end + 1, NULL);
	free(buff);
	return (end);
}

char	*get_next_line(int fd)
{
	static char	*current_buff;
	char		*current_line;

	if (fd < 0 || 1024 <= 0)
		return (NULL);
	if (!ft_read_from_buff(&current_buff, fd))
	{
		free(current_buff);
		current_buff = NULL;
		return (NULL);
	}
	current_line = ft_get_line(current_buff);
	if (!current_line)
		return (NULL);
	current_buff = ft_init_new_buff(current_buff);
	return (current_line);
}
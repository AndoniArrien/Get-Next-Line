/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:33:17 by aarrien-          #+#    #+#             */
/*   Updated: 2022/10/06 10:20:51 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(int fd, char **buff)
{
	int		bytes_read;
	char	*temp;
	char	*buff_extra;

	buff_extra = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	temp = ft_strdup(*buff);
	free(*buff);
	bytes_read = read(fd, buff_extra, BUFFER_SIZE);
	*buff = ft_strjoin(temp, buff_extra);
	free(temp);
	free(buff_extra);
	return (bytes_read);
}

char	*ft_line(char **buff)
{
	char	*line;
	char	*temp;
	size_t	len;
	size_t	i;

	i = 0;
	temp = ft_strdup(*buff);
	if (!temp)
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	len = i + 1;
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (len > i)
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	free(temp);
	return (line);
}

void	ft_next(char **buff)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = ft_strdup(*buff);
	free(*buff);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
		*buff = ft_calloc(1, sizeof(char));
	else
		*buff = ft_strdup(&temp[i + 1]);
	free(temp);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	if (!buff[fd])
		buff[fd] = ft_calloc(1, sizeof(char));
	while ((!ft_strchr(buff[fd], '\n') && bytes_read > 0))
		bytes_read = ft_read(fd, &buff[fd]);
	if (!*buff[fd])
		return (free(buff[fd]), buff[fd] = NULL, NULL);
	line = ft_line(&buff[fd]);
	ft_next(&buff[fd]);
	return (line);
}

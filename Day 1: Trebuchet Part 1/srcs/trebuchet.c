/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trebuchet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:13:59 by dvan-den          #+#    #+#             */
/*   Updated: 2023/12/01 10:49:24 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/trebuchet.h"

int	first(char *line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (ft_isdigit(line[i]))
			return (line[i] - '0');
		i++;
	}
	return (0);
}

int	last(char *line, size_t len)
{
	size_t	i;

	i = len - 1;
	while (i >= 0)
	{
		if (ft_isdigit(line[i]))
			return (line[i] - '0');
		i--;
	}
	return (0);
}

int	calc(char *line)
{
	int		n1;
	int		n2;
	size_t	len;

	len = ft_strlen(line);
	n1 = first(line, len);
	n2 = last(line, len);
	return (n1 * 10 + n2);
}

int	trebuchet(int fd)
{
	char	*line;
	int		sum;
	int		value;
	int		count;

	sum = 0;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		value = calc(line);
		ft_printf(line);
		ft_printf("Value line %d: %d\n", count, value);
		sum = sum + value;
		line = get_next_line(fd);
	}
	return (sum);
}

int	main(void)
{
	int	fd;
	int	sum;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	sum = trebuchet(fd);
	ft_printf("\nresult:\t%d\n", sum);
	close(fd);
	return (0);
}

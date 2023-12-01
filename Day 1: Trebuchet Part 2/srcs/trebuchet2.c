/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trebuchet2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:45:42 by dvan-den          #+#    #+#             */
/*   Updated: 2023/12/01 13:47:04 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/trebuchet2.h"

int	wordsToInteger(char *str)
{
	if (strcmp(str, "one") == 0)
		return (1);
	if (strcmp(str, "1") == 0)
		return (1);
	if (strcmp(str, "two") == 0)
		return (2);
	if (strcmp(str, "2") == 0)
		return (2);
	if (strcmp(str, "three") == 0)
		return (3);
	if (strcmp(str, "3") == 0)
		return (3);
	if (strcmp(str, "four") == 0)
		return (4);
	if (strcmp(str, "4") == 0)
		return (4);
	if (strcmp(str, "five") == 0)
		return (5);
	if (strcmp(str, "5") == 0)
		return (5);
	if (strcmp(str, "six") == 0)
		return (6);
	if (strcmp(str, "seven") == 0)
		return (7);
	if (strcmp(str, "7") == 0)
		return (7);
	if (strcmp(str, "eight") == 0)
		return (8);
	if (strcmp(str, "8") == 0)
		return (8);
	if (strcmp(str, "nine") == 0)
		return (9);
	if (strcmp(str, "9") == 0)
		return (9);
	return (-1);
}

int containsSubstring(const char* string, const char* substring) {
    int stringLength = strlen(string);
    int subStringLength = strlen(substring);

    for (int i = 0; i <= stringLength - subStringLength; i++) {
        if (strncmp(string + i, substring, subStringLength) == 0) {
            return i + 1;
        }
    }

    return -1;
}


int first(char* str) {
    char* valid_numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int num_valid_numbers = sizeof(valid_numbers) / sizeof(valid_numbers[0]);
    size_t len = strlen(str);
    char buffer[len + 1];
    buffer[0] = '\0';

    for (size_t j = 0; j < len; j++) {
        strncat(buffer, &str[j], 1);
        //printf("buffer:\t\"%s\"\n", buffer);

        for (int i = 0; i < num_valid_numbers; i++) {
            int position = containsSubstring(buffer, valid_numbers[i]);
            if (position != -1) {
                return wordsToInteger(valid_numbers[i]);
            }
        }
    }

    return -1;
}

int last(char* str) {
    char* valid_numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int num_valid_numbers = sizeof(valid_numbers) / sizeof(valid_numbers[0]);
    size_t len = strlen(str);

	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = 0; j < num_valid_numbers; j++)
		{
			int position = containsSubstring(str + i, valid_numbers[j]);
			if (position != -1) {
                return wordsToInteger(valid_numbers[j]);
            }
		}
	}
    
    return -1;
}

int	calc(char *line)
{
	int	n1;
	int	n2;

	n1 = first(line);
	n2 = last(line);
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
		//ft_printf(line);
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
	ft_printf("result:\t%d\n", sum);
	close(fd);
	return (0);
}

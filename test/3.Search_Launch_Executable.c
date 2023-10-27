/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.Search_Launch_Executable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:25:23 by jaehejun          #+#    #+#             */
/*   Updated: 2023/10/27 18:38:06 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int	count_single(const char *s, char c)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == '\0'))
			count++;
		index++;
	}
	return (count);
}

static char	*single(const char *s, char c)
{
	int		index;
	int		num;
	char	*single;

	num = 0;
	while (s[num] != '\0' && s[num] != c)
		num++;
	single = (char *)malloc(sizeof(char) * (num + 1));
	if (single == NULL)
		return (NULL);
	index = 0;
	while (num-- > 0)
	{
		single[index] = s[index];
		index++;
	}
	single[index] = '\0';
	return (single);
}

static void	free_all(char **str, int index)
{
	while (index-- > 0)
		free(str[index]);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**all;

	all = (char **)malloc(sizeof(char *) * (count_single(s, c) + 1));
	if (all == NULL)
		return (NULL);
	index = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0' && *s != c)
		{
			all[index++] = single(s, c);
			if (all[index - 1] == 0)
			{
				free_all(all, index);
				return (NULL);
			}
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	all[index] = NULL;
	return (all);
}

char	*find_executable(char *executable_name)
{
	char	*listed_path;
	char	**single_path;
	char	*executable_path;

	(void)executable_name;
	listed_path = getenv("PATH");
	printf("LISTED_PATH: %s\n", listed_path);
	single_path = ft_split(listed_path, ':');
	while (*single_path != NULL)
	{
		executable_path = strcat(*single_path, "/");
		executable_path = strcat(executable_path, executable_name);
		if (access(executable_path, X_OK) == 0)
		{
			printf("EXECUTABLE_PATH: %s\n", executable_path);
			return (executable_path);
		}
		single_path++;
	}
	return (NULL);
}
int	main(int argc, char **argv)
{
	char	*executable_path;

	(void)argc;
	executable_path = find_executable(argv[1]);
	//argv[0] = executable_path;
	//argv[0] = "-l";
	//argv[1] = NULL;
	argv[1] = "";
	argv[2] = "a";
	argv[3] = NULL;
	//argv[4] = NULL;
	if (executable_path == NULL)
		printf("Executable not found\n");
	else
	{
		printf("Executable found : %s\n", executable_path);
		//printf("argv[2]: %s\n", argv[2]);
		execve(executable_path, argv, NULL);
		printf("execve failed\n");
	}
	return (0);
}

//int	main(void)
//{
//	execve("/bin/ls", "ls -l", NULL);
//	printf("execve failed\n");
//	return (0);
//}
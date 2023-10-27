/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.Display_Prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:18:54 by jaehejun          #+#    #+#             */
/*   Updated: 2023/10/24 15:44:28 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

typedef struct s_prompt
{
	char	**cmd;
	char	**envp;
}	t_prompt;

void	sigint_handler(int signum)
{
	(void)signum;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char	*line;
	char	**tokens;

	while (1)
	{
		rl_catch_signals = 0;
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		line = readline("myshell$ ");
		if (line == NULL)
		{
			printf("\033[1A\033[9Cexit\n");
			exit(0);
		}
		if (line[0] != '\0')
		{
			add_history(line);
			tokens = tokenize_line(line);
		}
	}
	return (0);
}

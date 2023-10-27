/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:46:53 by jaehejun          #+#    #+#             */
/*   Updated: 2023/10/27 17:44:39 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char	*line;
	char	**tokens;

	g_exit_status = 0;
	while (1)
	{
		rl_catch_signals = 0;
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		line = readline("myshell$ ");
		if (line == NULL)
		{
			printf("\033[1A\033[9Cexit\n");
			g_exit_status = 0;
			exit(0);
		}
		if (line[0] != '\0')
		{
			add_history(line);
			if (check_quotes(line) == 0) // ' 또는 " 홀수 -> unclosed quotes
			{
				printf("quote is not closed\n");
				free(line);
				g_exit_status = 1;
				continue ;
			}
			else
				tokens = tokenize_line(line);
		}
	}
	return (0);
}

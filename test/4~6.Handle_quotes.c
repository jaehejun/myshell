/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4~6.Handle_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:02:42 by jaehejun          #+#    #+#             */
/*   Updated: 2023/10/20 19:58:56 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

char	**tokenize(char *typed)
{
	char	**tokens;
	int		t_cnt;

	t_cnt = count_tokens(typed);
	tokens = (char **)malloc(sizeof(char *) * (t_cnt + 1));
	tokens[t_cnt] = NULL;
	
	
}
int	main(void)
{
	char	*typed;
	char	**tokens;

	typed = readline("prompt> ");
	printf("%s\n", typed);
	tokens = tokenize(typed);
	strtok()
}
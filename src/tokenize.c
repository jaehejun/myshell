/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:11:50 by jaehejun          #+#    #+#             */
/*   Updated: 2023/10/28 17:46:35 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_tokens(char *line)
{
	int	idx;
	int	token_count;
	int	s_quotes;
	int	d_quotes;

	idx = 0;
	token_count = 0;
	s_quotes = 0;
	d_quotes = 0;
	while (line[idx] != '\0')
	{
		while (line[idx] == ' ')
			idx++;
		if (line[idx] == '\'')
		{
			idx++;
			while (line[idx] != '\'')
				idx++;
		}
		
		else if (line[idx] == '\"')
		{
			
		}
		
		else
		{
			
		}
	}
	
	return (token_count);
	
}

char	**tokenize_line(char *line)
{
	char	**tokens;
	int		token_count;
	int		idx;

	token_count = count_tokens(line);
	tokens = (char **)malloc(sizeof(char *) * (token_count + 1));

	while (line[idx] != '\0')
	{
		
	}
}

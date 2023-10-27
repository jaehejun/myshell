/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:19:59 by jaehejun          #+#    #+#             */
/*   Updated: 2023/10/24 16:25:58 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_quotes(char *line)
{
	int	index;
	int	s_quotes;
	int	d_quotes;

	index = 0;
	s_quotes = 0;
	d_quotes = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '\'')
			s_quotes++;
		if (line[index] == '\"')
			d_quotes++;
		index++;
	}
	if (s_quotes % 2 != 0 || d_quotes % 2 != 0)
		return (0);
	return (1);
}

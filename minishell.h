/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:46:50 by jaehejun          #+#    #+#             */
/*   Updated: 2023/10/27 16:06:44 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_envp;

typedef struct s_redir
{
	int				type; //(< > << >>)
	char			*filename;
	struct s_redir	*next;
}	t_redir;

typedef struct s_process
{
	//struct s_envp		*envp; // 굳이 일일수수도
	struct s_redir		*redir;
	char				**cmd;
	struct s_process	*next;
	//int	infile
	//int	outfile
}	t_process;        

void	sigint_handler(int signum);

int		check_quotes(char *line);
char	**tokenize_line(char *line);
int		count_tokens(char *line);

#endif

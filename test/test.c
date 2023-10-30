/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:42:49 by jaehejun          #+#    #+#             */
/*   Updated: 2023/10/30 22:26:00 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OPEN 1
#define CLOSED 0

int	is_meta(char c);
int	is_space(char c);
int	is_oper(char c);

int	is_meta(char c)
{
	if (is_space(c) == TRUE || is_oper(c) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (TRUE);
	return (FALSE);
}

int	is_oper(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (TRUE);
	return (FALSE);
}

//int	is_quote(char c)
//{
//	if (c == '\'' || c == '\"')
//		return (TRUE);
//	return (FALSE);
//}

int	count_tokens(char *str)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (str[idx] != '\0')
	{
		while (is_space(str[idx]) == TRUE && str[idx] != '\0') // skip space
			idx++;
		if (str[idx] != '\0') // oper or word
		{
			if (is_oper(str[idx]) == TRUE) //oper
			{
				printf("%c\n", str[idx]);
				count++;
				while (is_oper(str[idx]) == TRUE && str[idx] != '\0') // oper continues
					idx++;
			}
			else // word
			{
				printf("%c\n", str[idx]);
				count++;
				while (is_meta(str[idx]) == FALSE && str[idx] != '\0') // word continues
					idx++;
			}
		}
	}
	return (count);
}

int	main(void)
{
	char	*str = "  ab  <cd  |ef <<< g>>h i ";

	printf("%d\n", count_tokens(str));
	printf("single:%d\n", '\'');
	printf("double:%d\n", '\"');
	return (0);
}


//#define OPEN 1
//#define CLOSED 0

//static int	count_words(const char *str)
//{
//	int	sq;
//	int	dq;
//	int	index;
//	int	count;

//	sq = CLOSED;  // Tracker for single quotes.
//	dq = CLOSED;  // Tracker for double quotes.

//	while (str[index] != '\0')
//	{
//		// Check if current character is not a space.
//		if (str[index] != ' ')
//		{
//			count++;
//			// If the character is not a space or it is inside quotes, keep counting.
//			while ((str[index] != ' ' || sq == OPEN) && str[index] != '\0')
//			{
//				if (dq == CLOSED && (str[index] == '\"' || str[index] == '\''))
//				{
//					dq = str[index];
//				}
//				sq = (sq + (str[index] == dq)) % 2;
//				dq *= (sq == OPEN);
//				index++;
//			}
//			// If quotes are not balanced, return error.
//			if (sq == OPEN)
//				return (-1);
//		}
//		else // (str[index] == ' ')
//			index++;
//	}
//	return (count);
//}
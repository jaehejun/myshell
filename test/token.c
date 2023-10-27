/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:54:49 by jaehejun          #+#    #+#             */
/*   Updated: 2023/10/25 17:39:11 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

//#define TRUE 1
//#define FALSE 0

//int main()
//{
//    const char *str =  "\"ls '-al\" qwe ";
//    int i = 0;
//    int flag_dq = FALSE;
//    int flag_sq = FALSE;
//    int st = 0;
//    char *tmp;
//    while (str[i])
//    {
//        if (str[i] == '"' && flag_sq == FALSE)
//            flag_dq = !flag_dq;
//        if (str[i] == '\'' && flag_dq == FALSE)
//            flag_sq = !flag_sq;
//        if (flag_dq == FALSE && flag_sq == FALSE && (str[i] == ' ' || str[i] == '\0'))
//        {
//            tmp = strndup(str + st, i - st);
//            printf("%s\n", tmp);
//            while (str[i] == ' ')
//                i++;
//            st = i;
//        }
//        else
//            i++;
//    }
//    if (flag_dq == TRUE || flag_sq == TRUE)
//        printf("INVALID ARG\n");
//}


int main(void)
{
    char    *line;
    line = readline("myshell$ ");
    while (*line != '\0' && *line != '|')
        line++;
    if (*line == '\0')
        printf("NULL");
    printf("%s\n", line);
    return (0);
}
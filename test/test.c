#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//int	main(void)
//{
//	char	*str[2];

//	str[0] = "/bin/ls";
//	str[1] = NULL;

//	execve(str[0], str, NULL);
//	printf("execve failed\n");
//	return (0);
//}

//int	main(int argc, char **argv, char **envp)
//{
//	(void)argc;
//	(void)argv;
//	int i = 0;
//	while (envp != NULL && envp[i] != NULL)
//	{
//		printf("ENVP %d: %s\n", i, envp[i]);
//		i++;
//	}
//	return (0);
//}

//int	main(void)
//{
//	char	*var;

//	var = getenv("PATH");
//	printf("%s\n", var);
//	return (0);
//}

//int	main(void)
//{
//	char	*str;

//	str = "";
//	printf("%d\n", str[0]);
//	if (str == NULL)
//		printf("NULL\n");
//	if (str[0] == '\0')
//		printf("null char\n");
//	return (0);
//}

//int	count_words(const char* str)
//{
//	int	count;
//	int	flag;
//	int	idx;

//	count = 0;
//	flag = 0;
//	idx = 0;
//	while (str[idx] != '\0')
//	{
//		while (str[idx] != ' ')
//			idx++;
//		if (str[idx] == ' ' && flag == 0)
//			idx++;
//		else if ((str[idx] == '\'' || str[idx] == '\"') && flag == 0)
//			flag = 1;
//		else
//			idx++;
//	}
//	return count;
//}



static int	count_words(const char *str)
{
	int	sq;
	int	dq;
	int	index;
	int	count;

	sq = 0;  // Tracker for single quotes.
	dq = 0;  // Tracker for double quotes.
	count = 0;  // Counter for words.
	index = 0;  // Index for string.
	while (str[index] != '\0')
	{
		// Check if current character is not a space.
		if (str[index] != ' ')
		{
			count++;
			// If the character is not a space or it is inside quotes, keep counting.
			while ((str[index] != ' ' || sq != 0) && str[index] != '\0')
			{
				if (dq == 0 && (str[index] == '\"' || str[index] == '\''))
					dq = str[index];
				sq = (sq + (str[index] == dq)) % 2;
				dq *= (sq != 0);
				index++;
			}
			// If quotes are not balanced, return error.
			if (sq != 0)
				return (-1);
		}
		else
			index++;
	}
	return (count);
}

int	main(void)
{
	//char	*str = " a b 'c'd e\"f\"g h   ";
	char	*str = " \"\" \"\" \"\" \"\" \"\"  ";

	printf("%d\n", count_words(str));
	return (0);
}
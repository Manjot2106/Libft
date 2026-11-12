/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:28:54 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:50:39 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word);
}

static char	*ft_strndup(const char *src, int n)
{
	char	*res;
	int		i;

	res = malloc((n + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_free(char **a, int i)
{
	while (i >= 0)
	{
		free(a[i]);
		i--;
	}
	free(a);
}

static char	**ft_maloc(const char *s, char c, int *pos, int *words)
{
	char	**arr;
	int		i;

	*pos = 0;
	*words = 0;
	i = ft_countword(s, c);
	arr = malloc(sizeof(char *) * (i + 1));
	if (!arr)
		return (NULL);
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		words;
	int		i;
	int		start;

	arr = ft_maloc(s, c, &i, &words);
	if (!arr)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			arr[words] = ft_strndup(s + start, i - start);
			if (!arr[words++])
				return (ft_free(arr, words - 1), NULL);
		}
	}
	arr[words] = NULL;
	return (arr);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	**str;
// 	int		i;

// 	i = 0;
// 	str = ft_split("hello i a toi", ' ');
// 	while (str[i])
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}
// }

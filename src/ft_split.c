/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares <psoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:47:40 by psoares           #+#    #+#             */
/*   Updated: 2021/10/27 01:41:50 by psoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static	int	calc_words(char const *str, char c)
{
	int		i;
	int		words;
	int		f;

	f = 0;
	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			f = 0;
		else if (str[i] != c && f == 0)
		{
			words++;
			f = 1;
		}
		i++;
	}
	return (words);
}

static	int	calc_symbols(char const *s, char c)
{
	int	symb;

	symb = 0;
	while (*s != c && *s != '\0')
	{
		symb++;
		s++;
	}
	return (symb);
}

static	int	array_sim(int symb, char const *s, char *ar)
{
	int	symb_in_word;

	symb_in_word = 0;
	while (symb_in_word < symb)
	{
		ar[symb_in_word] = *s;
		s++;
		symb_in_word++;
	}
	ar[symb_in_word] = '\0';
	return (symb_in_word);
}

static	char	**ft_strdel(char **array, int counter)
{
	int	i;

	i = 0;
	while (counter > 0)
	{
		counter--;
		free((void *)array[counter]);
		array[counter] = NULL;
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	int		symb;
	char	**array;

	if (!s)
		return (NULL);
	words = calc_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < words && *s != '\0')
	{
		while (*s == c)
			s++;
		symb = calc_symbols(s, c);
		array[i] = (char *)malloc(sizeof(char) * symb + 1);
		if (!array[i])
			return (ft_strdel(array, i));
		s += array_sim(symb, s, array[i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}

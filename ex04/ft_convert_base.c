/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:19:14 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/06 14:19:15 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <unistd.h>
#include <stdio.h>

/**
 * Returns the index of c in str
 */
int	ft_find(char	*str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

/**
 * Returns 1 negative, 0 if positive
 */
int	ft_sign(char *nbr, int *i)
{
	int sign;

	sign = 0;
	while (nbr[*i] == '+' || nbr[*i] == '-')
	{
		if (nbr[*i] == '-')
			sign = !sign;
		(*i)++;
	}
	return (sign);
}

int ft_atoi_base(char *nbr, char *base_from, int *i)
{
	int		n;
	int		x;
	int		l;

	l = 0;
	while (base_from[l])
		l++;
	n = 0;
	x = 0;
	while (nbr[*i])
	{
		x = ft_find(base_from, nbr[*i]);
		if (x == -1)
			break ;
		n *= l;
		n += x;
		(*i)++;
	}
	return (n);
}

int	ft_count(int n, char *base_to, int l)
{
	if (n < l)
		return 1;
	else
		return 1 + ft_count(n / l, base_to, l);
}

int	ft_putnbr_base(char* result, int n, char *base_to, int l)
{
	int	i;

	if (n < l)
	{
		result[0] = base_to[n];
		return 1;
	}
	else
	{
		i = ft_putnbr_base(result, n / l, base_to, l);
		result[i] = base_to[n % l];
		return i + 1;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		s;
	int		n;
	int		l;
	int		c;
	char	*result;
	char	*start;

	i = 0;
	s = ft_sign(nbr, &i);
	n = ft_atoi_base(nbr, base_from, &i);
	l = 0;
	while (base_to[l])
		l++;
	c = ft_count(n, base_to, l);
	result = malloc((s + c + 1) * sizeof(char));
	if (s)
		result[0] = '-';
	start = &result[s];
	ft_putnbr_base(start, n, base_to, l);
	start[c] = '\0';
	return (result);
}

int	main()
{
	printf("%s\n", ft_convert_base("-100", "0123456789", "01"));
}
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

int	ft_find(char	*str, char c);

int	ft_sign(char *nbr, int *i);

int	ft_check_bases(char *base_from, char *base_to);

unsigned int	ft_atoi_base(char *nbr, char *base_from, int *i)
{
	unsigned int	n;
	int				x;
	int				l;

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

int	ft_count(unsigned int n, char *base_to, unsigned int l)
{
	if (n < l)
		return (1);
	else
		return (1 + ft_count(n / l, base_to, l));
}

int	ft_putnbr_base(char *result, unsigned int n, char *base_to, unsigned int l)
{
	int	i;

	if (n < l)
	{
		result[0] = base_to[n];
		return (1);
	}
	else
	{
		i = ft_putnbr_base(result, n / l, base_to, l);
		result[i] = base_to[n % l];
		return (i + 1);
	}
}

int	ft_read(char *nbr, char *base_from, int *sign)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	*sign = ft_sign(nbr, &i);
	return (ft_atoi_base(nbr, base_from, &i));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				sign;
	unsigned int	n;
	unsigned int	l_to;
	int				count;
	char			*result;

	sign = 0;
	l_to = ft_check_bases(base_from, base_to);
	if (l_to == 0)
		return (0);
	n = ft_read(nbr, base_from, &sign);
	count = ft_count(n, base_to, l_to);
	result = malloc((sign + count + 1) * sizeof(char));
	if (!result)
		return (0);
	if (sign)
		result[0] = '-';
	ft_putnbr_base(&result[sign], n, base_to, l_to);
	(&result[sign])[count] = '\0';
	return (result);
}

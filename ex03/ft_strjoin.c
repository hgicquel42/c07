/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:48:11 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/05 17:48:12 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_write(char *result, int *k, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		result[*k] = src[i];
		(*k)++;
		i++;
	}
}

int	ft_strlen_all(int size, char **strs, char *sep)
{
	int	i;
	int	l;
	int	s;

	l = 0;
	i = 0;
	s = ft_strlen(sep);
	while (i < size)
	{
		l += ft_strlen(strs[i]);
		if (i > 0 && i < size - 1)
			l += s;
		i++;
	}
	return (l);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		l;
	int		k;

	l = ft_strlen_all(size, strs, sep);
	result = malloc((l + 1) * sizeof(char));
	k = 0;
	i = 0;
	while (i < size)
	{
		ft_write(result, &k, strs[i]);
		if (i < size - 1)
			ft_write(result, &k, sep);
		i++;
	}
	result[k] = '\0';
	return (result);
}

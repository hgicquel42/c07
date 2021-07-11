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

// #include <stdio.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	ft_strlen_all(int size, char **strs, char *sep)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	while (i < size)
	{
		l += ft_strlen(strs[i++]);
		if (i < size)
			l += ft_strlen(sep);
	}
	return (l);
}

int	ft_write(char *result, char *src, int offset)
{
	int	i;

	i = 0;
	while (src[i])
		result[offset++] = src[i++];
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		l;
	int		k;

	l = ft_strlen_all(size, strs, sep);
	result = malloc((l + 1) * sizeof(char));
	if (!result)
		return (0);
	k = 0;
	i = 0;
	while (i < size)
	{
		k += ft_write(result, strs[i++], k);
		if (i < size)
			k += ft_write(result, sep, k);
	}
	result[k] = '\0';
	return (result);
}

// int	main(int argc, char **argv)
// {
// 	printf("%s\n", ft_strjoin(argc - 1, &argv[1], "-"));
// }
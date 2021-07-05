/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:34:26 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/05 17:34:27 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	count;
	int	i;

	count = max - min;
	if (count < 1)
	{
		*range = 0;
		return (0);
	}
	tab = malloc(count * sizeof(int));
	i = 0;
	while (i < count)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

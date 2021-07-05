/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:45:02 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/05 17:45:04 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
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
	if (!tab)
		return (-1);
	i = 0;
	while (i < count)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (count);
}

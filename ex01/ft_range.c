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

// #include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (0);
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (0);
	i = 0;
	while (i < (max - min))
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

// int	main(int argc, char	**argv)
// {
// 	if (argc != 3)
// 		return (1);
// 	int min = atoi(argv[1]);
// 	int max = atoi(argv[2]);
// 	int	*range = ft_range(min, max);

// 	for (int i = 0; i < max - min; i++)
// 		printf("%d\n", range[i]);
// 	return (0);
// }

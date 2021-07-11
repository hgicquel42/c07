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

// #include <stdio.h>

int	ft_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc((max - min) * sizeof(int));
	if (!(*range))
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}

// int	main(int argc, char	**argv)
// {
// 	if (argc != 3)
// 		return (1);
// 	int	*range;
// 	int min = atoi(argv[1]);
// 	int max = atoi(argv[2]);
// 	int	count = ft_range(&range, min, max);

// 	for (int i = 0; i < count; i++)
// 		printf("%d\n", range[i]);
// 	printf("total %d\n", count);
// 	return (0);
// }

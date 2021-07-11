#include <stdlib.h>

// // REMOVE
// #include <stdio.h>

int				ft_find(char	*str, char c);

int				ft_check_base(char *base);

unsigned int	ft_abs(int x);

int	ft_fillnbr(char *result, int n, char *base, int size)
{
	int	i;

	if (n < 0)
	{
		if (n > -size)
		{
			result[0] = base[-(n % size)];
			return (1);
		}
		i = ft_fillnbr(result, n / size, base, size);
		result[i] = base[-(n % size)];
		return (1 + i);
	}
	else
	{
		if (n < size)
		{
			result[0] = base[n % size];
			return (1);
		}
		i = ft_fillnbr(result, n / size, base, size);
		result[i] = base[n % size];
		return (1 + i);
	}
}

char	*ft_itoa_base(int n, char *base)
{
	int				count;
	unsigned int	temp;
	unsigned int	size;
	char			*result;

	size = 0;
	while (base[size])
		size++;
	temp = ft_abs(n);
	count = 1 + (n < 0);
	while (temp >= size)
		count++, temp /= size;
	result = malloc((count + 1) * sizeof(char));
	if (n < 0)
		result[0] = '-';
	ft_fillnbr(&result[(n < 0)], n, base, size);
	result[count] = '\0';
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	x;
	int	size;
	int	sign;

	size = 0;
	while (base[size])
		size++;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	n = 0;
	while (1)
	{
		x = ft_find(base, str[i++]);
		if (x == -1)
			break ;
		n = (n * size) + (sign * x);
	}
	return (n);
}

char	*ft_convert_base(char *from, char *base_from, char *base_to)
{
	int	n;

	if (!ft_check_base(base_from))
		return (0);
	if (!ft_check_base(base_to))
		return (0);
	n = ft_atoi_base(from, base_from);
	return (ft_itoa_base(n, base_to));
}

// int	main(int argc, char **argv)
// {
// 	if (argc != 4)
// 		return (1);
// 	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
// }

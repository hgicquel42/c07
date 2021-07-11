int	ft_find(char	*str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_check_base(char *base)
{
	int	i;
	int	l;

	l = 0;
	while (base[l])
	{
		if (base[l] == '-' || base[l] == '+')
			return (0);
		if (base[l] == ' ' || (base[l] >= 9 && base[l] <= 13))
			return (0);
		i = 0;
		while (base[i])
		{
			if ((i != l) && (base[i] == base[l]))
				return (0);
			i++;
		}
		l++;
	}
	if (l < 2)
		return (0);
	return (1);
}

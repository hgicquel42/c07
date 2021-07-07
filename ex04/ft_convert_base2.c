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
	int	sign;

	sign = 0;
	while (nbr[*i] == '+' || nbr[*i] == '-')
	{
		if (nbr[*i] == '-')
			sign = !sign;
		(*i)++;
	}
	return (sign);
}

unsigned int	ft_check_base(char *base)
{
	unsigned int	i;
	unsigned int	l;

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
	return (l);
}

unsigned int	ft_check_bases(char *base_from, char *base_to)
{
	unsigned int	l_from;
	unsigned int	l_to;

	l_from = ft_check_base(base_from);
	l_to = ft_check_base(base_to);
	if (l_from < 2 || l_to < 2)
		return (0);
	else
		return (l_to);
}

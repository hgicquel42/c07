#include <stdlib.h>

// #include <unistd.h>
// #include <stdio.h>

int	ft_include(char	*str, int l, char c)
{
	int	i;

	i = 0;
	while (i < l && str[i] != c)
		i++;
	if (i == l)
		return (0);
	return (1);
}

int	ft_count(char *str, char *charset, int l)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		if (ft_include(charset, l, str[i++]))
			continue ;
		i--;
		j = 0;
		while (str[i + j] && !ft_include(charset, l, str[i + j]))
			j++;
		i += j;
		s++;
	}
	return (s);
}

void	ft_alloc(char **strs, char *str, char *charset, int l)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		if (ft_include(charset, l, str[i++]))
			continue ;
		i--;
		j = 1;
		while (str[i + j] && !ft_include(charset, l, str[i + j]))
			j++;
		strs[s] = malloc((j + 1) * sizeof(char));
		i += j;
		s++;
	}
	strs[s] = 0;
}

void	ft_fill(char **strs, char *str, char *charset, int l)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		if (ft_include(charset, l, str[i++]))
			continue ;
		i--;
		strs[s][0] = str[i];
		j = 1;
		while (str[i + j] && !ft_include(charset, l, str[i + j]))
		{
			strs[s][j] = str[i + j];
			j++;
		}
		strs[s][j] = '\0';
		i += j;
		s++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		l;
	int		i;
	int		j;
	int		s;
	char	**strs;

	l = 0;
	while (charset[l])
		l++;
	s = ft_count(str, charset, l);
	strs = malloc((s + 1) * sizeof(char *));
	ft_alloc(strs, str, charset, l);
	ft_fill(strs, str, charset, l);
	return (strs);
}

// int	main()
// {
// 	int i;
// 	int	j;
// 	char **strs = ft_split("1645640789hello641364world466354", "0123456789");

// 	i = 0;
// 	while (strs[i])
// 	{
// 		j = 0;
// 		while (strs[i][j])
// 			j++;
// 		write(1, strs[i], j);
// 		write(1, "\n", 1);
// 		i++;
// 	}
// }
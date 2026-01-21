#include "push_swap.h"

int	match_flag(char* s)
{
	if (ft_strcmp(s, "--simple"))
		return (1);
	else if (ft_strcmp(s, "--medium"))
		return (2);
	else if (ft_strcmp(s, "--complex"))
		return (3);
	else if (ft_strcmp(s, "--adaptive"))
		return (4);
	else
		return (-1);
}
int flag(char** s)
{
	int	i;
	int j;

	i = 0;
	while (s[i])
	{
		if (match_flag(s) != -1)
			return (i);
		i++;
	}
	return (-1)
}
int number(char** s, int index)
{
	int	i;
	int j;

	i = 0;
	while (s[i])
	{
		if (i == index)
			i++;
		j = 0;
		while (s[i][j] && s[i])
		{
			if (j == 0 && (s[i][j] == '-' || s[i][j] == '+'))
				j++;
			if (!(s[i][j] >= '0' && s[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);

}
int dup(int* p)
{
	int	i;
	int j;

	i = 0;
	while (p[i])
	{
		j = i + 1;
		while (p[j])
			if (p[i] == p[j])
				return (1);
		i++;
	}
	return (0);
}
int valid(char** s)
{
	int	index;
	
	index = flag(s);
	if (!number(s, index))
		return (-1);
	if (dup(s))
		return(-1);
	return (1);

}

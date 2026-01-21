#include "push_swap.h"

int* get_numbers(char** s, int index)
{
	int i;
	int j;
	int* p;

	i = 0;
	while (s[i])
		i++;
	if (index != -1)
		i--;
	p = malloc(i * sizeof(int));
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (p[i] && s[j])
	{
		if (index == j)
			j++;
		if (!s[j])
			break;
		p[i++] = ft_atoi(s[j++]);
	}
	return (p); 
}
void split_free(char** p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}
int main(int argc, char** argv)
{
	char** args;
	int* p;
	t_stack* a;
	t_stack* taila;
	
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (0);
	}
	else
		args = argv + 1;
	if (valid(args) == -1)
		return (0);
	p = get_numbers(args, flag(args));
	if (argc == 2)
		split_free(args);
	if (!p)
		return (0);
	taila = NULL;
	a = init_a(p, &taila);
	if (sorted(a))
		return(0);
	else
		sort(a, taila);
	return (free(p), 0);
}

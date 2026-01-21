void rrr(t_stack** a, t_stack** taila, t_stack** b, t_stack** tailb)
{
	rra(a, taila);
	rrb(b, tailb);
	write(1, "rra\n", 4);
	write(1, "rrb\n", 4);

}
int stack_len(t_stack* s)
{
	int count;

	count = 0;
	whie(s)
	{
		count++;
		s = s->next;
	}
	return (count);
}
int sorted(t_stack* s)
{
	if (!s)
		return (1);
	while (s->next)
	{
		if (s->value > s->next->value)
			return (0);
		s = s->next;
	}
	return (1)
}
float disorder(t_stack* a, t_stack* tail)
{
	float mistakes;
	float total_pairs;
	int i;
	int j;
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack_len(a) - 1)
	{
		j = i + 1;
		while (j < stack_len(a) - 1)
		{
			total_pairs++;
			if (a->value > a->next->value)
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs)
}

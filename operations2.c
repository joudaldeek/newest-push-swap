void ra(t_stack** a, t_stack** tail)
{
	t_stack* tmp;

	if (!a || !*a || !(*a)->next)
		return;
	tmp = *a;
	*a = (*a)->next;
	*a->previous = NULL;
	(*tail)->next = tmp;
	tmp->next = NULL;
	tmp->previous = *tail;
	(*tail) = tmp;
	write(1, "ra\n", 3);

}

void rb(t_stack** b, t_stack** tail)
{
	t_stack* tmp;

	if (!b|| !*b || !(*b)->next)
		return;
	tmp = *b;
	*b = (*b)->next;
	*b->previous = NULL;
	(*tail)->next = tmp;
	tmp->next = NULL;
	tmp->previous = *tail;
	(*tail) = tmp;
	write(1, "rb\n", 3);
}
void rr(t_stack** a, t_stack** taila, t_stack** b, t_stack** tailb)
{
	ra(a, taila);
	rb(b, tailb);
	write(1, "ra\n", 3);
	write(1, "rb\n", 3);
}

void rra(t_stack** a, t_stack** tail)
{
	t_stack* tmp;
	
	if (!a || !(*a) || !(*a)->next)
		return;
	tmp = (*tail)->previous;
	(*tail)->next = *a;
	(*a)->previous = (*tail);
	(*tail)->previous = NULL;
	tmp->next = NULL;
	*a = *tail;
	*tail = tmp;
	write(1, "rra\n", 4);
}

void rrb(t_stack** b, t_stack** tail)
{
	t_stack* tmp;

	if (!b || !(*b) || !(*b)->next)
		return;
	tmp = (*tail)->previous;
	(*tail)->next = *b;
	(*b)->previous = (*tail);
	(*tail)->previous = NULL;
	tmp->next = NULL;
	*b = *tail;
	*tail = tmp;
	write(1, "rrb\n", 4);

}


t_stack* ft_lstnew(int value)
{
	t_stack* node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
void init_a(int* p, t_stack** taila)
{
	int i;
	t_stack* head;
	t_stack* temp;

	i = 0;
	head = ft_lstnew(p[i]);
	if (!head)
		return (NULL);
	i++;
	*tail = head;
	while (p[i])
	{
		(*taila)->next = ft_lstnew(p[i++]);
		temp = *taila;
		*taila = (*taila)->next;
		(*taila)->previous = temp;
	}
	return (head);
}

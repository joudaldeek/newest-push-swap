/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaldeek <jaldeek@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:43:51 by jaldeek           #+#    #+#             */
/*   Updated: 2026/02/03 12:06:39 by jaldeek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max_bits(t_stack **a)
{
	int		max;
	int		num_of_bits;
	t_stack	*tmp;

	if (!(*a))
		return (0);
	tmp = *a;
	num_of_bits = 0;
	max = tmp ->value;
	while (tmp)
	{
		if (tmp ->value > max)
			max = tmp ->value;
		tmp = tmp ->next;
	}
	while (1 << num_of_bits <= max)
		num_of_bits++;
	return (num_of_bits);
}

void	radix(t_stack **a, t_stack **taila, t_stack **b, t_stack **tailb)
{
	int	i;
	int	j;
	int	bits;
	int	len;

	bits = max_bits(a);
	i = 0;
	while (i < bits)
	{
		len = stack_len(a);
		j = 0;
		while (j < len)
		{
			if (((*a)->value >> i & 1) == 0)
				pb(a, b);
			else
				ra(a, taila);
			j++;
		}
		while (stack_len(b) > 0)
			pa(a, b);
		i++;
	}
}

void	complex(t_stack **a, t_stack **taila, t_stack **b, t_stack **tailb)
{
	int		len;
	int		i;
	int		*p;
	t_stack	*tmp;

	i = 0;
	len = stack_len(a);
	tmp = *a;
	p = malloc(len * sizeof(int));
	while (tmp)
	{
		p[i] = tmp ->value;
		i++;
		tmp = tmp ->value;
	}
	sort_p(p);
	set_index(a, p);
	radix();
	set_values(a, p);
}

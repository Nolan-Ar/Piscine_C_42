/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourusername <yourusername@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:00:00 by yourusername     #+#    #+#              */
/*   Updated: 2024/05/27 10:00:00 by yourusername    ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_operating	get_operating(char *op)
{
	if (op[0] == '+' && op[1] == '\0')
		return (&ft_add);
	else if (op[0] == '-' && op[1] == '\0')
		return (&ft_less);
	else if (op[0] == '*' && op[1] == '\0')
		return (&ft_mult);
	else if (op[0] == '/' && op[1] == '\0')
		return (&ft_div);
	else if (op[0] == '%' && op[1] == '\0')
		return (&ft_mod);
	return (0);
}

int	main(int argc, char **argv)
{
	t_operating	op;
	int			a;
	int			b;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	op = get_operating(argv[2]);
	if (!op)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		if (argv[2][0] == '%')
			write(1, "Stop : modulo by zero\n", 22);
		else
			write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	ft_putnbr(op(a, b));
	write(1, "\n", 1);
	return (0);
}


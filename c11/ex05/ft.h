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
#ifndef FT_H
# define FT_H

# include <unistd.h>

typedef int	(*t_operating)(int, int);

void	ft_putnbr(int n);

int		ft_atoi(char *str);
int		ft_div(int a, int b);
int		ft_add(int a, int b);
int		ft_less(int a, int b);
int		ft_mult(int a, int b);
int		ft_mod(int a, int b);

#endif

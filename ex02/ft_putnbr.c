/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:40:59 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/31 18:40:59 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		count;
	char	digit[10];

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
			write(1, "2147483648", 10);
		nb *= -1;
	}
	if (nb == 0)
		write(1, "0", 1);
	count = 0;
	while (nb > 0)
	{
		digit[9 - count] = nb % 10 + 48;
		nb /= 10;
		count++;
	}
	write(1, digit + 10 - count, count);
}

/*
#include <stdio.h>
int	main(void)
{
	ft_putnbr(0);
	// ft_putnbr(42);
	// ft_putnbr(-42);
	// ft_putnbr(123);
	// ft_putnbr(2147483647);
	ft_putnbr(-2147483648);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:42:17 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/31 18:42:18 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c);
int	is_valid(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int		length;
	int		num_of_digits;
	long	copy;
	char	result[32];

	length = is_valid(base);
	if (length <= 1)
		return ;
	if (nbr < 0)
		write(1, "-", 1);
	copy = (nbr < 0) * -1 * (long) nbr + (nbr > 0) * (long) nbr;
	num_of_digits = 0;
	while (copy > 0)
	{
		result[31 - num_of_digits] = base[copy % length];
		num_of_digits++;
		copy /= length;
	}
	if (!nbr)
		write(1, base, 1);
	write(1, result + 32 - num_of_digits, num_of_digits);
	return ;
}

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_valid(char *base)
{
	int	length;
	int	i;
	int	j;

	length = 0;
	while (base[length])
		length++;
	i = -1;
	while (++i < length)
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		j = i;
		while (++j < length)
			if (base[i] == base[j])
				return (0);
	}
	return (length);
}

/*
#include <stdio.h>
int	main(void)
{
	ft_putnbr_base(-12, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(12, "01");
	printf("\n");
	ft_putnbr_base(0, "012345678ABCDEF");
	printf("\n");
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(2147483647, "0123456789ABCDEF");
	printf("\n");
}
*/
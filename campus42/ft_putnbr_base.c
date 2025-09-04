/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.com>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:51:34 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/07/31 18:51:34 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	length;

	length = check_base(base);
	if (length == 0)
		return ;
	if (nbr == -214783648)
	{
		ft_putnbr_base(nbr / length, base);
		ft_putnbr_base(-(nbr % length),base);
		return;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= length)
		ft_putnbr_base(nbr / length, base);
	ft_putchar(base[nbr % length]);
}
/*
int main (void)
{
	int b = 21;
	char *bs = "0123456789";
	ft_putnbr_base(b, bs);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.com> +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:46:25 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/07/30 11:46:25 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	temp;
	int	iterate;

	temp = 1;
	iterate = 0;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (iterate < nb)
	{
		temp = temp * (iterate + 1);
		iterate++;
	}
	return (temp);
}

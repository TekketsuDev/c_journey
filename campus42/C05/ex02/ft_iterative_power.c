/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.com>    +#+  +:+       +#     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:48:55 by vjamet-s          #+#    #+#             */
/*   Updated: 2025/07/30 11:48:55 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	resu;

	resu = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	while (power > 0)
	{
		resu = resu * nb;
		power--;
	}
	return (resu);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:07:25 by zvandeven         #+#    #+#             */
/*   Updated: 2023/03/22 15:03:59 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/ft_printf.h"

int	ft_printnbr_pf(unsigned int nbr, unsigned int len, char *base)
{
	unsigned long int	lnbr;
	int					count;

	count = 0;
	lnbr = nbr;
	if (lnbr >= len)
	{
		count = ft_printnbr_pf(lnbr / len, len, base) + 1;
	}
	ft_putchar(base[lnbr % len]);
	return (count);
}

int	ft_putnbr_base_pf(unsigned int nbr, int count, int b)
{
	int		len;
	char	*base;

	len = 0;
	if (b == 1)
		base = "0123456789abcdef";
	if (b == 2)
		base = "0123456789ABCDEF";
	while (base[len] != '\0')
	len ++;
	count = ft_printnbr_pf(nbr, len, base);
	return (count);
}

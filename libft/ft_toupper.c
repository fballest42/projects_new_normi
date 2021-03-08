/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:47:43 by fballest          #+#    #+#             */
/*   Updated: 2021/03/04 11:21:24 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	ch;

	if (c >= 97 && c <= 122)
	{
		c = c - 32;
		ch = c + '\0';
		return (ch);
	}
	return (c);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setprint2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:48:49 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:47:43 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static void	ft_setprintcnullb(t_env *env, int i)
{
	if (env->alig == 0 && env->width > 0)
	{
		while (env->width - 1 - i++)
			ft_putchar(env, ' ');
		env->imp = "";
		ft_putchar(env, env->c);
	}
	else if (env->alig > 0 && env->width > 0)
	{
		env->imp = "";
		ft_putchar(env, env->c);
		while (env->width - 1 - i++)
			ft_putchar(env, ' ');
	}
	if (env->width == 0)
	{
		env->imp = "";
		ft_putchar(env, env->c);
	}
	return ;
}

void	ft_setprintcnull(t_env *env)
{
	int		i;

	i = 0;
	if ((env->type == 'c' || env->type == '%')
		&& (env->c == '\0' || env->c == 0))
	{
		ft_setprintcnullb(env, i);
	}
}

static void	ft_setprint5c(t_env *env, char c, int i, int z)
{
	if (env->len == 0 && env->width > 0)
	{
		while (env->width - i > 0)
			env->imp[i++] = c;
		env->imp[i] = '\0';
		return ;
	}
	if (env->alig == 0 && !(env->len == 0 && env->width > 0))
	{
		if (env->sign > 0 && env->zero > 0 && env->dot == 0)
			env->imp[i++] = '-';
		while (i <= env->width)
			env->imp[i++] = c;
		while (i >= (env->width - env->len) && (env->len - z) >= 0)
			env->imp[--i] = env->impp[env->len - z++];
		env->imp[env->width + 1] = '\0';
		if (env->imp[i] == '-' & env->zero > 0 && env->dot == 0
			&& env->width > env->len)
			env->imp[i] = '0';
		ft_cleanmemory(env->impp);
		return ;
	}
}

static void	ft_setprint5b(t_env *env, int i)
{
	if (env->alig > 0 && env->width > 2)
	{
		ft_putchar(env, env->c);
		while (((env->width - 1) - i) > 0)
		{
			ft_putchar(env, ' ');
			i++;
		}
		env->width = 0;
		i = 0;
		return ;
	}
	else if (env->alig == 0 && env->width > 2)
	{
		while (((env->width - 1) - i) > 0)
		{
			ft_putchar(env, ' ');
			i++;
		}
		ft_putchar(env, env->c);
		env->width = 0;
		i = 0;
	}
	else
		ft_putchar(env, env->c);
}

void	ft_setprint5(t_env *env, char c, int i, int z)
{
	int			j;

	j = 0;
	if (env->zero > 0 && env->alig == 0 && env->dot == 0
		&& (env->type == 'c' || env->type == 's' || env->type == '%'
			|| env->type == 'd' || env->type == 'i' || env->type == 'x'
			|| env->type == 'X' || env->type == 'p' || env->type == 'u'))
		c = '0';
	if (env->type == 'c' && env->c == '\0')
	{
		ft_setprint5b(env, i);
		return ;
	}
	ft_setprint5c(env, c, i, z);
	if (env->alig > 0 && !(env->len == 0 && env->width > 0))
	{
		while (env->impp[z] != '\0')
			env->imp[i++] = env->impp[z++];
		while ((env->width - i) >= 0)
			env->imp[i++] = c;
		env->imp[i - 1] = '\0';
		ft_cleanmemory(env->impp);
		return ;
	}
}

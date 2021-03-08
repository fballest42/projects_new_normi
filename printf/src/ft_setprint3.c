/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setprint3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 09:00:10 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:48:10 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_setprint4(t_env *env)
{
	char		c;
	int			i;
	int			z;

	c = ' ';
	i = 0;
	z = 0;
	env->len = ft_strlenarg(env->impp);
	ft_tempmemory2(env);
	if (env->width <= env->len && env->len > 0)
	{
		while (env->impp[i] != '\0')
		{
			env->imp[i] = env->impp[i];
			i++;
		}
		env->imp[i] = '\0';
		ft_cleanmemory(env->impp);
		return ;
	}
	else if (env->width > env->len)
		ft_setprint5(env, c, i, z);
	else if (env->width == 0 && env->len == 0)
		env->imp = "";
}

void	ft_setprint3b(t_env *env, int i)
{
	if (env->prec == 0 && env->dot > 0)
	{
		env->impp = "";
		ft_setprint4(env);
	}
	else if (env->prec > 0)
	{
		while (env->prec - i > 0)
		{
			env->impp[i] = env->arg[i];
			i++;
		}
		env->impp[i] = '\0';
		ft_cleanmemory(env->arg);
	}
}

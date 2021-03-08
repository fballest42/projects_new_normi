/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:08:57 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:45:17 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static void	ft_setprint3(t_env *env)
{
	int		i;

	i = 0;
	if (((env->prec < env->len && env->dot > 0)
			|| (env->prec == 0 && env->dot > 0))
		&& (env->type == 'c' || env->type == 's' || env->type == '%'))
		ft_setprint3b(env, i);
	else if ((env->prec >= env->len || (env->prec == 0 && env->dot == 0))
		&& (env->type == 'c' || env->type == 's' || env->type == '%'))
	{
		while (env->arg[i] != '\0')
		{
			env->impp[i] = env->arg[i];
			i++;
		}
		env->impp[i] = '\0';
		ft_cleanmemory(env->arg);
	}
	ft_setprint4(env);
}

static void	ft_setprint2b(t_env *env, int i, int j, int z)
{
	if (env->type == 'p')
	{
		env->impp[i++] = '0';
		env->impp[i++] = 'x';
	}
	if (env->sign > 0 && (env->type == 'i' || env->type == 'd'))
		env->impp[i++] = '-';
	while (j < env->prec)
		env->impp[i + j++] = '0';
	while (j >= (env->prec - env->len))
		env->impp[i + j--] = env->arg[env->len - z++];
	env->impp[env->prec + i] = '\0';
	if (env->arg && (env->num != 0))
		ft_cleanmemory(env->arg);
}

static void	ft_setprint2(t_env *env)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	if (env->prec >= env->len && (env->type == 'i' || env->type == 'd'
			|| env->type == 'p' || env->type == 'u' || env->type == 'x'
			|| env->type == 'X'))
	{
		ft_setprint2b(env, i, j, z);
	}
	ft_setprint3(env);
}

static void	ft_setprintb(t_env *env, int i)
{
	if ((env->prec < 0 && env->negp == 0)
		&& (env->type == 'c' || env->type == 's' || env->type == '%'))
	{
		env->prec = env->len;
		while (env->arg[i])
		{
			env->impp[i] = env->arg[i];
			i++;
		}
		env->impp[i] = '\0';
		ft_cleanmemory(env->arg);
	}
	else if (env->prec <= env->len && (env->type == 'd' || env->type == 'i'
			|| env->type == 'u' || env->type == 'x' || env->type == 'X'
			|| env->type == 'p'))
		env->prec = env->len;
}

void	ft_setprint(t_env *env)
{
	int		i;

	i = 0;
	if (env->type == 'c' && env->c == '\0')
	{
		ft_setprintcnull(env);
		return ;
	}
	if (env->prec == 0 && env->type == '%')
		env->prec = 1;
	if (env->dot == 0 && env->prec <= env->len)
		env->prec = env->len;
	else if ((env->prec < 0 || (env->negp > 0 && env->width < (env->prec * -1)))
		&& (env->type == 'd' || env->type == 'i' || env->type == 'u'))
		env->prec = 0;
	else if ((env->prec < 0 || (env->negp > 0 && env->width < (env->prec * -1)))
		&& (env->type == 'c' || env->type == 's' || env->type == '%'))
		env->prec = env->len;
	ft_tempmemory(env);
	ft_setprintb(env, i);
	ft_setprint2(env);
}

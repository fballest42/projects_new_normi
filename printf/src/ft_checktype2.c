/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:29:49 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:34:30 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_setint2(t_env *env, long int nbr)
{
	env->len = ft_nbrlen(nbr);
	env->arg = (char *)malloc(env->len + 1);
	if (!env->arg)
		return ;
}

void	ft_setint(t_env *env, va_list argm)
{
	long int	nbr;
	int			i;

	i = 0;
	nbr = 0;
	nbr = (int)va_arg(argm, int);
	env->num = (int)nbr;
	ft_checknull(env);
	if (nbr == 0 && env->dot > 0 && env->prec == 0)
	{
		env->arg = "";
		return ;
	}
	ft_setint2(env, nbr);
	if (nbr < 0)
	{
		env->sign = 1;
		nbr = nbr * -1;
	}
	while (i <= env->len)
	{
		env->arg[env->len - ++i] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	env->arg[i - 1] = '\0';
}

void	ft_setunsigned2(t_env *env, int i, unsigned int nbr)
{
	if (env->type == 'u')
	{
		nbr = (unsigned int)env->num;
		if (env->num == 0 && env->dot > 0 && env->prec == 0)
		{
			env->arg = "";
			return ;
		}
		env->len = ft_nbrlen((unsigned int)env->num);
		env->arg = (char *)malloc(env->len + 1);
		if (!env->arg)
			return ;
		if (env->num < 0)
		{
			env->sign = 1;
			nbr = env->num * -1;
		}
		while (i <= env->len)
		{
			env->arg[env->len - ++i] = (nbr % 10) + '0';
			nbr = nbr / 10;
		}
		env->arg[i - 1] = '\0';
	}
}

void	ft_setxupperx(t_env *env, char *base, int i)
{
	if (env->type == 'x' || env->type == 'X')
	{
		ft_baseconv(env, (unsigned int)env->num, base);
		if (env->type == 'X')
		{
			while (env->arg[i] != '\0')
			{
				if (env->arg[i] >= 97 && env->arg[i] <= 122)
					env->arg[i] = env->arg[i] - 32;
				i++;
			}
		}
		env->len = ft_strlenarg(env->arg);
	}
}

void	ft_setunsigned(t_env *env, va_list argm)
{
	int			i;
	int			nbr;
	char		*base;

	i = 0;
	nbr = 0;
	base = "0123456789abcdef";
	env->num = va_arg(argm, unsigned int);
	ft_checknull(env);
	if (env->num == 0 && env->dot > 0 && env->prec == 0)
	{
		env->arg = "";
		return ;
	}
	ft_setxupperx(env, base, i);
	ft_setunsigned2(env, i, nbr);
}

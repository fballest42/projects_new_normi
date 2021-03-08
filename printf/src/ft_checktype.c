/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:14:24 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:31:31 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static void	ft_setchar(t_env *env, va_list argm)
{
	if (env->type == 'c')
	{
		env->c = va_arg(argm, int);
		if (env->c == 0 || env->c == '\0')
		{
			free(env->arg);
			env->arg = NULL;
			env->arg = "";
			env->len = 0;
		}
		else
		{
			env->arg[0] = env->c;
			env->arg[1] = '\0';
		}
	}
}

static void	ft_setcharstr2(t_env *env, va_list argm)
{
	if (env->type == 'c' || env->type == '%')
	{
		env->len = 1;
		env->dot = 0;
		if (!env->arg)
		{
			env->arg = (char *)malloc(env->len + 1);
			if (!env->arg)
				return ;
		}
		if (env->type == '%')
		{
			env->arg[0] = '%';
			env->arg[1] = '\0';
		}
		ft_setchar(env, argm);
	}
}

static void	ftsetstr(t_env *env, va_list argm, char *tmp, int i)
{
	if (env->type == 's')
	{
		if (env->prec == 0 && env->dot > 0)
		{
			env->arg = "";
			return ;
		}
		tmp = va_arg(argm, char *);
		if (!tmp)
			tmp = "(null)";
		env->len = ft_strlenarg(tmp);
		env->arg = (char *)malloc(env->len + 1);
		if (!env->arg)
			return ;
		while (tmp[i] != '\0')
		{
			env->arg[i] = tmp[i];
			i++;
		}
		env->arg[i] = '\0';
		tmp = NULL;
	}
}

void	ft_setcharstr(t_env *env, va_list argm)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	ftsetstr(env, argm, tmp, i);
	ft_setcharstr2(env, argm);
}

void	ft_checktype(t_env *env, const char *str, va_list argm)
{
	if (str[env->i] != '\0' && (str[env->i] == 'c' || str[env->i] == 's'
			|| str[env->i] == 'p' || str[env->i] == 'd' || str[env->i] == 'i'
			|| str[env->i] == 'u' || str[env->i] == 'x' || str[env->i] == 'X'
			|| str[env->i] == '%'))
	{
		env->type = str[env->i];
		env->i++;
		if (env->type == 'c' || env->type == 's' || env->type == '%')
			ft_setcharstr(env, argm);
		else if (env->type == 'i' || env->type == 'd')
			ft_setint(env, argm);
		else if (env->type == 'u' || env->type == 'x' || env->type == 'X')
			ft_setunsigned(env, argm);
		else if (env->type == 'p')
			ft_setpointer(env, argm);
		env->len = ft_strlenarg(env->arg);
		return ;
	}
	else
		return ;
}

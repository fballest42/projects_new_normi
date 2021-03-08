/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:49:11 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:28:00 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_printingstr(t_env *env)
{
	size_t		ii;

	ii = 0;
	while (env->imp[ii] != '\0')
	{
		ft_putchar(env, env->imp[ii]);
		ii++;
	}
	if (ii > 0)
		ft_cleanmemory(env->imp);
	return ;
}

static void	ft_setflags2(t_env *env, const char *str, va_list argm)
{
	if (str[env->i] == '.')
	{
		env->dot = env->dot + 1;
		env->i++;
		if (str[env->i] == '-')
		{
			env->negp = 1;
			env->i++;
		}
		if (str[env->i] == '*')
		{
			env->prec = va_arg(argm, int);
			env->i++;
		}
		if (str[env->i] >= '0' && str[env->i] <= '9')
		{
			while (str[env->i] >= '0' && str[env->i] <= '9')
			{
				env->prec = ((env->prec * 10) + (str[env->i] - '0'));
				env->i++;
			}
		}
	}
}

static void	ft_setflagswidth(t_env *env, const char *str, va_list argm)
{
	if (str[env->i] == '*')
	{
		env->width = va_arg(argm, int);
		if (env->width < 0)
		{
			env->alig = 1;
			env->width = env->width * -1;
		}
		env->i++;
	}
	if (str[env->i] >= '0' && str[env->i] <= '9')
	{
		while (str[env->i] >= '0' && str[env->i] <= '9')
		{
			env->width = (env->width * 10) + (str[env->i] - '0');
			env->i++;
		}
	}
}

void	ft_setflags(t_env *env, const char *str, va_list argm)
{
	if (str[env->i] == '-')
	{
		env->alig = 1;
		env->i++;
	}
	if (str[env->i] == '0')
	{
		env->zero = 1;
		env->i++;
	}
	ft_setflagswidth(env, str, argm);
	ft_setflags2(env, str, argm);
}

int	ft_checkflags(t_env *env, const char *str, va_list argm)
{
	while (str[env->i] && (str[env->i] == '-' || str[env->i] == '.' || \
		str[env->i] == '*' || (str[env->i] >= '0' && str[env->i] <= '9')))
	{
		ft_setflags(env, str, argm);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 09:58:26 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:37:55 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	ft_strlenarg(char *arg2)
{
	int		ii;

	ii = 0;
	while (arg2[ii] != '\0')
		ii++;
	return (ii);
}

int	ft_reinit(t_env *env)
{
	env->c = 0;
	env->alig = 0;
	env->zero = 0;
	env->width = 0;
	env->dot = 0;
	env->prec = 0;
	env->len = 0;
	env->num = 0;
	env->negp = 0;
	env->sign = 0;
	env->type = '\0';
	env->arg = NULL;
	env->impp = NULL;
	env->imp = NULL;
	return (1);
}

int	ft_init(t_env *env)
{
	env->c = 0;
	env->zero = 0;
	env->alig = 0;
	env->width = 0;
	env->dot = 0;
	env->prec = 0;
	env->len = 0;
	env->num = 0;
	env->negp = 0;
	env->type = 0;
	env->sign = 0;
	env->arg = NULL;
	env->imp = NULL;
	env->impp = NULL;
	env->ret = 0;
	env->i = 0;
	return (1);
}

static void	ft_read(t_env *env, const char *str, va_list argm)
{
	while (str[env->i] != '\0')
	{
		if (str[env->i] == '%')
		{
			env->i++;
			while (str[env->i] == ' ')
				env->i++;
			if (str[env->i] && ft_checkflags(env, str, argm) > 0)
			{
				ft_checktype(env, str, argm);
				ft_setprint(env);
				ft_printingstr(env);
			}
			ft_reinit(env);
		}
		else
			ft_putchar(env, str[env->i++]);
	}
}

int	ft_printf(const char *str, ...)
{
	t_env		*env;
	va_list		argm;
	int			ret1;

	ret1 = 0;
	env = malloc(sizeof(t_env));
	if (!str || !env || !ft_init(env))
		return (-1);
	va_start(argm, str);
	ft_read(env, str, argm);
	ret1 = env->ret;
	free(env);
	return (ret1);
}

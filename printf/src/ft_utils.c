/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:52:53 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:52:21 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_checknull(t_env *env)
{
	if ((!env->arg) && env->type == 's')
		env->arg = "(null)";
	else if (env->num == '\0'
		&& (env->type == 'd' || env->type == 'i' || env->type == 'u'
			|| env->type == 'x' || env->type == 'X'))
		env->arg = "0";
}

static void	ft_tempmemorys(t_env *env)
{
	if (env->prec < env->len && env->sign > 0
		&& (env->type != 'c' || env->type != 's' || env->type != '%'))
	{
		env->impp = (char *)malloc(env->len + 2);
		if (!env->impp)
			return ;
	}
	else if (env->prec < env->len && (env->type == 'c'
			|| env->type == 's' || env->type == '%'))
	{
		env->impp = (char *)malloc(env->prec + 1);
		if (!env->impp)
			return ;
	}
}

void	ft_tempmemory(t_env *env)
{
	env->impp = NULL;
	if (env->prec >= env->len && env->sign == 0)
	{
		env->impp = (char *)malloc(env->prec + 1);
		if (!env->impp)
			return ;
	}
	else if (env->prec >= env->len && env->sign > 0)
	{
		env->impp = (char *)malloc(env->prec + 2);
		if (!env->impp)
			return ;
	}
	else if (env->prec < env->len && env->sign == 0
		&& (env->type != 'c' || env->type != 's' || env->type != '%'))
	{
		env->impp = (char *)malloc(env->len + 1);
		if (!env->impp)
			return ;
	}
	ft_tempmemorys(env);
}

void	ft_tempmemory2(t_env *env)
{
	int			i;

	i = 1;
	env->imp = NULL;
	if (env->width > env->len)
	{
		if (env->sign > 0)
			i = 2;
		env->imp = (char *)malloc(env->width + i);
		if (!env->imp)
			return ;
	}
	else if (env->width <= env->len && env->len > 0)
	{
		env->imp = (char *)malloc(env->len + 1);
		if (!env->imp)
			return ;
	}
	else
		return ;
}

void	ft_cleanmemory(char *str)
{
	int			i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			str[i++] = 0;
		free(str);
		str = NULL;
	}
}

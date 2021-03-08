/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:51:33 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:36:30 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_putchar(t_env *env, char c)
{
	write(1, &c, 1);
	env->ret++;
}

int	ft_nbrlen(long long num)
{
	int		ii;

	ii = 0;
	if (num == 0)
		return (ii + 1);
	if (num < 0)
		num = num * -1;
	while (num > 0)
	{
		ii++;
		num = num / 10;
	}
	return (ii);
}

void	ft_baseconv(t_env *env, long long int nb, char *base)
{
	int						i;
	int						j;
	char					c;
	long long int			lb;

	i = 0;
	j = 0;
	lb = ft_strlenarg(base);
	env->arg = (char *)malloc(lb + 1);
	if (!env->arg)
		return ;
	while (nb >= lb)
	{
		env->arg[i++] = base[nb % lb];
		nb = nb / lb;
	}
	env->arg[i] = base[nb];
	while (j <= (i / 2) && env->arg[i] != '\0')
	{
		c = env->arg[i - j];
		env->arg[i - j] = env->arg[j];
		env->arg[j] = c;
		j++;
	}
	env->arg[i + 1] = '\0';
}

void	ft_baseconvp(t_env *env, unsigned long int nb, char *base)
{
	int						i;
	int						j;
	char					c;
	unsigned long int		lb;

	i = 0;
	j = 0;
	lb = ft_strlenarg(base);
	env->arg = (char *)malloc(lb + 1);
	if (!env->arg)
		return ;
	while (nb >= lb)
	{
		env->arg[i++] = base[nb % lb];
		nb = nb / lb;
	}
	env->arg[i] = base[nb];
	while (j <= (i / 2) && env->arg[i] != '\0')
	{
		c = env->arg[i - j];
		env->arg[i - j] = env->arg[j];
		env->arg[j] = c;
		j++;
	}
	env->arg[i + 1] = '\0';
}

void	ft_setpointer(t_env *env, va_list argm)
{
	char				*base;
	long long int		num;

	base = "0123456789abcdef";
	num = (unsigned long int)va_arg(argm, unsigned long int);
	env->num = (unsigned long int)num;
	ft_checknull(env);
	if ((unsigned long int)num == 0 && env->dot > 0 && env->prec == 0)
	{
		env->arg = "";
		return ;
	}
	else if (env->num == '\0' && env->type == 'p')
	{
		env->arg = "0";
		return ;
	}
	else
		ft_baseconvp(env, (unsigned long int)num, base);
}

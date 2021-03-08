/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:05:50 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:53:21 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_env
{
	int				zero;
	int				alig;
	char			c;
	int				width;
	int				dot;
	int				prec;
	int				flag;
	int				len;
	char			type;
	int				sign;
	long long int	num;
	int				negp;
	char			*arg;
	char			*imp;
	char			*impp;
	int				ret;
	int				i;
	int				j;
}				t_env;

int				ft_printf(const char *str, ...);
int				ft_init(t_env *env);
int				ft_reinit(t_env *env);
int				ft_checkflags(t_env *env, const char *str, va_list argm);
void			ft_setflags(t_env *env, const char *str, va_list argm);
void			ft_checktype(t_env *env, const char *str, va_list argm);
void			ft_setunsigned(t_env *env, va_list argm);
void			ft_setxupperx(t_env *env, char *base, int i);
void			ft_setunsigned2(t_env *env, int i, unsigned int nbr);
void			ft_setint(t_env *env, va_list argm);
void			ft_setcharstr(t_env *env, va_list argm);
void			ft_setpointer(t_env *env, va_list argm);
void			ft_setprint(t_env *env);
void			ft_setprintcnull(t_env *env);
void			ft_setprint5(t_env *env, char c, int i, int z);
void			ft_setprint3b(t_env *env, int i);
void			ft_setprint4(t_env *env);
void			ft_tempmemory(t_env *env);
void			ft_tempmemory2(t_env *env);
void			ft_checknull(t_env *env);
void			ft_baseconv(t_env *env, long long int nb, char *base);
void			ft_baseconvp(t_env *env, unsigned long int nb, char *base);
int				ft_nbrlen(long long num);
int				ft_strlenarg(char *arg2);
void			ft_putchar(t_env *env, char c);
void			ft_printingstr(t_env *env);
void			ft_cleanmemory(char *str);

#endif

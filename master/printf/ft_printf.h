/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:53:55 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/22 22:33:25 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	cases(const char *str, int i, va_list args);
int	printchar(int c);
int	printint(int n, int ct);
int	printuint(unsigned int n, int ct);
int	printhex(unsigned int n, int ct);
int	printhexu(unsigned int n, int ct);
int	printaddr(unsigned long long int n, int ct);
int	printstr(char *chr);
#endif
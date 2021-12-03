/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:44:47 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/22 22:30:22 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	cases(const char *str, int i, va_list args)
{
	int	ct;

	ct = 0;
	if (str[i] == 'c')
		ct = printchar(va_arg(args, int));
	else if (str[i] == 's')
		ct = printstr(va_arg(args, char *));
	else if (str[i] == 'p')
		ct = printaddr(va_arg(args, unsigned long long int), 0);
	else if (str[i] == 'd' || str[i] == 'i')
		ct = printint(va_arg(args, int), 0);
	else if (str[i] == 'u')
		ct = printuint(va_arg(args, int), 0);
	else if (str[i] == 'x')
		ct = printhex(va_arg(args, int), 0);
	else if (str[i] == 'X')
		ct = printhexu(va_arg(args, int), 0);
	else if (str[i] == '%')
		ct = write(1, "%", 1);
	return (ct);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	va_start(args, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += cases(str, i + 1, args);
			i++;
		}
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (ret);
}

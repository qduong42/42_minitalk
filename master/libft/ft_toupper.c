/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:34:39 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/22 21:40:54 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*These functions convert lowercase letters to uppercase, and vice versa
*/
int	ft_toupper(int c)
{
	if (c > 96 && c <= 122)
		return (c - 32);
	else
		return (c);
}

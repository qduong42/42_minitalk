/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:09:38 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/28 23:58:32 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	takes server PID and sends received string to PID
*/

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

/*
	Main
*/

int	main(int argv, char **args)
{
	int	i;
	int	pid;
	/*
	args[1][0] - pointer to received PID 
	args[2][0] - pointer to received string
	*/
	pid = ft_atoi(args[1]);
	while (1)
	{
		kill(pid, SIGUSR2);
	}
	return (0);
}
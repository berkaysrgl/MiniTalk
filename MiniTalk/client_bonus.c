/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:29:44 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/14 17:08:43 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "unistd.h"

int	ft_printf(const char *str, ...);

int	my_atoi(char *str)
{
	int	number;

	number = 0;
	while (*str)
	{
		number = (10 * number) + (*str - 48);
		str++;
	}
	return (number);
}

void	msg_client(int x)
{
	static int	i = 0;

	if (i == 0 && x == SIGUSR2)
	{
		i++;
		ft_printf("Success!\n");
	}
}

void	bitshift(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 7;
		c = *str;
		while (i >= 0)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			signal(SIGUSR2, msg_client);
			usleep(100);
			i--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("You should write 3 arguments!");
		return (0);
	}
	bitshift(my_atoi(argv[1]), argv[2]);
	bitshift(my_atoi(argv[1]), "\n");
	return (0);
}

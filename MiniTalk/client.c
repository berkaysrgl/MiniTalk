/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:31:53 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/14 16:18:20 by bsarigul         ###   ########.fr       */
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

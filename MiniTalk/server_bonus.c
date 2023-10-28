/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:36:23 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/14 17:07:24 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);

void	signal_handler(int signal, siginfo_t *sig, void *cnt)
{
	static int				bit = 7;
	static unsigned char	set;

	(void)cnt;
	if (signal == SIGUSR1)
		set += (1 << bit);
	if (bit == 0)
	{
		ft_printf("%c", set);
		bit = 7;
		set = 0;
		kill(sig->si_pid, SIGUSR2);
	}
	else
		bit--;
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = signal_handler;
	ft_printf("pid: %d\n", getpid());
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		ft_printf("error!");
	while (1)
	{
		pause();
	}
}

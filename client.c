#include "../printf_git/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int	ft_atoi(const char *nptr);

void	handler(int pid, char msg)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((msg & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}
int main(int argc, char **argv)
{
    int     pid;
    char    *msg;
    int     i;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        msg = argv[2];
        while (msg[i] != '\0')
        {
            handler(pid, msg[i]);
            i++;
        }
        handler(pid,'\n');
    }
    else
        ft_printf("program need 2 arguments to work");
    return (0);
}

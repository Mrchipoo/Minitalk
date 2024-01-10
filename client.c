#include "../printf_git/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int	ft_atoi(const char *nptr);

void handler(int pid, int harf)
{
    while(harf != 0)
    {
        if (harf % 2 == 1)
            kill(pid,SIGUSR2);
        else
            kill(pid,SIGUSR1);
        harf =  harf / 2;
        usleep(400);
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
        // handler(pid,'\n');
    }
    else
        ft_printf("program need 2 arguments to work");
    return (0);
}
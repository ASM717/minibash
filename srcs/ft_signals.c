#include "../minishell.h"

void	ft_signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		if (waitpid(-1, NULL, WNOHANG) == -1)
		{
			g_status = 130;
			rl_on_new_line();
			rl_redisplay();
			printf("  \n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		else
		{
			g_status = 130;
			printf("\n");
		}
	}
}

void	ft_signal_quit_handler(int signal)
{
	if (signal == SIGQUIT)
	{
		if (waitpid(-1, NULL, WNOHANG) == -1)
		{
			rl_on_new_line();
			rl_redisplay();
			printf("  \b\b");
		}
		else
		{
			g_status = 131;
			printf("Quit: 3\n");
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
pid_t pid;

/*programa que temporiza la ejecución de un proceso hijo */
void hand(int signum){
	//algo X
	if(signum == SIGALRM)
		kill(pid,SIGKILL);
}

int main(int argc, char **argv)
{
	char **argumentos = &argv[1];
	
	pid = fork();

	if(pid==0){
		if(execvp(argv[1],argumentos)== -1){
			perror("Fallo al crear la ejecucion");
		}
	}
	else{
		struct sigaction sa;
		sa.sa_handler = hand;
		
		signal(SIGINT,SIG_IGN);

		if(sigaction(SIGALRM ,&sa, NULL)==-1){
			exit(EXIT_FAILURE);
		}

		alarm(5);

		int status;
		pid_t o = waitpid(pid,&status,WUNTRACED);
	

		if (WIFEXITED(status))
		{
            	printf("child exited, status=%d\n", WEXITSTATUS(status));

        	} else if (WIFSIGNALED(status)) {
            	printf("child killed (signal %d)\n", WTERMSIG(status));

		} else if (WIFSTOPPED(status)) {
            	printf("child stopped (signal %d)\n", WSTOPSIG(status));
		}
	}
	return 0;
}

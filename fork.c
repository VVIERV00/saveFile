#include <stdio.h> //
#include <unistd.h>//
#include <sys/types.h>//
#include <sys/wait.h>//
#include <stdlib.h>//
#include <signal.h>
void funcion();
int main(void) {
  signal(SIGINT, &funcion);
 // sigaction (SIGINT, &funcion, NULL);
  int pid = fork();
  if (pid==0){
    sleep(4);
    printf("[H] ppid = %5d, pid = %5d\n", getppid(), getpid());	
    exit(33);
 } else{
    printf("[P] ppid = %5d, pid = %5d, H = %5d\n", getppid(), getpid(), pid);
    int stat;
    
    int lol;
    pid_t status;
    lol = waitpid(pid, &status, 0);
    stat = WEXITSTATUS(status);
    //lol = wait(&status);
    printf("El resultado de la macro es: %d \n", stat);

    printf("[P] el proceso pid=%5d acaba de terminar con estado %5d \n", 
lol, status); 		
 } return 0;
}
void funcion(){
	printf("Soy una senial \n");
}

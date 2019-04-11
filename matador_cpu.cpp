// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa matatdor.cpp


#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()
#include <sched.h>  // Biblioteca para uso do cpu_set



int  main()
{
  // o processo que vai matar

  int meu_pid;
  int pid_vitima, resposta;

  meu_pid = getpid();
    
  
 printf( "Eu sou um programa matador de programa meu PID é %d\n", meu_pid );
 printf( "Digite o PID do processo \n");
 scanf( "%d", &pid_vitima);
 printf( "O que deseja fazer ? \n");
 printf( "1 - Matar \n");
 printf( "2 - Parar \n");
 printf( "3 - Continuar \n");
 printf( "4 - Alocar CPU \n");
 scanf( "%d", &resposta);
  
 switch(resposta){

 case 1: 
 	printf("\n Vou matar o processo %d \n", pid_vitima);
 	kill(pid_vitima, SIGKILL);
 	printf( "\nAgora posso morrer tranquilo.\n");
	break;
 case 2: 
	printf("\n Vou parar o processo %d \n", pid_vitima);
 	kill(pid_vitima, SIGSTOP);
 	printf( "\n Processp parado\n");
	break;
 case 3:
        printf("\n Vou Continuar o processo %d \n", pid_vitima);
 	kill(pid_vitima, SIGCONT);
 	printf( "\n Executando...\n");
	break;
 case 4:
	int n_cpu;
        printf("\n Vou alocar a CPU  %d \n", pid_vitima);
        printf("\n Mas qual CPU vc quer o processo rode? Escolha '0' ou '1' \n");
	scanf("%d",&n_cpu);
 	//kill(pid_vitima, SIGCONT);

 	printf( "\n Executando...\n");
 	cpu_set_t cpu;
	CPU_ZERO(&cpu);
	CPU_SET(n_cpu, &cpu);
	sched_setaffinity (pid_vitima, sizeof(cpu_set_t), &cpu);
	break;
}


 exit(0);

}







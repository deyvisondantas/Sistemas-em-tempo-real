// UFRN-CT-DCA
// Disciplina: Sistemas em Tempo Real
// Programa matatdor.cpp
// 2019.1

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 


int  main()
{
  // o processo que vai matar

  int meu_pid;
  int pid_vitima, resposta; 

  meu_pid = getpid();  // Buscando o PID do processo
    
  
 printf( "Eu sou um programa matador de programa meu PID é %d\n", meu_pid );
 printf( "Digite o PID do processo \n");
 scanf( "%d", &pid_vitima);
 printf( "O que deseja fazer ? \n");
 printf( "1 - Matar \n");
 printf( "2 - Parar \n");
 printf( "3 - Continuar \n");
 scanf( "%d", &resposta);
  
 switch(resposta){

 case 1: 
 	printf("\n Vou matar o processo %d \n", pid_vitima);
 	kill(pid_vitima, SIGKILL);                     // Mantando o processo com o sinal SIGKILL
 	printf( "\nAgora posso morrer tranquilo.\n");
	break;
 case 2: 
	printf("\n Vou parar o processo %d \n", pid_vitima);
 	kill(pid_vitima, SIGSTOP);			// Parando o processo com o sinal SIGSTOP
 	printf( "\n Processp parado\n");
	break;
 case 3:
        printf("\n Vou Continuar o processo %d \n", pid_vitima);
 	kill(pid_vitima, SIGCONT);			// Dando continuidade ao processo com o sinal SIGCONT
 	printf( "\n Executando...\n");
	break;
}


 exit(0);

}







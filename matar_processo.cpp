
// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: Matar processo
// 2019.1


#include <iostream>
#include <sys/types.h>
#include <unistd.h>	
#include <stdio.h>
#include <stdlib.h>
#include <string>   // biblioteca string 

using namespace std;

int main ()
{ 
  string Nprocesso;       //String que vai receber o numero do processo
  string comando_matar;  //String que terá o comando para matar o processo
 
  cout << "Digite o numero do processo!" <<endl;
  getline(cin, Nprocesso);   // Lendo o numero usando a função getline da biblioteca <string>
  cout << "Numero do processo: " << Nprocesso << endl;

  //" kill - 9 " eh o comando que mata processos
  comando_matar = "kill -9 ";		// Atribuindo o comando a variável string
    
  comando_matar += string(Nprocesso);   // Concatenando as duas strings: "kill -9" + "o numero do processo" = kill -9 Nprocesso
   
  //cout << " Comando matar: " << comando_matar; 
  
  system(comando_matar.c_str());        // Passando o comando para ser executado no sistema
                                        // Uso da funcao "c_str()", que retorna o 'comando' para o system() 
  
  cout << "O processo " << Nprocesso << " foi morto . Verifique com o comando 'ps aux'" << endl;
  
    
  exit (0);

}

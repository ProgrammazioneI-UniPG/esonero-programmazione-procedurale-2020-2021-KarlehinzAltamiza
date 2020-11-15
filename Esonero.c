#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[]) {
  int b=0; //usato per la generazione di numero randomico
  char frase_random[128]; //frase generata casualmente
  char Plaintext_M[128];
  char Chiave_K[1000]; //frase inserita dall'utente manualmente
  char Frase_cifrata[128]; //frase XOR
  char Frase_cifrata2[128]; //serve per far ritornare da frase convertita in XOR a Plaintext_M
  int cont=0; //contatore
  int cont2; //2° contatore
  int scelta;
  time_t t;

  srand((unsigned) time(&t));
  printf("Inserisci una stringa con un massimo di 5 caratteri\n");
  fgets(Plaintext_M,129,stdin); //ho inserito 129 perche cosi conti 128 caratteri
  cont=strlen(Plaintext_M); //conta la lunchezza della stringa
  printf("Hai inserito un totale di %d caratteri\n", cont);
  printf("RISULTATO FINALE:");
  puts(Plaintext_M);
  printf("MENU!\n");
  printf("****************************\n");
  printf("tasto 1: creare la chiave K, per cifrare il testo M\n");
  printf("tasto 2:generare randomicamente una chiave k\n");
  printf("****************************\n");
  do {
    printf("inserisci un numero tra 1 e 2\n");
    scanf("%d",&scelta);
    switch (scelta){
      case 1: printf("HA SCELTO L'OPZIONE 1\n");
              do {
                printf("inserisca una stringa uguale o superiore a %d\n",cont);
                scanf("%s",Chiave_K);
                cont2=strlen(Chiave_K); //conta la lunghezza
                printf("Hai inserito una stringa con un tot di:%d\n",cont2);
                if (cont2 >=cont) {
                  for (int i=0;i<cont;i++) { //mediante il cilclo svolge opera lo XOR
                    Frase_cifrata[i]=Plaintext_M[i] ^ Chiave_K[i];
                  }
                  printf("La frase cifrata con XOR e: %s\n",Frase_cifrata);
                  for (int i=0;i<cont;i++) { 
                    Frase_cifrata2[i]=Frase_cifrata[i] ^ Chiave_K[i];
                  }
                  printf("La frase cifrata con XOR e ritornata a: %s\n",Frase_cifrata2);
                }
                if (cont2 < cont) {
                  printf("Inserisca una stringa più larga,riprova\n");
                }
              } while(cont2 < cont);
      break;
      case 2:printf("Ha Scelto l'opzione 2\n");
             for (int i=0;i<cont;i++) {
             b=32+rand() % 95+1;
             frase_random[i]=b;
             b=0;
            }
            printf("e stato creato la frase: %s\n",frase_random);
              for (int i=0;i<cont;i++) {
                Frase_cifrata[i]=Plaintext_M[i] ^ frase_random[i];
              }
              printf("La frase cifrata con XOR e: %s\n",Frase_cifrata);
              for (int i=0;i<cont;i++) {
                Frase_cifrata2[i]=Frase_cifrata[i] ^ frase_random[i];
              }
              printf("La frase cifrata con XOR e ritornata a: %s\n",Frase_cifrata2);
      break;
      }
  } while(scelta != 1 && scelta != 2);

return 0;

#include <stdio.h>
#include <locale.h>
#include <string.h>

#define QUANTIA_PROFESSORES 3
#define QUANTIA_DISCIPLINAS 2

struct aluno {
    char nome[50];
    int idade;
    int matricula;
    int disciplina;
};

struct disciplina {
    char nome[50];
    int codigo;
    int carga_horaria;
    char professor_responsavel[50];
};

struct professor {
    char nome[50];
    int funcional;
    int titulacao;
};

void ordena_idade(struct aluno aluno[], int QUANTIA_ESTUDANTES);
int le_valida_idade(int i, struct aluno aluno[]);
int main() {
    struct disciplina disciplinas[QUANTIA_DISCIPLINAS];
    struct professor professores[QUANTIA_PROFESSORES];
    setlocale(LC_ALL, "Portuguese");
    int QUANTIA_ESTUDANTES;
    int professor_responsavel;
    int disciplina_A=0, disciplina_B=0;
    int escolha_disciplina;
    for(int i=0;i<QUANTIA_PROFESSORES;i++){
      printf("digite o nome do %dº professor:\n",i+1);
      scanf(" %s",professores[i].nome);

        printf("digite a funcional do %dº professor:\n",i+1);
      scanf(" %d",&professores[i].funcional);
    do{
                printf("digite a titulacao do %d° professor:\nEspecialista - 1\nMestre - 2\nDoutor - 3\n",i+1);
      scanf(" %d",&professores[i].titulacao);
    }while(professores[i].titulacao<1||professores[i].titulacao>3);
    }

  for(int i=0;i<QUANTIA_DISCIPLINAS;i++){

    printf("digite o nome da %dª disciplina:\n",i+1);
    scanf(" %s",disciplinas[i].nome);

        printf("digite o código da %dª disciplina:\n",i+1);
    scanf("%d",&disciplinas[i].codigo);

    printf("digite a carga horária da %dª disciplina:\n",i+1);
    scanf("%d",&disciplinas[i].carga_horaria);

    do{
    printf("digite o professor da %dª disciplina:\n1º%s,2°%s,3°%s\n",i+1,professores[0].nome,professores[1].nome,professores[2].nome);
    scanf(" %d",&professor_responsavel);
    }while(professor_responsavel<1||professor_responsavel>3);

    if(professor_responsavel==1){
    strcpy(disciplinas[i].professor_responsavel, professores[0].nome);
     }

      if(professor_responsavel==2){
    strcpy(disciplinas[i].professor_responsavel, professores[1].nome);
     }

        if(professor_responsavel==3){
    strcpy(disciplinas[i].professor_responsavel, professores[2].nome);
     }


    
  }



    do{
    printf("digite o número de estudantes:\n");
    scanf("%d",&QUANTIA_ESTUDANTES);}while(QUANTIA_ESTUDANTES<0||QUANTIA_ESTUDANTES>15);
    struct aluno estudantes[QUANTIA_ESTUDANTES];

    

    for (int i = 0; i < QUANTIA_ESTUDANTES; i++) {
        printf("Informe o nome do %dº estudante\n", i + 1);
        scanf("%s", estudantes[i].nome);
      do{
    printf("digite a disciplina do aluno:\n1º%s,2°%s\n",disciplinas[0].nome,disciplinas[1].nome);
      
      scanf("%d",&escolha_disciplina);
      }while((escolha_disciplina<1||escolha_disciplina>2)&&disciplina_A<11&&disciplina_B<11);
      if(escolha_disciplina==1){
        estudantes[i].disciplina=escolha_disciplina;
        disciplina_A++;
      }

      if(escolha_disciplina==2){
        estudantes[i].disciplina=escolha_disciplina;
        disciplina_B++;
      }
        le_valida_idade(i, estudantes);
    }

    ordena_idade(estudantes, QUANTIA_ESTUDANTES);

    printf("\nPrimeiro relatorio\nCódigo|Professor|Nome|Idade\n");
    for(int i=0;i<QUANTIA_ESTUDANTES;i++){
    

    if(estudantes[i].disciplina==1){
        printf("%d|%s|%s|%d\n",disciplinas[0].codigo,disciplinas[0].professor_responsavel, estudantes[i].nome,estudantes[i].idade);
      
    }
      
    }
      printf("\n");
      printf("\nSegundo relatorio\nCódigo|Professor|Nome|Idade\n");
    for(int i=QUANTIA_ESTUDANTES-1;i>=0;i--){
    

    if(estudantes[i].disciplina==2){
        printf("%d|%s|%s|%d\n",disciplinas[1].codigo,disciplinas[1].professor_responsavel, estudantes[i].nome,estudantes[i].idade);

      
    }





      
    }












  

    return 0;
}


void ordena_idade(struct aluno aluno[], int QUANTIA_ESTUDANTES) {
    char onome[50];
    int amatricula;
    int adisciplina;
    for (int i = 0; i < QUANTIA_ESTUDANTES - 1; i++) {
        for (int j = 0; j < QUANTIA_ESTUDANTES - i - 1; j++) {
            if (aluno[j].idade > aluno[j + 1].idade) {
                int temp = aluno[j].idade;
                aluno[j].idade = aluno[j + 1].idade;
                aluno[j + 1].idade = temp;

                strcpy(onome, aluno[j].nome);
                strcpy(aluno[j].nome, aluno[j + 1].nome);
                strcpy(aluno[j + 1].nome, onome);

                amatricula = aluno[j].matricula;
                aluno[j].matricula = aluno[j + 1].matricula;
                aluno[j + 1].matricula = amatricula;

                adisciplina = aluno[j].disciplina;
                aluno[j].disciplina = aluno[j + 1].disciplina;
                aluno[j + 1].disciplina = adisciplina;
            }
        }
    }
}

int le_valida_idade(int i, struct aluno aluno[]){
   
    do{
    printf("Informe a idade do %dº estudante\n", i + 1);
    scanf("%d",&aluno[i].idade);
    }while(aluno[i].idade<16||aluno[i].idade>26);
    return 0;
    }
    

  
  

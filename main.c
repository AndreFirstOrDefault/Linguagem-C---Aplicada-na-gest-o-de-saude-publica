#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

char nome[50], cpf[14],  tel[14], endereco[100], bairro[40], cidade[20], estado[2], cep[9], numero[6], email[35], comorb[100];
int idade;

FILE *ficha;
FILE *grupo;

typedef struct{

   int dia;
   int mes;
   int ano;

}Data;

Data data1, data2 ,data3;

int cadastro(){
     printf("Inicie o cadastro de pacientes: ");
     fflush(stdin);
     printf("\n\nNome: " );
     scanf("%50[^\n]s", &nome);
     fflush(stdin);
     verificaCpf();
}

acesso(){
      char user[6];  // #C35b8
      int pas;      //  298118

        printf("Digite seus dados de acesso: \n\n");
        printf("Usuario: ");
        scanf("%s", &user);
        fflush(stdin);
        printf("Senha: ");
        scanf("%d", &pas);
        fflush(stdin);
     if(user[0]!= '#'|| user[1]!= 'C'|| user[2]!= '3'|| user[3]!= '5'||user[4]!= 'b'|| user[5]!= '8'|| pas!= 298118){
        system("cls");
        printf("\nOs dados estao incorretos!!!");
        printf("\n\nVerifique os dados com o administrador do sistema ou com sua chefia imediata!\n\n");
        acesso();
        getchar();
        }
    else{
        system("cls");
        cadastro();
         }
}
verificaCpf(){
    int i=0, icpf[11], soma=0, s=0, cpf1=0, cpf2=0, dig1=0, dig2=0, cond=0;
         printf("\nCPF: ");
         scanf("%s", &cpf);
         fflush(stdin);
         cond=strlen(cpf);
    for(i=0;i<cond;i++){
        if(cpf[i]!= '.' && cpf[i]!= '-'){
            icpf[s]=cpf[i]-48;
            s++;
            }
}
     //digito 1
    for(i=0;i<9;i++){
        soma+=icpf[i]*(10-i);
    }
        cpf1=soma%11;

    if(cpf1==0 || cpf1==1 ){
        dig1=0;

        }else{
            dig1=11-cpf1;
        }
        //digito 2
    soma=0;
    for(i=0;i<10;i++){
        soma+=icpf[i]*(11-i);
        }
        cpf2=soma%11;

    if(cpf2==0 || cpf2==1){
        dig2=0;
        }else{
            dig2=11-cpf2;
        }
    if(icpf[0]==icpf[1] && icpf[0]==icpf[2] && icpf[0]==icpf[3] && icpf[0]==icpf[4] && icpf[0]==icpf[5] && icpf[0]==icpf[6] && icpf[0]==icpf[7] &&
        icpf[0]==icpf[8] && icpf[0]==icpf[9] && icpf[0]==icpf[10]){

        printf("\n--------------- CPF invalido!!! Digite novamente!!! ---------------\n");
        verificaCpf();
    }if(icpf[9]==dig1 && icpf[10]==dig2){
        cadastroTel();
        }else{
            printf("\n\n--------------- CPF invalido!!! Digite novamente!!! ---------------\n");
            verificaCpf();
            }
}

cadastroTel(){
    printf("\nTelefone(ex:(11)2222-3333): ");
    system ("break");
    scanf("%s", &tel);
if(isdigit(tel[1]) && isdigit(tel[2]) && isdigit(tel[4]) && isdigit(tel[5]) && isdigit(tel[6]) && isdigit(tel[7]) && isdigit(tel[10]) && isdigit(tel[11])
&& isdigit(tel[12]) && tel[0]=='(' && tel[3]==')' && tel[8]=='-' || tel[9]=='-'){
    if(tel[1]==0 || tel[2]==0 && tel[1]=='2' && tel[2]=='3' || tel[1]=='2' && tel[2]=='5' || tel[1]=='2' && tel[2]=='6' ||  tel[1]=='2' && tel[2]=='9' ||
     tel[1]=='3' && tel[2]=='6'|| tel[1]=='3' && tel[2]=='9' || tel[1]=='5' && tel[2]=='2' || tel[1]=='5' && tel[2]=='6' || tel[1]=='5' && tel[2]=='7' ||
     tel[1]=='5' && tel[2]=='8' || tel[1]=='5' && tel[2]=='9' || tel[1]=='7' && tel[2]=='2' || tel[1]=='7' && tel[2]=='6' || tel[1]=='7' && tel[2]=='8')
     {
   printf("\n--------------- Tel Invalido!!! Digite novamente ---------------\n");
   cadastroTel();
        }else {
            cadastroEnd1();
			}
            }else {
                printf("\n--------------- Tel Invalido!!! Digite novamente ---------------\n");
                cadastroTel();
}
}
cadastroEnd1(){
    printf("\nEndereco(Rua,Av.,etc): ");
    fflush(stdin);
    scanf("%100[^\n]s", &endereco);
    fflush(stdin);
    printf("Numero: ");
    scanf("%s", &numero);
    fflush(stdin);

if(numero[0]<'0' || numero[0]>'9'){
    printf("\n--------------- Numero Invalido!!! Digite alguns dados novamente!!! ---------------\n");
        cadastroEnd1();
        } else{
            cadastroEnd2();
        }
}
cadastroEnd2(){
    printf("Bairro: ");
    scanf("%s", &bairro);
    fflush(stdin);
    printf("Cidade: ");
    scanf("%20[^\n]s", &cidade);
    fflush(stdin);
    printf("Estado(sigla em maiusculo): ");
    scanf("%s", &estado);
    fflush(stdin);

if(estado[0] =='A' && estado[1] == 'C' || estado[0] =='A' && estado[1]=='L' || estado[0]== 'A' && estado[1]== 'P' || estado[0]== 'A' && estado[1]== 'M'
	|| estado[0]=='B' && estado[1]=='A' || estado[0]=='C' && estado[1]=='E' || estado[0]=='D' && estado[1]=='F' || estado[0]=='E' && estado[1]=='S' ||
	estado[0]=='G' && estado[1]=='O' || estado[0]=='M' && estado[1]=='A' || estado[0]=='M' && estado[1]=='T' || estado[0]=='M' && estado[1]=='S' ||
	estado[0]=='M' && estado[1]=='G' || estado[0]=='P' && estado[1]=='A' || estado[0]=='P' && estado[1]=='B' || estado[0]=='P' && estado[1]=='R' ||
	estado[0]=='P' && estado[1]=='E' || estado[0]=='P' && estado[1]=='I' || estado[0]=='R' && estado[1]=='J' || estado[0]=='R' && estado[1]=='N' ||
	estado[0]=='R' && estado[1]=='S' || estado[0]=='R' && estado[1]=='O' || estado[0]=='R' && estado[1]=='R' || estado[0]=='S' && estado[1]=='C' ||
	estado[0]=='S' && estado[1]=='P' || estado[0]=='S' && estado[1]=='E' || estado[0]=='T' && estado[1]=='O'){
verificaCep();
	}else {
        printf("\n--------------- Estado invalido (digitar a sigla em maiusculo)!!! Digite alguns dados novamente!!! ---------------\n");
        cadastroEnd2();
	}
}
verificaCep(){
    printf("Cep (com -): ");
    scanf("%s", &cep);
    fflush(stdin);

if(isdigit(cep[0]) && isdigit(cep[1]) && isdigit(cep[2]) && isdigit(cep[3]) && isdigit(cep[4]) && isdigit(cep[6]) &&
   isdigit(cep[7]) && isdigit(cep[8])&& cep[5]=='-' ){
    vdataN();
    }else {
        printf("\n--------------- Cep INVALIDO!!! Digite novamente! ---------------\n");
        verificaCep();
    }
}

vdataN(){

    printf("\nData de nascimento (ex: DD/MM/AAAA): ");
	scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
	fflush(stdin);

	if(data1.ano < 1900 || data1.mes > 12 || data1.mes < 1 || data1.dia > 31 || data1.ano > 2022 && data1.mes >=11){
		printf("\n---------------1 Data invalida! Digite novamente! ---------------\n");
        vdataN();

        }else if( data1.ano == 1900 && data1.ano % 400 != 0 && data1.mes == 2 && data1.dia > 28){
            printf("\n----------------2 Data invalida! Digite novamente! ---------------\n");
            vdataN();

            }else if(data1.dia > 30 && data1.mes == 4 || data1.dia > 30 && data1.mes == 6 || data1.dia > 30 && data1.mes ==9 || data1.dia > 30 &&
                     data1.mes == 11){
                printf("\n---------------3 Data invalida! Digite novamente! ---------------\n");
                vdataN();

                }else if(data1.mes == 2 && data1.dia > 29){
                    printf("\n---------------4 Data invalida! Digite novamente! ---------------\n");
                    vdataN();

                    }else{
                            verificaEmail();
    }
}

verificaEmail(){

printf("Email: ");
scanf("%s", &email);

if(email[5]=='@' || email[6]=='@' || email[7]=='@' || email[8]=='@' || email[9]=='@' || email[10]=='@' || email[11]=='@' || email[12]=='@' ||
email[31]=='@' || email[14]=='@' || email[15]=='@' || email[16]=='@' || email[17]=='@' || email[18]=='@' || email[19]=='@' || email[20]=='@' ||
email[21]=='@' || email[22]=='@' || email[23]=='@' || email[24]=='@' || email[25]=='@' ){
    vdataD();
	}else{
		printf("\n--------------- Email INVALIDO!!! Digite novamente! ---------------\n");
        verificaEmail();
	}
}

vdataD(){
    printf("Data do diagnostico (ex: DD/MM/AAAA): ");
	scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);
	fflush(stdin);

		if(data2.ano < 2020 || data2.mes > 12 || data2.mes < 1 || data2.dia > 31 || data2.ano > 2022 && data2.mes >=11){
		printf("\n--------------- Data invalida! Digite novamente! ---------------\n");
        vdataD();

        }else if(data2.ano % 4 != 0 && data2.mes == 2 && data2.dia > 29){
            printf("\n---------------- Data invalida! Digite novamente! ---------------\n");
            vdataD();

            }else if(data2.dia > 30 && data2.mes == 4 || data2.dia > 30 && data2.mes == 6 || data2.dia > 30 && data2.mes ==9 || data2.dia > 30 &&
                     data2.mes == 11){
                printf("\n--------------- Data invalida! Digite novamente! ---------------\n");
                vdataD();

                }else if(data2.mes == 2 && data2.dia > 29 || data1.ano>=data2.ano){
                    printf("\n--------------- Data invalida! Digite novamente! ---------------\n");
                    vdataD();

                    }else{
                                vcomorb();}
}

vcomorb(){
    char resp;
        printf("\nO paciente possui alguma comorbidade?(digite s(sim) ou n(nao)\n");
        scanf("%c", &resp);
    if(resp=='s'|| resp=='S'){
        fflush(stdin);
        printf("\nQual comorbidade possui o paciente?:  \n\n");
        scanf("%100[^\n]s", &comorb);
        fflush(stdin);
        ficha = fopen("cadastrocv2022.txt", "a");
        fprintf(ficha,"Nome: ""%s", nome);
        fprintf(ficha,"\nCpf: ""%s", cpf);
        fprintf(ficha,"\nTelefone: ""%s",tel);
        fprintf(ficha,"\nEndereco: " "%s", endereco);
        fprintf(ficha,"\nNumero: ""%s", numero);
        fprintf(ficha,"\nBairro: ""%s", bairro);
        fprintf(ficha,"\nCidade: ""%s", cidade);
        fprintf(ficha,"\nEstado: ""%s", estado);
        fprintf(ficha,"\nCep: ""%s", cep);
        fprintf(ficha,"\nData de Nascimento: ""%d/%d/%d", data1.dia, data1.mes, data1.ano);
        fprintf(ficha,"\nEmail: ""%s", email);
        fprintf(ficha,"\nData do Diagnostico: ""%d/%d/%d", data2.dia, data2.mes, data2.ano);
        fprintf(ficha,"\nComorbidade(s): ""%s\n\n", comorb);
        ficha = fopen("cadastrocv2022.txt", "a");
        fclose(ficha);
        getchar();
        vidade();
}
    if (resp=='n' || resp=='N') {

        ficha = fopen("cadastrocv2022.txt", "a");
        fprintf(ficha,"Nome: ""%s", nome);
        fprintf(ficha,"\nCpf: ""%s", cpf);
        fprintf(ficha,"\nTelefone: ""%s",tel);
        fprintf(ficha,"\nEndereco: " "%s", endereco);
        fprintf(ficha,"\nNumero: ""%s", numero);
        fprintf(ficha,"\nBairro: ""%s", bairro);
        fprintf(ficha,"\nCidade: ""%s", cidade);
        fprintf(ficha,"\nEstado: ""%s", estado);
        fprintf(ficha,"\nCep: ""%s", cep);
        fprintf(ficha,"\nData de Nascimento: ""%d/%d/%d", data1.dia, data1.mes, data1.ano);
        fprintf(ficha,"\nEmail: ""%s", email);
        fprintf(ficha,"\nData do Diagnostico: ""%d/%d/%d", data2.dia, data2.mes, data2.ano);
        fprintf(ficha,"\nComorbidade(s): Nao possui.\n\n");
        ficha = fopen("cadastrocv2022.txt", "a");
        fclose(ficha);
        getchar();
        vidade();

         }

}
vidade(){

    data3.dia = 21;
    data3.mes = 11;
    data3.ano = 2022;

    if(data3.mes >= data1.mes && data3.dia >= data1.dia ){

        idade = data3.ano - data1.ano;
    }else{
        idade = data3.ano - (data1.ano + 1);

    }if(idade > 65){
        grupo = fopen("cadastrorisco2022.txt", "a");
        fprintf(grupo,"\nCep: ""%s", cep);
        grupo = fopen("cadastrorisco2022.txt", "a");
        fprintf(grupo,"\nIdade: ""%d anos.\n", idade);
        grupo = fopen("cadastrorisco2022.txt", "a");
        fclose(grupo);

}
        char resp2;
        printf("\nDeseja cadastrar mais pacientes?(digite s(sim) ou n(nao)\n");
        scanf("%c", &resp2);
        fflush(stdin);
    if(resp2=='s'|| resp2=='S'){

        system("cls");
        cadastro();
        }else{
        printf("\n\nDados salvos com Sucesso!!!") ;
}
}

apagarTudo(){
    ficha = fopen("cadastrocv2022.txt", "w");
    ficha = fprintf(ficha," ");
    ficha = fopen("cadastrorisco2022.txt", "w");
    grupo = fprintf(grupo," ");
}
int main(){
    //apagarTudo();
    setlocale(LC_ALL,"portuguese");
    acesso();
}





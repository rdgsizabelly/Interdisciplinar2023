#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
int main(){
	setlocale(LC_ALL,"Portuguese");	
	float peso, altura, imc, pesoIdeal, tmb, continuar;
	int idade, nomeVer = 0, i = 0;
	char nome[20], genero[2], genString[20], idadeVer[100], pesoVer[100], alturaVer[100], continuarVer[100], objetivo[2], objString[20], atividadeFisica[2], atvString[50];

do{
	system("cls");
	printf("");	printf("\t\t\t\t\x1b[31;47mBem Vindo ao FitFlex\033[0m!");
	printf("");
	printf("\n\t_____________________________________________________________________________________________\n");
		printf("\n\t\tPor favor digite seu nome e idade abaixo!");	
		printf("\n\t\t\tDigite o seu nome: ");
		scanf("%[^\n]%*c", &nome);
	while(nome[i] != '\0' && nomeVer != 1){    
        if((nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z') || isspace(nome[i])){
            i++;
			nomeVer = 0;
        }else{
            printf("\t\tPor favor digite somente letras.");
            printf("\n\t\t\tDigite o seu nome: ");
			scanf("%[^\n]%*c", &nome);
        }
    }
		printf("\t\t\tDigite a sua idade: ");
		scanf("%s", idadeVer);
		fflush(stdin);
		i = 0;
	// Verificar se o primeiro caractere e um sinal de menos (opcional para numeros negativos)
	if (idadeVer[i] == '-'){
			i++;
	}
	// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while(idadeVer[i] != '\0'){
		if(!isdigit(idadeVer[i])){
			printf("\t\tIdade inv�lida, digite uma idade v�lida: ");
			scanf("%s", idadeVer);
			fflush(stdin);
		}else{
			i++;
		}
	}
	idade = strtof(idadeVer, NULL);
	printf("\t_____________________________________________________________________________________________\n\n");
	printf("\t\tAgora preciso saber o seu peso e altura para determinar o seu IMC.\n");
	printf("\t\t\tInforme seu peso Kg(Ex: 70,5): ");
	scanf("%s", &pesoVer);
	fflush(stdin);
	i = 0;
	if (pesoVer[i] == '-'){
			i++;
		}
		// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while (pesoVer[i] != '\0'){
		if(!isdigit(pesoVer[i]) && pesoVer[i] != ','){
		printf("\t\tPeso inv�lido, digite um peso v�lido(Ex: 70,5): ");
		scanf("%s", &pesoVer);
		}else{
			i++;
		}
	}
		peso = strtof(pesoVer, NULL);
		printf("\t\t\tInforme sua altura(Ex: 1,70): ");
		scanf("%s", &alturaVer);
		fflush(stdin);
		i = 0;
	if(alturaVer[i] == '-'){
			i++;
	}
		// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while (alturaVer[i] != '\0'){
		if (!isdigit(alturaVer[i]) && alturaVer[i] != ','){
		printf("\t\tAltura inv�lida, digite uma altura v�lida(Ex: 1,70): ");
		scanf("%s", &alturaVer);
		fflush(stdin);
		}else{
			i++;
		}
	}
	altura = strtof(alturaVer, NULL);
		printf("\t_____________________________________________________________________________________________\n\n");
		printf("\t\tAgora preciso saber seu genero para calcular seu peso ideal:\n");
	do{
		printf("\t\t\tDigite '1' para Masculino ou '2' para Feminino: ");
    	scanf("%s", &genero);
    	fflush(stdin);
		if (strcmp(genero, "1") == 0){
			printf("\t\t\tGenero Masculino.\n");
			strcpy(genString, "Masculino");
			pesoIdeal = (72.7*altura) - 58;
			printf("\t\t\tSeu peso ideal �:%.1fKg\n",pesoIdeal);
		}else if (strcmp(genero, "2") == 0){
			printf("\t\t\tGenero Feminino.\n");
			strcpy(genString, "Feminino");	
			pesoIdeal = (62.1*altura) - 44.7;
			printf("\t\t\tSeu peso ideal �:%.1f\n",pesoIdeal);
		}else{
			printf("\t\t\tVoce n�o digitou uma op��o v�lida!\n");
		}
	}while((strcmp(genero, "1")!= 0)&&(strcmp(genero, "2")!= 0));
		printf("\t_____________________________________________________________________________________________\n\n");
    	printf("\t\tEscolha abaixo qual alternativa mais se aproxima de seu objetivo em nossa academia:");
    	printf("\n\t\t\tDigite 1 para Hipertrofia");
    	printf("\n\t\t\tDigite 2 para Emagrecimento");
    	printf("\n\t\t\tDigite 3 para Bem estar e saude\n");
    do{
		printf("\t\t\tDigite aqui: ");
    	scanf("%s", &objetivo);
    	fflush(stdin);
        if (strcmp(objetivo, "1") ==0){
	    	printf("\t\t\tHipertrofia\n");
		    strcpy(objString, "Hipertrofia");
	    }else if(strcmp(objetivo, "2") == 0){
		    printf("\t\t\tEmagrecimento\n");
	    	strcpy(objString, "Emagrecimento");
    	}else if(strcmp(objetivo, "3") ==0 ){ 
       	 	printf("\t\t\tBem estar e saude\n");
        	strcpy(objString, "Bem estar e saude");
	    }else{
    		printf("\t\t\tVoce n�o digitou uma op��o valida!\n");
    	}
    } while ((strcmp(objetivo, "1") != 0) && (strcmp(objetivo, "2") != 0) && (strcmp(objetivo, "3") != 0));
		printf("\t_____________________________________________________________________________________________\n\n");
		printf("\t\tAgora escolha seu n�vel de atividade f�sica:\n");
	    printf("\t\t\tDigite 1 se voce n�o pratica nenhuma atividade f�sica\n");
   	    printf("\t\t\tDigite 2 se voce pratica atividades f�sicas de 1 a 2 vezes na semana\n");
		printf("\t\t\tDigite 3 se voce pratica atividades f�sicas 4 vezes ou mais na semana\n");
   do{
	   printf("\t\t\tDigite aqui: ");
	   scanf("%s", &atividadeFisica);
	   fflush(stdin);
      if (strcmp(atividadeFisica, "1") == 0){
   	   	 	printf("\t\t\tNenhuma atividade f�sica\n");
	    	strcpy(atvString, "Nenhuma atividade f�sica");
      	}else if(strcmp(atividadeFisica, "2") == 0){ 
        	printf("\t\t\tAtividade f�sica 1 a 2 vezes na semana\n");
        	strcpy(atvString, "Atividade f�sica 1 a 2 vezes na semana");
	  	}else if(strcmp(atividadeFisica, "3") == 0){
        	printf("\t\t\tAtividade f�sica 4 vezes ou mais na semana\n");
        	strcpy(atvString, "Atividade f�sica 4 vezes ou mais na semana");
		}else{
			printf("\t\t\tVoce n�o digitou uma op��o valida!\n");
	}
   } while ((strcmp(atividadeFisica, "1") != 0) && (strcmp(atividadeFisica, "2") != 0) && (strcmp(atividadeFisica, "3") != 0));
		if(strcmp(genero, "1") == 0 && idade<29){
	tmb = 15.057 * peso + 692.2; //Calculo do tmb para homem jovem
    }if(strcmp(genero, "1") == 0 && idade>30 && idade<59){
	tmb = 11.472 * peso + 873.1;//Calculo do tmb para homem adulto
	}if(strcmp(genero, "1") == 0 && idade>=60){
	tmb = 11.711 * peso + 587;//Calculo do tmb para homem idoso
	}if(strcmp(genero, "2") == 0 && idade<29){
	tmb = 14.818 * peso + 486.6;//Calculo do tmb para mulher jovem
	}if(strcmp(genero, "2") == 0 && idade>30 && idade<59){
	tmb = 8.126 * peso + 845.6;//Calculo do tmb para adulto mulher
	}if(strcmp(genero, "2") == 0 && idade>=60){
	tmb = 9.082 * peso + 658.5;//Calculo do tmb para mulher idosa
	}
	printf("\t\t\tSua Taxa Metabolica Basal(TMB) �: %.2f calorias por dia!\n", tmb);
	imc = peso / (altura * altura);
	printf("\t\t\tSeu IMC �: %.1f\n", imc);
	if (imc <= 18.5){
		printf("\t\t\tVoce est� abaixo do peso!");
	}else if (imc >= 18.6 && imc < 24.9){
		printf("\t\t\tSeu peso est� normal!");
	}else if (imc >= 25 && imc < 29.9){
		printf("\t\t\tVoce est� com Sobrepeso!");
	}else if (imc >= 30 && imc < 34.9){
		printf("\t\t\tVoce est� com Obesidade grau 1!");
	}else if (imc >= 35 && imc <= 39.9){
		printf("\t\t\tVoce est� com Obesidade grau 2!");
	}else{
		printf("\t\t\tVoce est� com Obesidade Grau 3!");
	}
	
	printf("\n\t_____________________________________________________________________________________________\n\n");
	printf("\n\t\tAqui est�o 3 dicas para ajudar voc� em seu objetivo.\n");
	if(imc <=18.5 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-� importante obter orienta��es de um m�dico ou nutricionista para garantir que suas escolhas sejam seguras e eficazes.\n");
		printf("\t\t2-Concentre-se em alimentos nutritivos como proteinas magras, carboidratos complexos e gorduras saudaveis.\n");
		printf("\t\t3- Inicie um programa de treinamento de for�a como levantamento de peso.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Consulte um profissional de saude.\n");
		printf("\t\t2-Concentre-se em uma alimenta��o saud�vel e equilibrada.\n");
		printf("\t\t3-Comece com exercicios leves como caminhadas di�rias e aumente gradualmente conforme se sentir mais confort�vel\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Agende uma consulta com um nutricionista para avaliar sua saude atual e discutir op��es para ganhar peso de maneira saud�vel.\n");
		printf("\t\t2-Concentre-se em uma dieta que inclua uma variedade de alimentos nutritivos.\n");
		printf("\t\t3-Incorporar exerc�cios leves como caminhadas, alongamentos ou ioga pode ser ben�fico para sua sa�de.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Aumente a frequ�ncia de treinos para 3-4 vezes por semana para estimular o crescimento.\n");
		printf("\t\t2-Priorize uma dieta rica em prote�nas magras e calorias adequadas para sustentar o crescimento muscular.\n");
		printf("\t\t3-Desenvolva um plano de treinamento estruturado com foco em exerc�cios compostos e progress�o de intensidade.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Aumente a frequ�ncia de exerc�cios para 3-5 vezes por semana combinando aer�bicos e exerc�cios de resist�ncia.\n");
		printf("\t\t2-Adote uma dieta equilibrada com foco em alimentos nutritivos evitando processados e a�ucares.\n");
		printf("\t\t3-Monitore as calorias e crie um d�ficit controlado com orienta��o de um profissional para perder peso com seguran�a.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Fa�a atividade f�sica 3-5 vezes por semana para melhorar sua sa�de.\n");
		printf("\t\t2-Priorize alimentos naturais como frutas, vegetais e prote�nas magras evitando produtos processados.\n");
		printf("\t\t3-Busque orienta��o m�dica para criar um plano de sa�de personalizado e atingir seus objetivos com seguran�a.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Consuma mais calorias, priorizando prote�nas, carboidratos saud�veis e gorduras para promover o crescimento muscular.\n");
		printf("\t\t2-Foque em exerc�cios de muscula��o variados e aumente gradualmente a carga para estimular o crescimento muscular.\n");
		printf("\t\t3-Priorize o sono adequado e permita que seus m�sculos descansem entre os treinos para otimizar o crescimento muscular.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Mantenha uma dieta equilibrada focando em alimentos nutritivos e controlando calorias.\n");
		printf("\t\t2-Integre treinos intervalados de alta intensidade para aumentar a queima de calorias.\n");
		printf("\t\t3-Priorize a hidrata��o adequada e o descanso para suportar a recupera��o muscular.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Mantenha uma alimenta��o balanceada com foco em prote�nas magras, vegetais e gr�os integrais.\n");
		printf("\t\t2-Cuide da recupera��o com alongamento, sono de qualidade e descanso ativo para evitar les�es.\n");
		printf("\t\t3-Mantenha a hidrata��o e o equil�brio de eletr�litos para uma sa�de ideal com exerc�cios frequentes.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Comece o treinamento de resist�ncia gradualmente, aumentando a carga ao longo do tempo.\n");
		printf("\t\t2-Priorize uma dieta rica em prote�nas para apoiar o crescimento muscular.\n");
		printf("\t\t3-Considere a orienta��o de um profissional para um plano personalizado de treino e nutri��o.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Inicie atividades leves como caminhadas e evolua gradualmente.\n");
		printf("\t\t2-Adote uma dieta equilibrada com controle de por��es.\n");
		printf("\t\t3-Consulte um profissional de sa�de para orienta��es personalizadas.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Comece com atividades leves como caminhadas regulares.\n");
		printf("\t\t2-Adote uma dieta rica em vegetais, prote�nas magras e fibras.\n");
		printf("\t\t3-Realize check-ups m�dicos regulares para monitorar sua sa�de.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Aumente a frequ�ncia dos treinos para pelo menos 3-4 vezes por semana.\n");
		printf("\t\t2-Priorize exerc�cios de resist�ncia e muscula��o para estimular o crescimento muscular.\n");
		printf("\t\t3-Consuma uma dieta rica em prote�nas e calorias controladas para apoiar o ganho de massa muscular.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Aumente a frequ�ncia de exerc�cios para pelo menos 3-5 vezes/semana para queimar mais calorias.\n");
		printf("\t\t2-Priorize atividades aer�bicas como corrida, nata��o ou ciclismo para acelerar a perda de peso.\n");
		printf("\t\t3-Adote uma dieta equilibrada, com �nfase em alimentos ricos em fibras e prote�nas.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Aumente a frequ�ncia de exerc�cios para pelo menos 3-5 vezes/semana para melhorar sua sa�de geral.\n");
		printf("\t\t2-Conclua atividades variadas como caminhadas, ioga e muscula��o para promover a sa�de cardiovascular e muscular.\n");
		printf("\t\t3-Mantenha uma alimenta��o balanceada e rica em vegetais, prote�nas magras e gr�os integrais.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Priorize uma dieta rica em prote�nas magras como frango, peixe e ovos para apoiar o crescimento muscular.\n");
		printf("\t\t2-Realize exerc�cios de resist�ncia como muscula��o variando os exerc�cios regularmente.\n");
		printf("\t\t3-Assegure-se de descansar adequadamente entre os treinos e obter sono de qualidade.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Mantenha uma dieta equilibrada com foco em alimentos integrais, vegetais, prote�nas magras e evite excesso de calorias vazias.\n");
		printf("\t\t2-Varie seus treinos incluindo exerc�cios de alta intensidade e aer�bicos para maximizar a queima de calorias.\n");
		printf("\t\t3-Monitore seu progresso, ajustando sua dieta e rotina de exerc�cios conforme necess�rio.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Continue com sua rotina regular de exerc�cios mantendo um equil�brio entre cardio e muscula��o.\n");
		printf("\t\t2-Priorize uma alimenta��o balanceada rica em nutrientes incluindo frutas, vegetais, prote�nas magras e gr�os integrais.\n");
		printf("\t\t3-Cuide da recupera��o garantindo um sono de qualidade gerenciando o estresse e incluindo atividades de relaxamento como ioga.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Inicie um programa de treinamento de resist�ncia para construir m�sculos.\n");
		printf("\t\t2-Ajuste sua alimenta��o para incluir uma quantidade adequada de prote�nas, carboidratos e gorduras saud�veis para apoiar o crescimento.\n");
		printf("\t\t3-Consulte um m�dico para garantir que sua sa�de esteja em ordem antes de iniciar um novo programa de treinamento e dieta.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Comece com atividades leves como caminhadas e aumente gradualmente a intensidade e a frequ�ncia para queimar calorias.\n");
		printf("\t\t2-Adote uma dieta equilibrada rica em vegetais prote�nas magras e evite alimentos processados e a�ucarados.\n");
		printf("\t\t3-Considere a ajuda de um nutricionista para criar um plano personalizado de perda de peso e estabelecer metas realistas.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Inicie um programa de atividade f�sica leve a moderada como caminhadas, nata��o ou ciclismo com a orienta��o de um profissional de sa�de.\n");
		printf("\t\t2-Adote uma dieta balanceada com foco em alimentos naturais, como frutas, vegetais, proteínas magras e gr�os inteiros.\n");
		printf("\t\t3-Mantenha um estilo de vida ativo no dia a dia como optar por escadas em vez de elevadores fazer pausas para esticar-se no trabalho.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Aumente a frequ�ncia dos treinos para pelo menos 3-4 vezes por semana para estimular o crescimento muscular de maneira mais eficaz.\n");
		printf("\t\t2-Concentre-se em exerc�cios de resist�ncia, como levantamento de peso, e inclua uma variedade de grupos musculares em seus treinos.\n");
		printf("\t\t3-Mantenha uma dieta rica em prote�nas para apoiar a recupera��o muscular e o crescimento.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Aumente a frequ�ncia dos exerc�cios para pelo menos 3-4 vezes por semana para acelerar a queima de calorias.\n");
		printf("\t\t2-Priorize treinos que combinem exerc�cios aer�bicos como corrida ou nata��o com exerc�cios de resist�ncia para construir m�sculos e aumentar o metabolismo.\n");
		printf("\t\t3-Mantenha uma alimenta��o balanceada com foco em alimentos naturais e evite o consumo excessivo de calorias, gordura saturadas e a��cares refinados.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Aumente a frequ�ncia dos exerc�cios para pelo menos 3-4 vezes por semana para melhorar sua sa�de geral.\n");
		printf("\t\t2-Inclua uma variedade de atividades como caminhadas, nata��o ou ioga para promover a resist�ncia e sa�de cardiovascular.\n");
		printf("\t\t3-Adote uma alimenta��o equilibrada rica em frutas, vegetais, gr�os integrais e prote�nas magras.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Priorize uma dieta rica em prote�nas magras, frango, peixe, ovos e leguminosas para apoiar o crescimento muscular.\n");
		printf("\t\t2-Realize treinamentos como levantamento de pesos com �nfase na progress�o de cargas e variedade de exerc�cios.\n");
		printf("\t\t3-Certifique-se de descansar adequadamente entre os treinos e dormir o suficiente para ter uma recupera��o adequada. \n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Mantenha um d�ficit cal�rico controlado consumindo menos calorias do que queima para promover a perda de peso de forma saud�vel.\n");
		printf("\t\t2-Inclua uma combina��o de exerc�cios aer�bicos e treinamento de resist�ncia em sua rotina pois isso ajudar� queimar calorias e preservar a massa muscular.\n");
		printf("\t\t3-Priorize uma dieta balanceada com alimentos ricos em nutrientes como frutas, vegetais prote�nas magras e gr�os inteiros e evite alimentos processados.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Mantenha uma rotina consistente de exerc�cios incluindo atividades aer�bicas e de resist�ncia.\n");
		printf("\t\t2-Adote uma alimenta��o balanceada com �nfase em alimentos naturais como frutas, verduras, prote�nas magras e gr�os inteiros.\n");
		printf("\t\t3-Priorize o sono de qualidade e o gerenciamento do estresse para otimizar sua sa�de.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-� essencial obter avalia��o m�dica para garantir que sua sa�de est� em ordem antes de iniciar o treinamento para hipertrofia.\n");
		printf("\t\t2-Inicie com um programa de treinamento supervisionado para garantir que est� fazendo os exerc�cios corretamente e de forma segura.\n");
		printf("\t\t3-Para promover o ganho de massa muscular mantenha uma dieta rica em prote�nas magras, carboidratos complexos e gorduras saud�veis.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Consulte um m�dico ou nutricionista para criar um plano de emagrecimento personalizado e seguro.\n");
		printf("\t\t2-Estabele�a metas realistas e comece com pequenas mudan�as na alimenta��o.\n");
		printf("\t\t3-Gradualmente introduza atividades f�sicas e aumente a frequ�ncia e intensidade conforme sua condi��o f�sica melhore.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Inicie com atividades leves como caminhadas curtas e gradualmente aumente a intensidade e dura��o do exerc�cio.\n");
		printf("\t\t2-Consulte um m�dico para avaliar sua sa�de geral e receber orienta��o sobre um programa de exerc�cios seguro.\n");
		printf("\t\t3-Adote uma dieta balanceada com foco em alimentos naturais e nutritivos controlando o consumo de calorias.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Aumente a frequ�ncia semanal de treinos para pelo menos 4-5 vezes com foco em exerc�cios de resist�ncia e muscula��o.\n");
		printf("\t\t2-Consuma uma dieta equilibrada e rica em prote�nas para promover o crescimento muscular evitando excesso de calorias.\n");
		printf("\t\t3-Considere a orienta��o de um fisioterapeuta para desenvolver um programa de treinamento adequado para minimizar riscos de les�es.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Aumente gradualmente a frequ�ncia de exerc�cios para pelo menos 150 minutos de atividade moderada por semana.\n");
		printf("\t\t2-Ajuste sua alimenta��o para criar um d�ficit cal�rico,\n reduzindo a ingest�o de calorias.\n");
		printf("\t\t3-Consulte um nutricionista para desenvolver um plano personalizado de perda de peso e acompanhe seu progresso regularmente.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Aumente gradualmente a frequ�ncia dos exerc�cios para atingir pelo menos 150 minutos de atividade moderada por semana.\n");
		printf("\t\t2-Adote uma dieta balanceada, rica em vegetais, fibras e prote�nas magras, evitando alimentos processados e ricos em a��cares.\n");
		printf("\t\t3-Monitore sua sa�de com exames m�dicos regulares para controlar fatores de risco como press�o arterial e n�veis de glicose.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Mantenha uma rotina de exerc�cios consistente focando em treinamento de resist�ncia para promover o crescimento muscular.\n");
		printf("\t\t2-Consuma uma dieta equilibrada e rica em prote�nas para sustentar o crescimento muscular.\n");
		printf("\t\t3-Certifique-se de descansar adequadamente para permitir que seus m�sculos se recuperem e cres�am.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Continue com a rotina de exerc�cios frequente priorizando exerc�cios aer�bicos e de resist�ncia para queimar calorias.\n");
		printf("\t\t2-Adote uma alimenta��o saud�vel e equilibrada com �nfase em por��es controladas e alimentos ricos em nutrientes.\n");
		printf("\t\t3-Considere trabalhar com um nutricionista ou personal trainer para criar um plano de emagrecimento personalizado. \n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Continue com a pr�tica regular de atividades f�sicas, focando em exerc�cios aer�bicos e de resist�ncia.\n");
		printf("\t\t2-Adote uma alimenta��o equilibrada com redu��o de calorias e �nfase em alimentos saud�veis como frutas, vegetais, prote�nas magras e gr�os inteiros.\n");
		printf("\t\t3-Mantenha o acompanhamento m�dico e se necess�rio consulte um nutricionista para criar um plano de emagrecimento seguro.\n");
}
	printf("\t________________________________________________________________________________________\n\n");
    printf("\t\t\tAqui estao informacoes:\n");
   	printf("\t\t\tNome: %s\n", nome);
	printf("\t\t\tIdade: %d anos\n", idade);
	printf("\t\t\tGenero escolhido: %s\n", genString);
	printf("\t\t\tPeso: %.2fKg\n", peso);
	printf("\t\t\tAltura: %.2f\n", altura);
	printf("\t\t\tObjetivo escolhido: %s\n", objString);
	printf("\t\t\tNivel de atividade fisica escolhida: %s\n",atvString);	
	printf("\t\t\tSeu peso ideal �: %.2fKg\n", pesoIdeal);
	printf("\t\t\tSeu IMC deu:%.2f\n", imc);
	printf("\t\t\tSeu TMB deu:%.2f\n", tmb);
    printf("\t________________________________________________________________________________________\n");
	printf("\n\t\tEscolha '1' para sair do programa ou '2' para repetir todo o processo: ");
    scanf(" %s", &continuarVer);
    fflush(stdin);
    i = 0;
    if (continuarVer[i] == '-'){
			i++;
		}
		// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while (continuarVer[i] != '\0'){
		while ((continuarVer[i] < '0' || continuarVer[i] > '9') && continuarVer[i] != '.'){
		printf("\t\tOp��o inv�lida, digite uma op��o v�lida: ");
		scanf("%s", &continuarVer);
		fflush(stdin);
		}
		i++;
	}
	continuar = strtof(continuarVer, NULL);
}while(continuar == 2);
	system("cls");
	system("pause");
	return 0;
}

//
//  main.c
//  lab01_2
//
//  Created by Frederic on 04/03/18.
//  Copyright © 2018 Frederic. All rights reserved.
//

#include <ctype.h>
#include <stdio.h>
#include <math.h>

float fatorial(char token[], int size);
float real(char token[], int size);
float inteiro(char token[], int size);

int main() {
    
    char str[100];
    char palavra[20];
    float num[20];
    double res=0;
    int i=0;
    int j=0;
    int k=0;
    int tam=0;
    int flag=0;
    int erro=0;
    
    fgets(str, 100, stdin);
    
    while(str[i]!='\n'){
        while(str[i]!=' '){
            if(str[i]=='\n'){
                break;
            }
            if(flag==2){
                erro=1;
            }
            palavra[j]=str[i];
            if(str[i]=='.'){
                if(flag==1){
                    erro=1;
                }
                flag=1;
            }
            else if(str[i]=='!'){
                flag=2;
            }
            if((str[i]<='-' && str[i]>='"')||(str[i]>=':')){
                erro =1;
            }
            i++;
            j++;
            tam++;
        }
        if(erro==1){
            num[k]=0;
            k++;
        }
        else{
            if(flag==1){
                num[k]=real(palavra, tam);
                k++;
            }
            else if(flag==2){
                num[k]=fatorial(palavra, tam);
                k++;
            }
            else{
                num[k]=inteiro(palavra, tam);
                k++;
            }
        }
        if(str[i]=='\n'){
            break;
        }
        flag=0;
        i++;
        j=0;
        tam=0;
        erro=0;
    }
    
    i=0;
    for(i=0;i<k;i++){
        res=res+num[i];
    }
    
    printf("%.2f\n",res);
    
    return 0;
}


float fatorial(char token[], int size){
    
    int n=0;
    int i;
    float fact=1;
    int temp;
    
    temp=size-2;
    for(i=0;i<size-1;i++){
        token[i]=token[i]-'0';
        n=n+token[i]*pow(10,temp);
        temp--;
    }
    for (i=1;i<=n;i++){
        fact = fact * i;
    }
    
    return fact;
}

float real(char token[], int size){
    
    int tam=0;
    int i=0;
    int j=0;
    float num[10];
    float res=0;
    
    while (token[i]!='.') {;
        num[j]=token[i]-'0';
        tam=tam+1;
        i++;
        j++;
    }
    i++;
    for(i=i;i<size;i++){
        num[j]=token[i]-'0';
        j++;
    }
    tam--;
    for(i=0;i<size-1;i++){
        res=res+num[i]*pow(10,tam);
        tam--;
    }
    
    return res;
    
}

float inteiro(char token[], int size){
    
    int i;
    float res=0;
    int tam;
    
    tam=size-1;
    for(i=0;i<size;i++){
        token[i]=token[i]-'0';
        res=res+token[i]*pow(10,tam);
        tam--;
    }
    
    return res;
    
}












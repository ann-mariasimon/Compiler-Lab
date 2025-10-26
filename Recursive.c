#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i=0;

int E(),EP(),T(),TP(),F();

int main(){
printf("Recursive Grammer for the Grammer.\nHere '@' is the Epsilion used.\n");
printf("E->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/id\n");
printf("Enter the Expression:\n");
scanf("%s",input);
if(E() && input[i]=='\0')
printf("String is Acceptable\n");
else
printf("String is not Acceptable\n");
}

int E(){
return T() && EP();
}

int EP(){
if(input[i]=='+'){
i++;
return T() && EP();
}
return 1;
}

int T(){
return F() && TP();
}

int TP(){
if(input[i]=='*'){
i++;
return F() && TP();
}
return 1;
}

int F(){
if(input[i]=='('){
i++;
if(E() && input[i]==')'){
i++;
return 1;
}
return 0;
}
if(isalpha(input[i])){
i++;
return 1;
}
return 0;
}

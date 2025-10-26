#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
FILE *input,*output;
char ch,word[20];
int line=1,token=1,i,isKeyword;

char keywords[10][10]={"int","main","if","else","do","while"};

input=fopen("input.txt","r");
output=fopen("output.txt","w");

fprintf(output,"LineNo.\t\tTokenNo\t\tTokenType\t\tLexeme\n");

while((ch=fgetc(input))!=EOF){

if(ch==' ' || ch=='\t')
continue;

if(ch=='\n'){
line++;
continue;
}
if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
fprintf(output,"%d\t\t%d\t\tOperator    \t\t%c\n",line,token++,ch);
continue;
}

if(ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='!' || ch=='%'){
fprintf(output,"%d\t\t%d\t\tSpecial    \t\t%c\n",line,token++,ch);
continue;
}

if(isdigit(ch)){
fprintf(output,"%d\t\t%d\t\tDigit    \t\t%c\n",line,token++,ch);
continue;
}

if(isalpha(ch)){
i=0;
word[i++]=ch;

while((ch=fgetc(input))!=EOF && (isalnum(ch) || ch=='_'))
word[i++]=ch;

word[i]='\0';
isKeyword=0;

for(int k=0;k<6;k++){
if(strcmp(word,keywords[k])==0){
isKeyword=1;
break;
}
}

if(isKeyword)
fprintf(output,"%d\t\t%d\t\tKeyword    \t\t%s\n",line,token++,word);
else
fprintf(output,"%d\t\t%d\t\tIdentifier    \t\t%s\n",line,token++,word);

if(ch!=EOF)
fseek(input,-1,SEEK_CUR);
}
}
fclose(input);
fclose(output);
return 0;
}

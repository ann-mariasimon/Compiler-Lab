%{
#include <stdio.h>

int vowel_count = 0;
int consonant_count = 0;
%}

%%

[aeiouAEIOU]                    { vowel_count++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { consonant_count++; }
[ \t\n]+                        { /* ignore whitespace */ }
.                               { /* ignore others */ }

%%

int yywrap(void) {
    return 1;
}

int main() {
    FILE *f1 = fopen("input.txt", "r");
    if (f1 == NULL) {
        perror("Error opening file");
        return 1;
    }

    char input_string[1024];
    char ch;
    int i = 0;

    while ((ch = fgetc(f1)) != EOF && i < 1023) {
        input_string[i++] = ch;
    }
    input_string[i] = '\0';
    fclose(f1);

    printf("String in file:\n%s\n\n", input_string);

    YY_BUFFER_STATE buffer = yy_scan_string(input_string);
    yylex();

    printf("Total number of vowels: %d\n", vowel_count);
    printf("Total number of consonants: %d\n", consonant_count);

    yy_delete_buffer(buffer);
    return 0;
}

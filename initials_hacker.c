#include <cs50.h>
#include <stdio.h>
#include <string.h>

//THIS IS A HACKER CHALLENGE, IF MY IMPLEMENTATION IS BAD, THEN RECOMMEND ME AN EASY WAY

void returnInitials(string n);
void capitalize(char ltr);

int main(void)
{
    string s = GetString();
    returnInitials(s);
    printf("\n");
    return 0;
}

void returnInitials(string n){
    if (n[0] != ' '){
        capitalize(n[0]);
    }
    
    for(int i = 0; i < strlen(n) - 1; i++){
        if (n[i] == ' ' && n[i+1] != ' '){  //THIS DETERMINES IF THE NEXT ELEMENT IS A NON-SPACE
            capitalize(n[i+1]);             //CAPITALIZES A NON SPACE ELEMENT
        }
    }
}

void capitalize(char ltr){
    if (ltr >= 'a' && ltr <= 'z'){
        printf("%c",ltr - 32);	//lazy way to capitalize letters
    }else{
        printf("%c",ltr);
    }
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>

void returnInitials(string n);
void capitalize(char ltr);

int main(void)
{
    string s = GetString();
    capitalize(s[0]);
    
    returnInitials(s);
    printf("\n");
    
    
    return 0;
}

void returnInitials(string n){
    for(int i = 1; i < strlen(n); i++){
        if (n[i] == ' '){
            if (i != strlen(n)){  //sanity checks, makes sure array does not go out of range incase of adding spaces at the end
                capitalize(n[i+1]);
            }
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

#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Caesars cipher
string caesarCipher(string pt, int k);
char encode(char c, int k);

int main(int argc, string argv[])
{
    //If no inputs or more arguments
    if (argc != 2){
        printf("Usage: ./caesar k\n");
        return 1;
    }else{
        //CONVERTS THE STRING CONSTANT TO INTEGER
        int k = atoi(argv[1]);
        k %= 26;
        //GETS THE PLAINTEXT
        printf("plaintext: ");
        string ptext = get_string();
        printf("ciphertext: ");
        string ctext = caesarCipher(ptext, k);
        printf("%s",ctext);
        printf("\n");
    }
}

string caesarCipher(string pt, int k){
    for(int i = 0; i < strlen(pt); i++){
        if((pt[i] >= 'A' && pt[i] <= 'Z') || (pt[i] >= 'a' && pt[i] <= 'z')){
            pt[i] = encode(pt[i], k);
        }
    }
    
    return pt;
}

char encode(char c, int k){
    
    
    char e;
    if(c >= 'A' && c <= 'Z'){
        e = (char)(((int)c + k) % 90); //THIS IS CONFUSING, I KNOW
        if (e < 'A'){
            e += 64;
        }
    }else{
        e = (char)(((int)c + k) % 122);
        if (e < 'a'){
            e += 96;
        }
    }
    
    return e;
}




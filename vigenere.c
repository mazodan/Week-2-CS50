#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Put functions here
string viginereCipher(string ptext, string key);
char encode(char c, char k);

// Global variables
// Track current element of "key" {"Default : 0"}
int keyElem = 0;


// Main Entry
int main(int argc, string argv[]){



    // Check Inputs - SPEC { viginere k (string) where string = KEY }
    if (argc != 2){
        printf("Usage: ./viginere k\n");
        return 1;
    } else {

        string key = argv[1];
        int keyLen = strlen(key);

        for (int i = 0; i < keyLen; i++){
            if(isdigit(key[i])){
                printf("Usage: ./viginere k\n");
                return 1;
            }
        }


        // Execute Main Code
        printf("plaintext: ");
        string ptext = get_string();
        printf("ciphertext: ");
        string ctext = viginereCipher(ptext, argv[1]);
        // OUTPUT
        printf("%s",ctext);
        printf("\n");
    }


}
// Viginere cipher requires a key, Which is a string - Append depending on Letter, Use Modulo
string viginereCipher(string ptext, string key){
    // Use in the condition whether it reaches the end of the string
    int keyLimit = strlen(key);


    for(int i = 0; i < strlen(ptext); i++){
        // Check if element exceeds the length of key
        if (keyElem == keyLimit){
            // RESET to Element zero
            keyElem = 0;
        }

        //Determine if Plaintext is within the Alphabet
        if ((ptext[i] >= 'A' && ptext[i] <= 'Z') || (ptext[i] >= 'a' && ptext[i] <= 'z')){
            // Determine if key is also in the alphabet, if not, Leave it alone and do not iterate, recycle key
            if((key[keyElem] >= 'A' && key[keyElem] <= 'Z') || (key[keyElem] >= 'a' && key[keyElem] <= 'z')){
                // Execute Encode
                ptext[i] = encode(ptext[i], key[keyElem]);
            }
        } //Else, Do not manipulate and move to the next element
    }

    return ptext;
}

char encode(char c, char k){
    // Make a placeholder for the char to be returned back
    char e;
    int s;  //To be used when adding the key

    // Determine if the key is within the alphabet

        // Get the sub to be used if capital or small letter is used in key
        if (k >= 'A' && k <= 'Z'){
            // Typecast to Integer and use Mod 65 to get corresponding sub value { A = 0, Z = 25 }
            s = ((int) k) % 65;
        } else {
            // Assumes small letters are used
            s = ((int) k) % 97;
        }

        // Now that the sub value is assigned, lets add it
        // Determine if the element is Captial or Small so appropriate ascii code would be returned
        if (c >= 'A' && c <= 'Z'){
            e = (char)(((int)c + s) % 90);
            if (e < 'A'){
                e += 64;
            }
        } else {
            e = (char)(((int)c + s) % 122);
            if (e < 'a'){
                e += 96;
            }
        }

        // Iterate to next kth element
        keyElem++;

        // Return the character e
        if (e == '`'){
            return 'z';
        } else {
            return e;
        }



}







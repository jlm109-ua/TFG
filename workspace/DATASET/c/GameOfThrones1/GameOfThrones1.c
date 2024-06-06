#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagramOfPalindrome(char *s);

bool isAnagramOfPalindrome(char *s)
{
    int ch[256] = {0};
    int nLen = strlen(s);
    int nCountOfOdd = 0;
    
    for(int i = 0 ; i < nLen; i++)
    {
        int nAscii = (int)s[i];
        ++ch[nAscii];
    }
    
    for(int i = 0 ; i <= 255 ; i++)
    {
        if((ch[i] & 1) == 1) {
            if(nCountOfOdd == 1)
                return false;
            else
                nCountOfOdd = 1;
        }
    }
    return true;
}

int runMain(){
     char s[100000];
    strcpy(s, "aaabbbb");  // Asigna el valor "aaabbbb" a la cadena s

    bool flag = isAnagramOfPalindrome(s);
    if (flag == false)
        return 0;
    else
        return 1;

}

int main() {
    return runMain();
}

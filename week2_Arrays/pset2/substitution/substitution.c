#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(int argc, string argv[])
{
    int offset[26];

    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            for (int i=0;i<26;i++)
            {
                if (argv[1][i]>='a' && argv[1][i]<='z')
                {
                    offset[i] = argv[1][i] - 'a';
                }
                else if(argv[1][i]>='A' && argv[1][i]<='Z')
                {
                    offset[i] = argv[1][i] - 'A';
                }
                else{
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }
            }
            for (int i=0;i<25;i++)
            {
                for (int j=i+1;j<26;j++)
                {
                    if (offset[i] == offset[j])
                    {
                        printf("Key must contain 26 characters.\n");
                        return 1;
                    }
                }
            }

            string s = get_string("plaintext:  ");
            for (int i=0, len_s = strlen(s); i<len_s; i++)
            {
                if(s[i]>='a' && s[i]<='z')
                {
                    s[i] = 'a' + offset[s[i]-'a'];
                }
                else if (s[i]>='A' && s[i]<='Z')
                {
                    s[i] = 'A' + offset[s[i]-'A'];
                }
            }
            printf("ciphertext: %s\n",s);
            return 0;

        }
        else{
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}
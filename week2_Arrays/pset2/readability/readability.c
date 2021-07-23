#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int index;
    index = (int)round((double)(0.0588 * letters/words*100 - 0.296 * sentences/words*100 - 15.8));

    if (index<1)
    {
        printf("Before Grade 1\n");
    }
    else if(index>=16)
    {
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %i\n", index);
    }
    
}





int count_letters(string text)
{
    int cont=0;
    for(int i=0,length=strlen(text); i<length; i++)
    {
        if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z'))
        {
            cont++;
        }
    }
    return cont;
}

int count_words(string text)
{
    int cont=1;
    for(int i=0,length=strlen(text); i<length; i++)
    {
        if(text[i] == ' ')
        {
            cont++;
        }
    }
    return cont;
}

int count_sentences(string text)
{
    int cont=0;
    for(int i=0,length=strlen(text); i<length; i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            cont++;
        }
    }
    return cont;
}

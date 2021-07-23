// Averages numbers using a helper function

#include <cs50.h>
#include <stdio.h>

float average(int length, float array[]);

int main(void)
{
    // Get number of scores
    int n = get_int("Scores:  ");

    // Get scores
    float scores[n];
    for (int i = 0; i < n; i++)
    {
        scores[i] = get_float("Score %i: ", i + 1);
    }

    // Print average
    printf("Average: %.1f\n", average(n, scores));
}

float average(int length, float array[])
{
    float sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return (float) sum / (float) length;
}

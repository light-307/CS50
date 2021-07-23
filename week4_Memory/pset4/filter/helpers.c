#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j< width ; j++)
        {
            int tmp = (int)((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0 + 0.5);
            image[i][j].rgbtBlue = tmp;
            image[i][j].rgbtGreen = tmp;
            image[i][j].rgbtRed = tmp;
        }
        
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j< width/2 ; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            
            image[i][j] = image[i][width - j -1];
            image[i][width - j -1] = tmp;
        }
        
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*image2)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j< width ; j++)
        {
            image2[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j< width ; j++)
        {
            int cont = 0;
            int tmpb = 0;
            int tmpg = 0;
            int tmpr = 0;
            for(int m =-1; m<=1; m++)
            {
                for(int n =-1; n<=1; n++)
                {
                    if((i+m>=0) && (i+m<=height-1) && (j+n>=0) && (j+n<=width-1))
                    {
                        tmpb = tmpb + image2[i+m][j+n].rgbtBlue;
                        tmpg = tmpg + image2[i+m][j+n].rgbtGreen;
                        tmpr = tmpr + image2[i+m][j+n].rgbtRed;
                        cont++;
                    }
                }
            }
            image[i][j].rgbtBlue = (int)(1.0*tmpb/cont + 0.5);
            image[i][j].rgbtGreen = (int)(1.0*tmpg/cont + 0.5);
            image[i][j].rgbtRed = (int)(1.0*tmpr/cont + 0.5);

            // printf("image:%i ",image[i][j].rgbtBlue);
            // printf("%i ",image[i][j].rgbtGreen);
            // printf("%i ",image[i][j].rgbtRed);
            // printf("image2:%i ",image2[i][j].rgbtBlue);
            // printf("%i ",image2[i][j].rgbtGreen);
            // printf("%i ",image2[i][j].rgbtRed);
            // printf("tmp:%i ",tmpb);
            // printf("%i ",tmpg);
            // printf("%i ",tmpr);
            // printf("cont:%i\n",cont);
            // if(i==1)
            // {
            //     return;
            // }
            
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*image2)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j< width ; j++)
        {
            image2[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j< width ; j++)
        {
            RGBTRIPLE(*box)[3] = calloc(3, 3 * sizeof(RGBTRIPLE));

            for(int m =-1; m<=1; m++)
            {
                for(int n =-1; n<=1; n++)
                {
                    if((i+m>=0) && (i+m<=height-1) && (j+n>=0) && (j+n<=width-1))
                    {
                        box[m+1][n+1] = image2[i+m][j+n];
                    }
                    else
                    {
                        box[m+1][n+1].rgbtBlue = 0;
                        box[m+1][n+1].rgbtGreen = 0;
                        box[m+1][n+1].rgbtRed = 0;
                    }
                    
                }
            }
            int Blue = (int)(sqrt(pow(-box[0][0].rgbtBlue + box[0][2].rgbtBlue - 2*box[1][0].rgbtBlue + 2*box[1][2].rgbtBlue - box[2][0].rgbtBlue + box[2][2].rgbtBlue, 2) + pow(-box[0][0].rgbtBlue + box[2][0].rgbtBlue - 2*box[0][1].rgbtBlue + 2*box[2][1].rgbtBlue - box[0][2].rgbtBlue + box[2][2].rgbtBlue, 2)) + 0.5);
            int Green = (int)(sqrt(pow(-box[0][0].rgbtGreen + box[0][2].rgbtGreen - 2*box[1][0].rgbtGreen + 2*box[1][2].rgbtGreen - box[2][0].rgbtGreen + box[2][2].rgbtGreen, 2) + pow(-box[0][0].rgbtGreen + box[2][0].rgbtGreen - 2*box[0][1].rgbtGreen + 2*box[2][1].rgbtGreen - box[0][2].rgbtGreen + box[2][2].rgbtGreen, 2)) + 0.5);
            int Red = (int)(sqrt(pow(-box[0][0].rgbtRed + box[0][2].rgbtRed - 2*box[1][0].rgbtRed + 2*box[1][2].rgbtRed - box[2][0].rgbtRed + box[2][2].rgbtRed, 2) + pow(-box[0][0].rgbtRed + box[2][0].rgbtRed - 2*box[0][1].rgbtRed + 2*box[2][1].rgbtRed - box[0][2].rgbtRed + box[2][2].rgbtRed, 2)) + 0.5);

            image[i][j].rgbtBlue = Blue<=255 ? Blue : 255;
            image[i][j].rgbtGreen = Green<=255 ? Green : 255;
            image[i][j].rgbtRed = Red<=255 ? Red : 255;
        }
    }

    return;
}

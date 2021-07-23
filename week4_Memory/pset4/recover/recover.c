#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 1;
    }


    int i=0;
    char outname[8];
    // Open output file
    FILE *outptr = fopen("000.jpg", "w");
    if (outptr == NULL)
    {
        fclose(file);
        fprintf(stderr, "Could not create 000.jpg.\n");
        return 1;
    }


    BYTE(*block) = calloc(512, sizeof(BYTE));
    
    while(fread(block, sizeof(BYTE), 512, file) == 512)
    {
        if(block[0]==0xff && block[1]==0xd8 && block[2]==0xff && (block[3]>>4)==0xe)
        {
            fclose(outptr);

            sprintf(outname,"%.3d.jpg",i);
            i++;

            // Open output file
            FILE *outptr = fopen(outname, "w");
            if (outptr == NULL)
            {
                fclose(file);
                fprintf(stderr, "Could not create %s.\n", outname);
                return 1;
            }
        }

        // Write row to outfile
        fwrite(block, sizeof(BYTE), 512, outptr);
        
    }
    
    free(block);
    fclose(file);
    fclose(outptr);
}

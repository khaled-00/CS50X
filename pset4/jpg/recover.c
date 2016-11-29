/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdint.h>
#include <cs50.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
    // The files
    FILE* inptr = fopen("card.raw", "r");
    FILE* outptr = NULL;
  
    // Name of outptr
    char named[3];
    int num_name = 0;
     
    // Data of image
    uint8_t buffer[512]; 

    // Read 512 Bytes every turn until the end of file
    while(fread(&buffer, sizeof(uint8_t), 512, inptr) != 0)
    {
        // Start of jpg
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // There is a file has opened
            if(outptr != NULL)
            {
                fclose(outptr);
            }
        
            // Make a name
            sprintf(named, "%.03d.jpg", num_name);
        
            // Make a file
            outptr = fopen(named, "w");
            
            // Write into this file
            fwrite(&buffer, sizeof(uint8_t), 512, outptr);
           
            // Count the file
            num_name++;
        }
        else if(outptr != NULL)
        {
            // Write into this file
            fwrite(&buffer, sizeof(uint8_t), 512, outptr);
        }
    }
        
    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    // That's all folks
    return 0;
}

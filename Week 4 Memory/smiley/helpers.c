#include "helpers.h"

// Colorize image
void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through all the pixels in the image
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // Check if the pixel is black (0,0,0)
            if (image[j][i].rgbtBlue == 0 && image[j][i].rgbtGreen == 0 && image[j][i].rgbtRed == 0)
            {
                // Set the pixel color to turquoise (10, 186, 181)
                image[j][i].rgbtRed = 10;
                image[j][i].rgbtGreen = 186;
                image[j][i].rgbtBlue = 181;
            }
        }
    }
}

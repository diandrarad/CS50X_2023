#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute the average of the pixel's RGB values
            int avg = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.0);

            // Set each color value to the average
            image[j][i].rgbtBlue = avg;
            image[j][i].rgbtGreen = avg;
            image[j][i].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute new RGB values based on the sepia formula
            int sepiaRed = round(.393 * image[j][i].rgbtRed + .769 * image[j][i].rgbtGreen + .189 * image[j][i].rgbtBlue);
            int sepiaGreen = round(.349 * image[j][i].rgbtRed + .686 * image[j][i].rgbtGreen + .168 * image[j][i].rgbtBlue);
            int sepiaBlue = round(.272 * image[j][i].rgbtRed + .534 * image[j][i].rgbtGreen + .131 * image[j][i].rgbtBlue);

            // Cap the RGB values at 255
            image[j][i].rgbtRed = fmin(255, sepiaRed);
            image[j][i].rgbtGreen = fmin(255, sepiaGreen);
            image[j][i].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    // Loop through each row in the image
    for (int i = 0; i < height; i++)
    {
        // Loop through each column up to the halfway point
        for (int j = 0; j < width / 2; j++)
        {
            // Swap the current pixel with its reflection across the middle
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the original image to read from
    RGBTRIPLE copy[height][width];
    memcpy(copy, image, sizeof(RGBTRIPLE) * height * width);

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int red = 0;
            int green = 0;
            int blue = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int col = j + l;
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        count++;
                        red += copy[row][col].rgbtRed;
                        green += copy[row][col].rgbtGreen;
                        blue += copy[row][col].rgbtBlue;
                    }
                }
            }
            image[i][j].rgbtRed = round((float) red / count);
            image[i][j].rgbtGreen = round((float) green / count);
            image[i][j].rgbtBlue = round((float) blue / count);
        }
    }
}

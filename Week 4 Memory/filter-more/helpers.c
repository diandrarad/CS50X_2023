#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[j][i].rgbtRed + image[j][i].rgbtGreen + image[j][i].rgbtBlue) / 3.0);
            image[j][i].rgbtRed = avg;
            image[j][i].rgbtGreen = avg;
            image[j][i].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
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
    // Create a copy of the original image to avoid modifying pixels that we still need to use for future calculations
    RGBTRIPLE copy[height][width];
    memcpy(copy, image, sizeof(RGBTRIPLE) * height * width);

    // Iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average color values of neighboring pixels
            int count = 0;
            int red = 0;
            int green = 0;
            int blue = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    // Check if the neighboring pixel is within the bounds of the image
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

            // Calculate the average color values
            image[i][j].rgbtRed = round((float) red / count);
            image[i][j].rgbtGreen = round((float) green / count);
            image[i][j].rgbtBlue = round((float) blue / count);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temporary array to store the filtered image
    RGBTRIPLE filtered[height][width];

    // Define the Gx and Gy kernels
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize Gx and Gy values for each channel
            int redx = 0, greenx = 0, bluex = 0;
            int redy = 0, greeny = 0, bluey = 0;

            // Loop through the surrounding pixels using the Gx and Gy kernels
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    // Calculate row and column indices of surrounding pixel
                    int row = i + k;
                    int col = j + l;

                    // Treat out-of-bounds pixels as solid black
                    if (row < 0 || row >= height || col < 0 || col >= width)
                    {
                        continue;
                    }

                    // Apply Gx and Gy kernels to surrounding pixel values
                    redx += Gx[k + 1][l + 1] * image[row][col].rgbtRed;
                    greenx += Gx[k + 1][l + 1] * image[row][col].rgbtGreen;
                    bluex += Gx[k + 1][l + 1] * image[row][col].rgbtBlue;

                    redy += Gy[k + 1][l + 1] * image[row][col].rgbtRed;
                    greeny += Gy[k + 1][l + 1] * image[row][col].rgbtGreen;
                    bluey += Gy[k + 1][l + 1] * image[row][col].rgbtBlue;
                }
            }

            // Calculate final G value for each channel using Sobel filter
            int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));
            int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));
            int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

            // Cap channel values at 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            // Update pixel in filtered image with final G values
            filtered[i][j].rgbtRed = red;
            filtered[i][j].rgbtGreen = green;
            filtered[i][j].rgbtBlue = blue;
        }
    }
    // Copy filtered image back into original image array
    memcpy(image, filtered, sizeof(RGBTRIPLE) * height * width);
}

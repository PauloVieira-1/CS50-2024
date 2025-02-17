#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;

            BYTE avg = (BYTE) round((float) (red + green + blue) / 3.0);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        };
    };
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE pixel;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            pixel = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = pixel;
        }
    };

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_total = 0;
            int green_total = 0;
            int blue_total = 0;
            int pixel_count = 0;

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    int neighbor_i = i + x;
                    int neighbor_j = j + y;

                    if (neighbor_i >= 0 && neighbor_i < height && neighbor_j >= 0 &&
                        neighbor_j < width)
                    {
                        red_total += image[neighbor_i][neighbor_j].rgbtRed;
                        green_total += image[neighbor_i][neighbor_j].rgbtGreen;
                        blue_total += image[neighbor_i][neighbor_j].rgbtBlue;
                        pixel_count++;
                    }
                }
            }

            temp[i][j].rgbtRed = (int) round((float) red_total / (float) pixel_count);
            temp[i][j].rgbtGreen = (int) round((float) green_total / (float) pixel_count);
            temp[i][j].rgbtBlue = (int) round((float) blue_total / (float) pixel_count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int g_x[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int g_y[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_total_x = 0;
            int green_total_x = 0;
            int blue_total_x = 0;

            int red_total_y = 0;
            int green_total_y = 0;
            int blue_total_y = 0;

            int new_channel_red = 0;
            int new_channel_green = 0;
            int new_channel_blue = 0;

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    int neighbor_i = i + x;
                    int neighbor_j = j + y;

                    if (neighbor_i >= 0 && neighbor_i < height && neighbor_j >= 0 &&
                        neighbor_j < width)
                    {
                        red_total_x += (image[neighbor_i][neighbor_j].rgbtRed) * g_x[x + 1][y + 1];
                        green_total_x +=
                            (image[neighbor_i][neighbor_j].rgbtGreen) * g_x[x + 1][y + 1];
                        blue_total_x +=
                            (image[neighbor_i][neighbor_j].rgbtBlue) * g_x[x + 1][y + 1];

                        red_total_y += (image[neighbor_i][neighbor_j].rgbtRed) * g_y[x + 1][y + 1];
                        green_total_y +=
                            (image[neighbor_i][neighbor_j].rgbtGreen) * g_y[x + 1][y + 1];
                        blue_total_y +=
                            (image[neighbor_i][neighbor_j].rgbtBlue) * g_y[x + 1][y + 1];
                    }
                }
            }

            new_channel_red +=
                (int) round((float) sqrt(pow(red_total_x, 2) + (float) pow(red_total_y, 2)));
            new_channel_green +=
                (int) round(sqrt((float) pow(green_total_x, 2) + (float) pow(green_total_y, 2)));
            new_channel_blue +=
                (int) round(sqrt((float) pow(blue_total_x, 2) + (float) pow(blue_total_y, 2)));

            if (new_channel_red > 255)temp[i][j].rgbtRed = 255; else temp[i][j].rgbtRed =  new_channel_red;
            if (new_channel_green > 255) temp[i][j].rgbtGreen = 255; else temp[i][j].rgbtGreen =  new_channel_green;
            if (new_channel_blue > 255) temp[i][j].rgbtBlue = 255; else temp[i][j].rgbtBlue =  new_channel_blue;

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}

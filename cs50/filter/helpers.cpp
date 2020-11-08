#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avgGray;

    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculating the avg gray
            avgGray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.000);

            // inserting the values;
            image[i][j].rgbtRed = avgGray;
            image[i][j].rgbtGreen = avgGray;
            image[i][j].rgbtBlue = avgGray;
        }
    }
}

// limit function for sepia effect
int limit(int data)
{
    if (data > 255)
    {
        return 255;
    }

    return data;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate sepia values
            sepiaRed = limit(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = limit(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = limit(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // assign to them
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int swapRed;
    int swapGreen;
    int swapBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // move left side to the swap
            swapRed = image[i][j].rgbtRed;
            swapGreen = image[i][j].rgbtGreen;
            swapBlue = image[i][j].rgbtBlue;

            // right side to the left
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;

            // left side to the right
            image[i][width - 1 - j].rgbtRed = swapRed;
            image[i][width - 1 - j].rgbtGreen = swapGreen;
            image[i][width - 1 - j].rgbtBlue = swapBlue;
        }
    }
}

// Blur image
void bplur(int height, int width, RGBTRIPLE image[height][width])
{
    // declareVariableSums
    int sumRed = 0;
    int sumGreen = 0;
    int sumBlue = 0;
    int count = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate first row
            // do if 1st row exists
            if (i - 1 > 1 && i + 1 < height)
            {
                // do if 1st column exists
                if (j - 1 >= 0 && j - 1 < width)
                {
                    sumRed += image[i - 1][j - 1].rgbtRed;
                    sumGreen += image[i - 1][j - 1].rgbtGreen;
                    sumBlue += image[i - 1][j - 1].rgbtBlue;
                    count++;
                }

                // do if 2nd column exists
                if (j >=0 )
                {
                    sumRed += image[i - 1][j].rgbtRed;
                    sumGreen += image[i - 1][j].rgbtGreen;
                    sumBlue += image[i - 1][j].rgbtBlue;
                    count++;
                }

                // do if 3rd column exists
                if (j + 1 >= 0 && j + 1 < width)
                {
                    sumRed += image[i - 1][j + 1].rgbtRed;
                    sumGreen += image[i - 1][j + 1].rgbtGreen;
                    sumBlue += image[i - 1][j + 1].rgbtBlue;
                    count++;
                }
            }

            // calculate second row
            // do if 2nd row eists
            if (i >= 0 && i + 1 < height)
            {
                // do if 1st column exists
                if (j - 1 >= 0 && j - 1 < width)
                {
                    sumRed += image[i][j - 1].rgbtRed;
                    sumGreen += image[i][j - 1].rgbtGreen;
                    sumBlue += image[i][j - 1].rgbtBlue;
                    count++;
                }

                // do if 2nd column exists
                if (j >=0 )
                {
                    sumRed += image[i][j].rgbtRed;
                    sumGreen += image[i][j].rgbtGreen;
                    sumBlue += image[i][j].rgbtBlue;
                    count++;
                }

                // do if 3rd column exists
                if (j + 1 >= 0 && j + 1 < width) {
                    sumRed += image[i][j + 1].rgbtRed;
                    sumGreen += image[i][j + 1].rgbtGreen;
                    sumBlue += image[i][j + 1].rgbtBlue;
                    count++;
                }
            }

            // calculate third row
            // do if 3rd row exists
            if (i + 1 >=0 && i + 1 < height)
            {

                // do if 1st column exists
                if (j - 1 >= 0 && j - 1 <= width)
                {
                    sumRed += image[i + 1][j - 1].rgbtRed;
                    sumGreen += image[i + 1][j - 1].rgbtGreen;
                    sumBlue += image[i + 1][j - 1].rgbtBlue;
                    count++;
                }

                // do if 2nd column exists
                if (j >= 0)
                {
                    sumRed += image[i + 1][j].rgbtRed;
                    sumGreen += image[i + 1][j].rgbtGreen;
                    sumBlue += image[i + 1][j].rgbtBlue;
                    count++;
                }

                // do if 3rd column exists
                if (j + 1 >= 0 && j + 1 < width)
                {
                    sumRed += image[i + 1][j + 1].rgbtRed;
                    sumGreen += image[i + 1][j + 1].rgbtGreen;
                    sumBlue += image[i + 1][j + 1].rgbtBlue;
                    count++;
                }
            }

            // insert blurred value
            if (count > 0)
            {
                image[i][j].rgbtRed = sumRed / count;
                image[i][j].rgbtGreen = sumGreen / count;
                image[i][j].rgbtBlue = sumBlue / count;
            }

            // reset
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;
            count = 0;
        }
    }
    return;
}

#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //make temp image
    RGBTRIPLE temp[height][width];
    //make temp RGB counter
    float temprgb = 0.0;
    //loop through image and round
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temprgb = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue);
            temprgb = temprgb / 3;
            temp[i][j].rgbtRed = round(temprgb);
            temp[i][j].rgbtGreen = round(temprgb);
            temp[i][j].rgbtBlue = round(temprgb);
        }
    }
    //make the new image
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed =  temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;

}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //make temp img
    RGBTRIPLE temp[height][width];
    //loop though
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp[i][j] = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue;
    int sumGreen;
    int sumRed;
    //create a temporary table
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            //Top row
            if (i == 0)
            {
                if (j == 0) //top row left corner
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i + 1][j + 1].rgbtBlue) / 4);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j + 1].rgbtGreen
                                          +  image[i + 1][j].rgbtGreen
                                          +  image[i + 1][j + 1].rgbtGreen) / 4);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j + 1].rgbtRed
                                        + image[i + 1][j].rgbtRed
                                        + image[i + 1][j + 1].rgbtRed) / 4);

                }

                else if (j == width - 1) //top row right corner
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i + 1][j - 1].rgbtBlue) / 4);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j - 1].rgbtGreen
                                          + image[i + 1][j].rgbtGreen
                                          + image[i + 1][j - 1].rgbtGreen) / 4);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j - 1].rgbtRed
                                        + image[i + 1][j].rgbtRed
                                        + image[i + 1][j - 1].rgbtRed) / 4);
                }

                else //top row middle pixel
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i + 1][j - 1].rgbtBlue
                                         + image[i + 1][j + 1].rgbtBlue) / 6);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j - 1].rgbtGreen
                                          + image[i][j + 1].rgbtGreen
                                          + image[i + 1][j].rgbtGreen
                                          + image[i + 1][j - 1].rgbtGreen
                                          + image[i + 1][j + 1].rgbtGreen) / 6);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j - 1].rgbtRed
                                        + image[i][j + 1].rgbtRed
                                        + image[i + 1][j].rgbtRed
                                        + image[i + 1][j - 1].rgbtRed
                                        + image[i + 1][j + 1].rgbtRed) / 6);
                }

            }
            //Bottom row of image
            else if (i == height - 1)
            {
                //left side pixel of bottom row
                if (j == 0)
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i - 1][j + 1].rgbtBlue) / 4);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j + 1].rgbtGreen
                                          + image[i - 1][j].rgbtGreen
                                          + image[i - 1][j + 1].rgbtGreen) / 4);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j + 1].rgbtRed
                                        + image[i - 1][j].rgbtRed
                                        + image[i - 1][j + 1].rgbtRed) / 4);
                }
                //right side pixel of last row
                else if (j == width - 1)
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i - 1][j - 1].rgbtBlue) / 4);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j - 1].rgbtGreen
                                          + image[i - 1][j].rgbtGreen
                                          + image[i - 1][j - 1].rgbtGreen) / 4);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j - 1].rgbtRed
                                        + image[i - 1][j].rgbtRed
                                        + image[i - 1][j - 1].rgbtRed) / 4);
                }
                //middle pixels of last row
                else
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i - 1][j - 1].rgbtBlue
                                         + image[i - 1][j + 1].rgbtBlue) / 6);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j - 1].rgbtGreen
                                          + image[i][j + 1].rgbtGreen
                                          + image[i - 1][j].rgbtGreen
                                          + image[i - 1][j - 1].rgbtGreen
                                          + image[i - 1][j + 1].rgbtGreen) / 6);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j - 1].rgbtRed
                                        + image[i][j + 1].rgbtRed
                                        + image[i - 1][j].rgbtRed
                                        + image[i - 1][j - 1].rgbtRed
                                        + image[i - 1][j + 1].rgbtRed) / 6);
                }

            }

            else
            {
                //left side of image
                if (j == 0)
                {
                    //6 pixels surrounding the left side of the image
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i - 1][j + 1].rgbtBlue
                                         + image[i + 1][j + 1].rgbtBlue) / 6);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          +  image[i - 1][j].rgbtGreen
                                          +  image[i + 1][j].rgbtGreen
                                          +  image[i][j + 1].rgbtGreen
                                          +  image[i - 1][j + 1].rgbtGreen
                                          +  image[i + 1][j + 1].rgbtGreen) / 6);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        +  image[i - 1][j].rgbtRed
                                        +  image[i + 1][j].rgbtRed
                                        +  image[i][j + 1].rgbtRed
                                        +  image[i - 1][j + 1].rgbtRed
                                        +  image[i + 1][j + 1].rgbtRed) / 6);
                }

                //Right side of image
                else if (j == width - 1)
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i - 1][j - 1].rgbtBlue
                                         + image[i + 1][j - 1].rgbtBlue) / 6);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          +  image[i - 1][j].rgbtGreen
                                          +  image[i + 1][j].rgbtGreen
                                          +  image[i][j - 1].rgbtGreen
                                          +  image[i - 1][j - 1].rgbtGreen
                                          +  image[i + 1][j - 1].rgbtGreen) / 6);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        +  image[i - 1][j].rgbtRed
                                        +  image[i + 1][j].rgbtRed
                                        +  image[i][j - 1].rgbtRed
                                        +  image[i - 1][j - 1].rgbtRed
                                        +  image[i + 1][j - 1].rgbtRed) / 6);
                }
                //middle pixels of middle rows
                else
                {
                    //calculate for blue pixels
                    sumBlue = round(ceil(image[i - 1][j - 1].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i - 1][j + 1].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i][j].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i + 1][j - 1].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i + 1][j + 1].rgbtBlue) / 9);
                    //calculate for green pixels
                    // 9 pixels surrounding the middle one
                    sumGreen = round(ceil(image[i - 1][j - 1].rgbtGreen
                                          + image[i - 1][j].rgbtGreen
                                          + image[i - 1][j + 1].rgbtGreen
                                          + image[i][j - 1].rgbtGreen
                                          + image[i][j].rgbtGreen
                                          + image[i][j + 1].rgbtGreen
                                          + image[i + 1][j - 1].rgbtGreen
                                          + image[i + 1][j].rgbtGreen
                                          + image[i + 1][j + 1].rgbtGreen) / 9);
                    //calculate for red pixels
                    sumRed = round(ceil(image[i - 1][j - 1].rgbtRed
                                        + image[i - 1][j].rgbtRed
                                        + image[i - 1][j + 1].rgbtRed
                                        + image[i][j - 1].rgbtRed
                                        + image[i][j].rgbtRed
                                        + image[i][j + 1].rgbtRed
                                        + image[i + 1][j - 1].rgbtRed
                                        + image[i + 1][j].rgbtRed
                                        + image[i + 1][j + 1].rgbtRed) / 9);
                }
            }

            //assign temp values with the calculated values
            temp[i][j].rgbtBlue = round((sumBlue));
            temp[i][j].rgbtGreen = round((sumGreen));
            temp[i][j].rgbtRed = round((sumRed));

        }
    }

    //copies values from temporary table and assigns to original image
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            //assiging temp value to original image
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }

    return;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //make var
    int sqrtRedd;
    int sqrtGreenn;
    int sqrtBluee;

    //make copy of image
    RGBTRIPLE copy[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }

    //loop through pixels
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //make the variables
            int GXred = 0;
            int GYred = 0;
            int GXgreen = 0;
            int GYgreen = 0;
            int GXblue = 0;
            int GYblue = 0;
            //make factors of gx gy
            int index = 0;
            int factorsX[] = {-1,  0,  1, -2, 0, 2, -1, 0, 1};
            int factorsY[] = {-1, -2, -1,  0, 0, 0,  1, 2, 1};

            //form 3x3 grid loop
            for (int hh = -1; hh <= 1; hh++)
            {
                for (int ww = -1; ww <= 1; ww++)
                {
                    int x = w + ww;
                    int y = h + hh;
                    if (y >= 0 && y < height && x >= 0 && x < width)
                    {
                        GXred += factorsX[index] * copy[y][x].rgbtRed;
                        GYred += factorsY[index] * copy[y][x].rgbtRed;

                        GXgreen += factorsX[index] * copy[y][x].rgbtGreen;
                        GYgreen += factorsY[index] * copy[y][x].rgbtGreen;

                        GXblue += factorsX[index] * copy[y][x].rgbtBlue;
                        GYblue += factorsY[index] * copy[y][x].rgbtBlue;
                    }
                    index++;
                }
            }
            //round the gx gy
            int red = round(sqrt(GXred * GXred + GYred * GYred));
            int green = round(sqrt(GXgreen * GXgreen + GYgreen * GYgreen));
            int blue = round(sqrt(GXblue * GXblue + GYblue * GYblue));
            //check for not over 255
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
            //edge image create
            image[h][w].rgbtRed = red;
            image[h][w].rgbtGreen = green;
            image[h][w].rgbtBlue = blue;
        }
    }

    return;
}


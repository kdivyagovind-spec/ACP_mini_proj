#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 30
#define COLS 60

char canvas[ROWS][COLS];

void initializeCanvas()
{
    int i, j;
    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLS; j++)
            canvas[i][j] = '_';
}

void displayCanvas()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
            printf("%c", canvas[i][j]);

        printf("\n");
    }
}

void plot(int x, int y, char ch)
{
    if(x >= 0 && x < ROWS && y >= 0 && y < COLS)
        canvas[x][y] = ch;
}

void drawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while(1)
    {
        plot(x1, y1, ch);

        if(x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if(e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if(e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void drawRectangle(int row, int col, int width, int height, char ch)
{
    int i;

    for(i = 0; i < width; i++)
    {
        plot(row, col + i, ch);
        plot(row + height - 1, col + i, ch);
    }

    for(i = 0; i < height; i++)
    {
        plot(row + i, col, ch);
        plot(row + i, col + width - 1, ch);
    }
}

void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3,
                  char ch)
{
    drawLine(x1, y1, x2, y2, ch);
    drawLine(x2, y2, x3, y3, ch);
    drawLine(x3, y3, x1, y1, ch);
}

void drawCircle(int xc, int yc, int r, char ch)
{
    int x, y;

    for(x = 0; x < ROWS; x++)
    {
        for(y = 0; y < COLS; y++)
        {
            int d = (x - xc)*(x - xc) +
                    (y - yc)*(y - yc);

            if(abs(d - r*r) <= r)
                plot(x, y, ch);
        }
    }
}

int main()
{
    int choice;

    initializeCanvas();

    while(1)
    {
        printf("\n====== 2D GRAPHICS EDITOR ======\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Object\n");
        printf("6. Modify Object\n");
        printf("7. Display Canvas\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            int x1,y1,x2,y2;

            printf("Enter x1 y1 x2 y2: ");
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

            drawLine(x1,y1,x2,y2,'*');
        }

        else if(choice == 2)
        {
            int row,col,width,height;

            printf("Enter row col width height: ");
            scanf("%d%d%d%d",
                  &row,&col,&width,&height);

            drawRectangle(row,col,width,height,'*');
        }

        else if(choice == 3)
        {
            int x1,y1,x2,y2,x3,y3;

            printf("Enter x1 y1 x2 y2 x3 y3: ");
            scanf("%d%d%d%d%d%d",
                  &x1,&y1,&x2,&y2,&x3,&y3);

            drawTriangle(x1,y1,x2,y2,x3,y3,'*');
        }

        else if(choice == 4)
        {
            int xc,yc,r;

            printf("Enter center row center col radius: ");
            scanf("%d%d%d",&xc,&yc,&r);

            drawCircle(xc,yc,r,'*');
        }

        else if(choice == 5)
        {
            int row,col,width,height;

            printf("Delete Rectangle Area\n");
            printf("Enter row col width height: ");

            scanf("%d%d%d%d",
                  &row,&col,&width,&height);

            drawRectangle(row,col,width,height,'_');
        }

        else if(choice == 6)
        {
            int row,col,width,height;

            printf("Old rectangle:\n");
            scanf("%d%d%d%d",
                  &row,&col,&width,&height);

            drawRectangle(row,col,width,height,'_');

            printf("New rectangle:\n");
            scanf("%d%d%d%d",
                  &row,&col,&width,&height);

            drawRectangle(row,col,width,height,'*');
        }

        else if(choice == 7)
        {
            displayCanvas();
        }

        else if(choice == 8)
        {
            printf("Exiting...\n");
            break;
        }

        else
        {
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}

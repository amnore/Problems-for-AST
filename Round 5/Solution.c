#include <stdio.h>
char buf[2048][1024];
void print_angle(int startx, int starty, int depth)
{
    if (depth == 1)
    {
        buf[starty][startx] = ' ';
        buf[starty][startx + 1] = '/';
        buf[starty][startx + 2] = '\\';
        buf[starty][startx + 3] = ' ';
        buf[starty + 1][startx] = '/';
        buf[starty + 1][startx + 1] = buf[starty + 1][startx + 2] = '_';
        buf[starty + 1][startx + 3] = '\\';
        return;
    }
    for (int i = starty; i < starty + (1 << depth); ++i)
        for (int j = startx; j < startx + (1 << (depth - 1)); ++j)
            buf[i][j] = ' ';
    for (int i = starty; i < starty + (1 << depth); ++i)
        for (int j = startx + (1 << (depth - 1)) + (1 << depth); j < startx + (1 << (depth + 1)); ++j)
            buf[i][j] = ' ';
    print_angle(startx + (1 << (depth - 1)), starty, depth - 1);
    print_angle(startx, starty + (1 << (depth - 1)), depth - 1);
    print_angle(startx + (1 << depth), starty + (1 << (depth - 1)), depth - 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    print_angle(0, 0, n);
    for (int i = 0; i < (1 << n); ++i)
    {
        for (int j = 0; j < (1 << n) + i + 1; ++j)
            putchar(buf[i][j]);
        putchar('\n');
    }
    return 0;
}

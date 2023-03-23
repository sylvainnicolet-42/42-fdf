Set dot in Matrix
```C
void    matrix_set_dots(char *line, t_dot **matrix, int y)  
{  
   char   **dots;  
   int       x;  
  
   dots = ft_split(line, ' ');  
   x = 0;  
   while (dots[x])  
   {  
      set_dot_color(dots, matrix, x, y);  
      matrix[y][x].x = x;  
      matrix[y][x].y = y;  
      matrix[y][x].is_last = 0;  
      free(dots[x]);  
      x++;  
   }  
   free(dots);  
   matrix[y][x - 1].is_last = 1;  
}
```
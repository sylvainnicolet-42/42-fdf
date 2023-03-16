Set dot color and height
```C
static void set_dot_color(char **dot, t_dot **matrix, int x, int y)  
{  
   char   **z;  
  
   z = ft_split(dot[x], ',');  
   matrix[y][x].z = ft_atoi(z[0]);  
   if (ft_atoi(z[0]) && !z[1])  
      matrix[y][x].has_height = 1;  
   free(z[0]);  
   if (!z[1])  
      matrix[y][x].color = 0;  
   else if (z[1])  
   {      matrix[y][x].color = ft_hex_to_int(z[1]);  
      free(z[1]);  
   }  
   free(z);  
}
```
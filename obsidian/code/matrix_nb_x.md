Get number of columns (x)
```C
static int  matrix_nb_x(int fd)  
{  
   int    nb_x;  
   char   *line;  
  
   line = get_next_line(fd);  
   nb_x = ft_wdcounter(line, ' ');  
   free(line);  
   return (nb_x);  
}
```
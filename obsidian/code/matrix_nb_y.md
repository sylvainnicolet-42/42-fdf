Get number of rows (y)
```C
static int  matrix_nb_y(int fd)  
{  
   int    nb_y;  
   char   *line;  
  
   nb_y = 1;  
   line = get_next_line(fd);  
   while (line)  
   {  
      free(line);  
      line = get_next_line(fd);  
      nb_y++;  
   }  
   return (nb_y);  
}
```
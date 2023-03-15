Build Matrix
```C
void    matrix_build(t_dot **matrix, char *file_path)  
{  
   int       fd;  
   int       y;  
   char   *line;  
  
   fd = open(file_path, O_RDONLY, 0);  
   if (fd <= 0)  
      ft_print_error("File does not exist");  
   y = 0;  
   line = get_next_line(fd);  
   while (line)  
   {  
      matrix_set_dots(line, matrix, y);  
      free(line);  
      line = get_next_line(fd);  
      y++;  
   }  
   free(matrix[y]);  
   matrix[y] = NULL;  
   close(fd);  
}
```
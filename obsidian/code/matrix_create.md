❗️ Malloc
Create and allocate memory for new Matrix
```C
t_dot   **matrix_create(char *file_path)  
{  
   t_dot  **new_matrix;  
   int       x;  
   int       y;  
   int       fd;  
  
   fd = open(file_path, O_RDONLY, 0);  
   if (fd <= 0)  
      ft_print_error("File does not exist");  
   x = matrix_nb_x(fd);  
   y = matrix_nb_y(fd);  
   new_matrix = malloc(sizeof(t_dot *) * (y + 1));  
   if (!new_matrix)  
      ft_print_error("Malloc error");  
   while (y >= 0)  
   {  
      new_matrix[y] = malloc(sizeof(t_dot) * (x + 1));  
      if (!new_matrix[y])  
         ft_print_error("Malloc error");  
      y--;  
   }  
   close(fd);  
   return (new_matrix);  
}
```

Read the file and build the matrix
```C
t_dot   **read_map(char *file_path)  
{  
   t_dot  **matrix;  
  
   matrix = matrix_create(file_path);  
   matrix_build(matrix, file_path);  
   return (matrix);  
}
```
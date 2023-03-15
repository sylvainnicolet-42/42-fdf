```C
void    display_matrix(t_dot **matrix)  
{  
   int    i;  
   int    j;  
  
   i = 0;  
   while (matrix[i])  
   {  
      j = 0;  
      while (matrix[i][j].is_last == 0)  
      {  
         printf("x = %f, y = %f, z = %f\n", matrix[i][j].x, matrix[i][j].y, matrix[i][j].z);  
         j++;  
      }  
      printf("x = %f, y = %f, z = %f\n", matrix[i][j].x, matrix[i][j].y, matrix[i][j].z);  
      i++;  
   }  
}
```
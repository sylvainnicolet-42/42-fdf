Close properly FDF
```C
static void matrix_clear(t_dot **matrix)  
{  
   int    i;  
  
   i = 0;  
   while (matrix[i])  
   {  
      free(matrix[i]);  
      i++;  
   }  
   free(matrix);  
}
```

```C
int fdf_close(t_param *params)  
{  
   mlx_destroy_window(params->mlx_ptr, params->win_ptr);  
   matrix_clear(params->matrix);  
   free(params);  
   ft_print_success("FDF ended successfully! 🚀");  
   return (0);  
}
```
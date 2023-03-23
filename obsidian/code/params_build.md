❗️ Malloc
Init all parameters
```C
t_param *params_build(t_dot **matrix)  
{  
   t_param    *params;  
  
   params = malloc(sizeof(t_param));  
   if (!params)  
      ft_print_error("Malloc error");  
   params->matrix = matrix;  
   reset_params(params);  
   create_mlx(params);  
   create_img(params);  
   return (params);  
}
```
❗️ Malloc
Init all parameters
```C
t_param *params_build(t_dot **matrix)  
{  
   t_param *param;  
   void   *mlx_ptr;  
   void   *win_ptr;  
  
   param = malloc(sizeof(t_param));  
   if (!param)  
      ft_print_error("Malloc error");  
   param->matrix = matrix;  
   param->scale = 20;  
   param->z_scale = 1;  
   param->is_isometric = 1;  
   param->angle = 0.523599;  
   param->win_x = 800;  
   param->win_y = 800;  
   param->shift_x = param->win_x / 3;  
   param->shift_y = param->win_y / 3;  
   mlx_ptr = mlx_init();  
   if (!mlx_ptr)  
      ft_print_error("mlx_init error");  
   param->mlx_ptr = mlx_ptr;  
   win_ptr = mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");  
   if (!win_ptr)  
      ft_print_error("mlx_new_window error");  
   param->win_ptr = win_ptr;  
   return (param);  
}
```
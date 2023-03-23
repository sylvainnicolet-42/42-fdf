❗️ Malloc
Create mlx
```C
static void create_mlx(t_param *params)  
{  
   params->mlx_ptr = mlx_init();  
   if (!params->mlx_ptr)  
      ft_print_error("mlx_init error");  
   params->win_ptr = mlx_new_window(  
         params->mlx_ptr, params->win_x, params->win_y, "FDF");  
   if (!params->win_ptr)  
      ft_print_error("mlx_new_window error");  
}
```
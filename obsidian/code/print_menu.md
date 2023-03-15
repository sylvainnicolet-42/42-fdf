Print menu with usages
```C
void    print_menu(t_param *params)  
{  
   mlx_string_put(params->mlx_ptr, params->win_ptr, 10, 5, WHITE, "Usage");  
   print_usage(params, 35, "Move", "left up down right");  
   print_usage(params, 55, "Move", "a w s d");  
   print_usage(params, 75, "Zoom in", "scroll down");  
   print_usage(params, 95, "Zoom out", "scroll up");  
}
```
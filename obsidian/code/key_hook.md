Handle key press
```C
int key_hook(int key, t_param *params)  
{  
   if (is_key(key))  
   {  
      mlx_clear_window(params->mlx_ptr, params->win_ptr);  
      update_params(key, params);  
      print_menu(params);  
      draw(params);  
   }  
   return (0);  
}
```
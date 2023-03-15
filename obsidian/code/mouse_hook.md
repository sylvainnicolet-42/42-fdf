```C
int mouse_hook(int button, int x, int y, t_param *params)  
{  
   (void) x;  
   (void) y;  
  
   if (is_button(button))  
   {  
      mlx_clear_window(params->mlx_ptr, params->win_ptr);  
      update_params(button, params);  
      print_menu(params);  
      draw(params);  
   }  
   return (0);  
}
```
```C
static int  is_button(int key)  
{  
   return (key == MOUSE_SCROLL_DOWN || key == MOUSE_SCROLL_UP);  
}
```

```C
static void update_params(int button, t_param *params)  
{  
   if (button == MOUSE_SCROLL_DOWN)  
      params->scale += 3;  
   if (button == MOUSE_SCROLL_UP)  
      params->scale -= 3;  
}
```

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
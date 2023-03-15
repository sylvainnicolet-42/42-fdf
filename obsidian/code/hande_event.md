Handle events on the window
```C
void    handle_event(t_param *params)  
{  
   mlx_key_hook(params->win_ptr, key_hook, params);  
   mlx_mouse_hook(params->win_ptr, mouse_hook, params);  
   mlx_hook(params->win_ptr, ON_DESTROY, KEY_PRESS_MASK, fdf_close, params);  
}
```
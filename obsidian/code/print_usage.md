Print usage
```C
static void print_usage(t_param *params, int y, char *label, char *key)  
{  
   mlx_string_put(params->mlx_ptr, params->win_ptr, 25, y, WHITE, label);  
   mlx_string_put(params->mlx_ptr, params->win_ptr, 200, y, WHITE, key);  
}
```
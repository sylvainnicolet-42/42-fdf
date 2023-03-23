
```C
void    image_refresh(t_param *params)  
{  
   mlx_destroy_image(params->mlx_ptr, params->img->img_ptr);  
   params->img->img_ptr = mlx_new_image(  
         params->mlx_ptr, params->win_x, params->win_y);  
   params->img->addr = mlx_get_data_addr(  
         params->img->img_ptr, &params->img->bits_per_pixel,  
         &params->img->line_length, &params->img->endian);  
   draw(params);  
}
```
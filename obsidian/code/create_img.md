❗️ Malloc
Create image
```C
static void create_img(t_param *params)  
{  
   t_img  *img;  
  
   img = malloc(sizeof(t_img));  
   if (!img)  
      ft_print_error("Malloc error");  
   img->img_ptr = mlx_new_image(  
         params->mlx_ptr, params->win_x, params->win_y);  
   if (!img->img_ptr)  
      ft_print_error("mlx_new_image error");  
   img->addr = mlx_get_data_addr(  
         img->img_ptr, &img->bits_per_pixel,  
         &img->line_length, &img->endian);  
   params->img = img;  
}
```
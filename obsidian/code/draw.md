Draw the matrix
```C
void    draw(t_param *params)  
{  
   int    y;  
   int    x;  
  
   y = 0;  
   while (params->matrix[y])  
   {  
      x = 0;  
      while (1)  
      {  
         // Draw the line between the current dot and the one below only if the current dot is not on the last line  
         if (params->matrix[y + 1])  
            line(params->matrix[y][x], params->matrix[y + 1][x], params);  
  
         // Draw the line between the current dot and the one on the right only if the current dot is not the last of the line  
         if (!params->matrix[y][x].is_last)  
            line(params->matrix[y][x], params->matrix[y][x + 1], params);  
  
         // Break the loop if the current dot is the last one of the line  
         if (params->matrix[y][x].is_last)  
            break ;  
         x++;  
      }  
      y++;  
   }
   mlx_put_image_to_window(  
     params->mlx_ptr, params->win_ptr, params->img->img_ptr, 0, 0);  
   print_menu(params);
}
```
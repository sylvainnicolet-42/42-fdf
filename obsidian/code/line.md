Draw a line between two points using Bresenham's line algorithm

```C
void    img_pix_put(t_param *params, int x, int y, int color)  
{  
   char   *pixel;  
  
   if (x >= 0 && x < params->win_x && y >= 0 && y < params->win_y)  
   {  
      pixel = params->img->addr  
         + (y * params->img->line_length  
            + x * (params->img->bits_per_pixel / 8));  
      *(int *)pixel = color;  
   }  
}
```

```C
static float    get_max(float step_x, float step_y)  
{  
   float  abs_step_x;  
   float  abs_step_y;  
   float  max;  
  
   if (step_x < 0)  
      abs_step_x = -step_x;  
   else      abs_step_x = step_x;  
   if (step_y < 0)  
      abs_step_y = -step_y;  
   else      abs_step_y = step_y;  
   if (abs_step_x > abs_step_y)  
      max = abs_step_x;  
   else      max = abs_step_y;  
   return (max);  
}
```

```C
static void line(t_dot a, t_dot b, t_param *params)  
{  
   float  step_x;  
   float  step_y;  
   float  max;  
   int       color;  
  
   refresh_params(&a, &b, params);  
   step_x = b.x - a.x;  
   step_y = b.y - a.y;  
   max = get_max(step_x, step_y);  
   step_x /= max;  
   step_y /= max;  
   color = get_color(a, b, params);  
   while ((int)(a.x - b.x) || (int)(a.y - b.y))  
   {  
      img_pix_put(params, a.x, a.y, color);  
      a.x += step_x;  
      a.y += step_y;  
   }  
}
```
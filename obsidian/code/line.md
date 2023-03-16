Draw a line between two points using Bresenham's line algorithm
```C
static int  get_color_from_params(t_param *params)  
{  
   if (params->color == P_BLACK)  
      return (BLACK);  
   else if (params->color == P_WHITE)  
      return (WHITE);  
   else if (params->color == P_RED)  
      return (RED);  
   else if (params->color == P_GREEN)  
      return (GREEN);  
   else if (params->color == P_BLUE)  
      return (BLUE);  
   else if (params->color == P_YELLOW)  
      return (YELLOW);  
   else if (params->color == P_PINK)  
      return (PINK);  
   else if (params->color == P_CYAN)  
      return (CYAN);  
   else if (params->color == P_ORANGE)  
      return (ORANGE);  
   else      return (P_COLOR);  
}
```

```C
static int  get_color(t_dot a, t_dot b, t_param *params)  
{  
   (void) params;  
   if (a.color)  
      return (a.color);  
   else if (b.color)  
      return (b.color);  
   if (a.has_height == 1 || b.has_height == 1)  
      return (get_color_from_params(params));  
   return (P_COLOR_GRID);  
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
      mlx_pixel_put(params->mlx_ptr, params->win_ptr, a.x, a.y, color);  
      a.x += step_x;  
      a.y += step_y;  
      if (a.x > params->win_x || a.y > params->win_y || a.y < 0 || a.x < 0)  
         break ;  
   }  
}
```
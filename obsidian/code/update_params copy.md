Update the params according to the key pressed
```C
static void update_params(int key, t_param *params)  
{  
if (key == KEY_ESC)  
   fdf_close(params);  
if (key == KEY_ARROW_LEFT || key == KEY_A)  
   params->shift_x += 10;  
if (key == KEY_ARROW_RIGHT || key == KEY_D)  
   params->shift_x -= 10;  
if (key == KEY_ARROW_DOWN || key == KEY_S)  
   params->shift_y -= 10;  
if (key == KEY_ARROW_UP || key == KEY_W)  
   params->shift_y += 10;  
if (key == KEY_P)  
{  
   if (params->projection == VIEW_TOP)  
      params->projection = 0;  
   else
	   params->projection++;  
}  
if (key == KEY_E)  
   params->angle += 0.05;  
if (key == KEY_R)  
   params->angle -= 0.05;  
}
```
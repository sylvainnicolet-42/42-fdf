Reset the parameters to default
```C
void    reset_params(t_param *params)  
{  
   params->scale = P_SCALE;  
   params->z_scale = P_Z_SCALE;  
   params->projection = P_PROJECTION;  
   params->win_x = P_WIN_X;  
   params->win_y = P_WIN_Y;  
   params->shift_x = params->win_x / 2;  
   params->shift_y = P_POS_Y;  
   params->color = P_COLOR;  
   params->angle = P_ANGLE * M_PI / 180;  
   params->alpha = P_ANGLE * M_PI / 180;  
   params->beta = 0;  
   params->teta = 0;  
}
```
Refresh the parameters
```C
void    refresh_params(t_dot *a, t_dot *b, t_param *params)  
{  
   zoom(a, b, params);  
   if (params->projection == VIEW_ISO)  
   {  
      x_rotation(a, b, params->alpha);  
      y_rotation(a, b, params->beta);  
      z_rotation(a, b, params->teta);  
      isometric(a, b, params);  
   }  
   shifting(a, b, params);  
}
```
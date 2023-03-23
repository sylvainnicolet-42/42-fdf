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

   // cette fonction met à jour les coordonnées des points de départ (`a`) et d'arrivée (`b`) en fonction des paramètres `params`.
   refresh_params(&a, &b, params);  
   // cette variable calcule la différence en x entre les points de départ et d'arrivée.
   step_x = b.x - a.x;  
   // cette variable calcule la différence en y entre les points de départ et d'arrivée.
   step_y = b.y - a.y;  
   // cette fonction détermine la plus grande différence entre `step_x` et `step_y`.
   max = get_max(step_x, step_y);  
   // cette étape normalise la différence en x par la valeur maximale (`max`).
   step_x /= max;
   // cette étape normalise la différence en y par la valeur maximale (`max`).  
   step_y /= max;  
   // cette fonction détermine la couleur de la ligne en fonction des paramètres `params` et des points de départ et d'arrivée.
   color = get_color(a, b, params);
   // cette boucle continue jusqu'à ce que les coordonnées de `a` atteignent celles de `b`.  
   while ((int)(a.x - b.x) || (int)(a.y - b.y))  
   {
      // cette fonction dessine un pixel à la position `(a.x, a.y)` avec la couleur `color`.
      img_pix_put(params, a.x, a.y, color);  
      // cette étape met à jour la coordonnée x de `a` en ajoutant la valeur normalisée de `step_x`.
      a.x += step_x;  
      // cette étape met à jour la coordonnée y de `a` en ajoutant la valeur normalisée de `step_y`.
      a.y += step_y;  
   }  
}
```
Refresh points for each behaviour
```C
void    zoom(t_dot *a, t_dot *b, t_param *params)  
{  
   a->x *= params->scale;  
   a->y *= params->scale;  
   b->x *= params->scale;  
   b->y *= params->scale;  
   a->z *= params->z_scale;  
   b->z *= params->z_scale;  
}
```

```C
void    shifting(t_dot *a, t_dot *b, t_param *params)  
{  
   a->x += params->shift_x;  
   a->y += params->shift_y;  
   b->x += params->shift_x;  
   b->y += params->shift_y;  
}
```

```C
// Ce code transforme les coordonnées 3D de deux points `a` et `b` en coordonnées isométriques 2D.
void    isometric(t_dot *a, t_dot *b, t_param *params)  
{  
   // cette ligne calcule la projection isométrique de la coordonnée x de `a` en soustrayant sa coordonnée y, puis en multipliant le résultat par le cosinus de l'angle de vue défini dans les paramètres `params`. Cela donne une projection de la coordonnée x en perspective isométrique.
   a->x = (a->x - a->y) * cos(params->angle);  
   a->y = (a->x + a->y) * sin(params->angle) - a->z;  
   b->x = (b->x - b->y) * cos(params->angle);  
   b->y = (b->x + b->y) * sin(params->angle) - b->z;  
}
```

```C
void    x_rotation(t_dot *a, t_dot *b, double alpha)  
{  
   a->y = a->y * cos(alpha) + a->z * sin(alpha);  
   a->z = -(a->y) * sin(alpha) + a->z * (cos(alpha));  
   b->y = b->y * cos(alpha) + b->z * sin(alpha);  
   b->z = -(b->y) * sin(alpha) + b->z * (cos(alpha));  
}
```

```C
void    y_rotation(t_dot *a, t_dot *b, double beta)  
{  
   a->x = a->x * cos(beta) + a->z * sin(beta);  
   a->z = -(a->x) * sin(beta) + a->z * (cos(beta));  
   b->x = b->x * cos(beta) + b->z * sin(beta);  
   b->z = -(b->x) * sin(beta) + b->z * (cos(beta));  
}
```

```C
void    z_rotation(t_dot *a, t_dot *b, double teta)  
{  
   a->x = a->x * cos(teta) - a->y * sin(teta);  
   a->y = (a->x) * sin(teta) + a->y * (cos(teta));  
   b->x = b->x * cos(teta) - b->y * sin(teta);  
   b->y = (b->x) * sin(teta) + b->y * (cos(teta));  
}
```
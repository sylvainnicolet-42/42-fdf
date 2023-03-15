```C
typedef struct s_dot  
{  
   float     x;  
   float     y;  
   float     z;  
   int       is_last;  
  
   int       color;  
   int       scale;  
   int       z_scale;  
   int       shift_x;  
   int       shift_y;  
   int       is_isometric;  
   double    angle;  
   int       win_x;  
   int       win_y;  
   void      *mlx_ptr;  
   void      *win_ptr;  
}  t_dot;
```
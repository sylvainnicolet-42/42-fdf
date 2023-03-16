```C
typedef struct s_param  
{  
   t_dot  **matrix;  
   int       scale;  
   int       z_scale;  
   int       shift_x;  
   int       shift_y;  
   int       color;  
   int       projection;  
   int       win_x;  
   int       win_y;  
   void   *mlx_ptr;  
   void   *win_ptr;  
   double angle;  
   double alpha;  
   double beta;  
   double teta;  
}  t_param;
```
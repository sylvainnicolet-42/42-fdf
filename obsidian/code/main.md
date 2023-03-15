```C
int main(int argc, char **argv)  
{  
   t_dot  **matrix;  
   t_param *params;  
  
   if (argc == 2)  
   {  
      matrix = read_map(argv[1]);  
      params = params_build(matrix);  
      draw(params);  
      handle_event(params);  
      mlx_loop(params->mlx_ptr);  
   }  
   else  
      ft_print_error("Usage : ./fdf [file]");  
   return (0);  
}
```
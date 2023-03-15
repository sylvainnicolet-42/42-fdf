Check if the key is one of the keys we want to handle
```C
static int  is_key(int key)  
{  
   return (key == KEY_ESC || key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT  
      || key == KEY_ARROW_DOWN || key == KEY_ARROW_UP || key == KEY_A  
      || key == KEY_S || key == KEY_D || key == KEY_W || key == KEY_P  
      || key == KEY_E || key == KEY_R  
   );  
}
```
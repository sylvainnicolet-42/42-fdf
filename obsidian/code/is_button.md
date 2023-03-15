Check if the key is one of the keys we want to handle
```C
static int  is_button(int key)  
{  
   return (key == MOUSE_SCROLL_DOWN || key == MOUSE_SCROLL_UP);  
}
```
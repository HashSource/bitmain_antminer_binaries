
void str_free(void *ptr)

{
  if (free_debug_func != (code *)0x0) {
    (*free_debug_func)(ptr,0);
  }
  (*free_func)(ptr);
  if (free_debug_func != (code *)0x0) {
    (*free_debug_func)(0,1);
  }
  return;
}


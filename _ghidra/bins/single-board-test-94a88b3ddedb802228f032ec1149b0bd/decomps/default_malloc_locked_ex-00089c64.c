
void default_malloc_locked_ex(void)

{
  (*malloc_locked_func)();
  return;
}


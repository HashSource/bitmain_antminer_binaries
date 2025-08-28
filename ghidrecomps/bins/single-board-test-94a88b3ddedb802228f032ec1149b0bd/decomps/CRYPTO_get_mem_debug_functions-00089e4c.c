
void CRYPTO_get_mem_debug_functions(m **m,r **r,f **f,so **so,go **go)

{
  if (m != (m **)0x0) {
    *m = malloc_debug_func;
  }
  if (r != (r **)0x0) {
    *r = realloc_debug_func;
  }
  if (f != (f **)0x0) {
    *f = free_debug_func;
  }
  if (so != (so **)0x0) {
    *so = set_debug_options_func;
  }
  if (go != (go **)0x0) {
    *go = get_debug_options_func;
  }
  return;
}



/* WARNING: Unknown calling convention */

void json_set_alloc_funcs(json_malloc_t malloc_fn,json_free_t free_fn)

{
  do_malloc = malloc_fn;
  do_free = free_fn;
  return;
}


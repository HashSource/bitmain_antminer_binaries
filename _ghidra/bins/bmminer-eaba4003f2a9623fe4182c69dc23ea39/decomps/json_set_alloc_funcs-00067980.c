
void json_set_alloc_funcs(json_malloc_t malloc_fn,json_free_t free_fn)

{
  json_free_t free_fn_local;
  json_malloc_t malloc_fn_local;
  
  do_malloc = malloc_fn;
  do_free = free_fn;
  return;
}


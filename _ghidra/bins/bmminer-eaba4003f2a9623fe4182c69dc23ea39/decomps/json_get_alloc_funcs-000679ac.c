
void json_get_alloc_funcs(json_malloc_t *malloc_fn,json_free_t *free_fn)

{
  json_free_t *free_fn_local;
  json_malloc_t *malloc_fn_local;
  
  if (malloc_fn != (json_malloc_t *)0x0) {
    *malloc_fn = do_malloc;
  }
  if (free_fn != (json_free_t *)0x0) {
    *free_fn = do_free;
  }
  return;
}


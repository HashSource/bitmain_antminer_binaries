
/* WARNING: Unknown calling convention */

void _jsonp_free(void **ptr)

{
  if (*ptr != (void *)0x0) {
    (*do_free)(*ptr);
    *ptr = (void *)0x0;
  }
  return;
}


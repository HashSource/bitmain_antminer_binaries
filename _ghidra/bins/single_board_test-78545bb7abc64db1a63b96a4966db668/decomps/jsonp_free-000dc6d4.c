
/* WARNING: Unknown calling convention */

void jsonp_free(void *ptr)

{
  if (ptr != (void *)0x0) {
    (*do_free)(ptr);
  }
  return;
}


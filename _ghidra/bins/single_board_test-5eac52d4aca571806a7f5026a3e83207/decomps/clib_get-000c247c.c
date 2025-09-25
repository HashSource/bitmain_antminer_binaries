
/* WARNING: Unknown calling convention */

void clib_get(void *destination,void *source,size_t size)

{
  memcpy(destination,source,size);
  return;
}


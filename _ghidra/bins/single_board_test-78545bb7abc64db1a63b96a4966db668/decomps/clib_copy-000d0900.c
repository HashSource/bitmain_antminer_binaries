
/* WARNING: Unknown calling convention */

void clib_copy(void *destination,void *source,size_t size)

{
  memcpy(destination,source,size);
  return;
}


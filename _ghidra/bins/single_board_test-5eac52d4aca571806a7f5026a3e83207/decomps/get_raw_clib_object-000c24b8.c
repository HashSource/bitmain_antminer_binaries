
/* WARNING: Unknown calling convention */

clib_error get_raw_clib_object(clib_object *inObject,void **elem)

{
  void *__dest;
  size_t __size;
  
  __size = inObject->size;
  __dest = malloc(__size);
  *elem = __dest;
  if (__dest != (void *)0x0) {
    memcpy(__dest,inObject->raw_data,__size);
    return 0;
  }
  return 3;
}


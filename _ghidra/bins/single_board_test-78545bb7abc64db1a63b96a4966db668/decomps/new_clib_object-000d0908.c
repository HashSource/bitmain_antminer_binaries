
/* WARNING: Unknown calling convention */

clib_object * new_clib_object(void *inObject,size_t obj_size)

{
  clib_object *__ptr;
  void *__dest;
  
  __ptr = (clib_object *)malloc(8);
  if (__ptr == (clib_object *)0x0) {
    return (clib_object *)0x0;
  }
  __ptr->size = obj_size;
  __dest = malloc(obj_size);
  __ptr->raw_data = __dest;
  if (__dest != (void *)0x0) {
    memcpy(__dest,inObject,obj_size);
    return __ptr;
  }
  free(__ptr);
  return (clib_object *)0x0;
}


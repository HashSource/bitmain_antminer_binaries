
/* WARNING: Unknown calling convention */

void * get_value_c_map(void *pObject)

{
  void *elem;
  
  get_raw_clib_object((clib_object *)pObject,&elem);
  return elem;
}


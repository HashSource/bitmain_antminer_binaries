
/* WARNING: Unknown calling convention */

void replace_raw_clib_object(clib_object *current_object,void *elem,size_t elem_size)

{
  void *__dest;
  
  free(current_object->raw_data);
  __dest = malloc(elem_size);
  current_object->raw_data = __dest;
  memcpy(__dest,elem,elem_size);
  return;
}


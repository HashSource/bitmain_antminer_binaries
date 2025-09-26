
/* WARNING: Unknown calling convention */

clib_error remove_c_map(clib_map *pMap,void *key)

{
  clib_rb_node *__ptr;
  void *removed_node;
  
  if (pMap != (clib_map *)0x0) {
    __ptr = remove_c_rb(pMap->root,key);
    if (__ptr != (clib_rb_node *)0x0) {
      get_raw_clib_object(__ptr->key,&removed_node);
      free(removed_node);
      delete_clib_object(__ptr->key);
      get_raw_clib_object(__ptr->value,&removed_node);
      free(removed_node);
      delete_clib_object(__ptr->value);
      free(__ptr);
      __ptr = (clib_rb_node *)0x0;
    }
    return (clib_error)__ptr;
  }
  return 0x1f5;
}


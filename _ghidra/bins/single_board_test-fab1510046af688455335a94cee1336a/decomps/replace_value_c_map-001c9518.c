
/* WARNING: Unknown calling convention */

void replace_value_c_map(clib_iterator *pIterator,void *elem,size_t elem_size)

{
  clib_map *pMap;
  int *piVar1;
  void *old_element;
  
  piVar1 = (int *)pIterator->pContainer;
  if (*(int *)(*piVar1 + 0x20) != 0) {
    get_raw_clib_object(*(clib_object **)((int)pIterator->pCurrentElement + 0x14),&old_element);
    (**(code **)(*piVar1 + 0x20))(old_element);
  }
  replace_raw_clib_object(*(clib_object **)((int)pIterator->pCurrentElement + 0x14),elem,elem_size);
  return;
}


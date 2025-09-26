
/* WARNING: Unknown calling convention */

clib_iterator * new_iterator_c_map(clib_map *pMap)

{
  clib_iterator *pcVar1;
  
  pcVar1 = (clib_iterator *)malloc(0x18);
  pcVar1->pContainer = pMap;
  pcVar1->get_next = (_func_clib_object_ptr_clib_iterator_ptr *)0x1c954d;
  pcVar1->get_value = (_func_void_ptr_void_ptr *)0x1c9505;
  pcVar1->replace_value = (_func_void_clib_iterator_ptr_void_ptr_size_t *)0x1c9519;
  pcVar1->pCurrent = 0;
  pcVar1->pCurrentElement = (void *)0x0;
  return pcVar1;
}


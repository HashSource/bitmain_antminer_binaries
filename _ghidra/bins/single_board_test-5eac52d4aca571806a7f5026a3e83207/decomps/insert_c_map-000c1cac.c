
/* WARNING: Unknown calling convention */

clib_error insert_c_map(clib_map *pMap,void *key,size_t key_size,void *value,size_t value_size)

{
  clib_error cVar1;
  
  if (pMap != (clib_map *)0x0) {
    cVar1 = insert_c_rb(pMap->root,key,key_size,value,value_size);
    return cVar1;
  }
  return 0x1f5;
}



/* WARNING: Unknown calling convention */

clib_bool find_c_map(clib_map *pMap,void *key,void **value)

{
  clib_rb_node *pcVar1;
  
  if (pMap == (clib_map *)0x0) {
    return 0;
  }
  pcVar1 = find_c_rb(pMap->root,key);
  if (pcVar1 != (clib_rb_node *)0x0) {
    get_raw_clib_object(pcVar1->value,value);
    return 1;
  }
  return 0;
}


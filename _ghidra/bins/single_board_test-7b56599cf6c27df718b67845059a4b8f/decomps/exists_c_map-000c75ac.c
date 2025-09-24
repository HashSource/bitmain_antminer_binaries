
/* WARNING: Unknown calling convention */

clib_bool exists_c_map(clib_map *pMap,void *key)

{
  clib_rb_node *pcVar1;
  
  if (pMap != (clib_map *)0x0) {
    pcVar1 = find_c_rb(pMap->root,key);
    if (pcVar1 != (clib_rb_node *)0x0) {
      pcVar1 = (clib_rb_node *)0x1;
    }
    return (clib_bool)pcVar1;
  }
  return 0;
}


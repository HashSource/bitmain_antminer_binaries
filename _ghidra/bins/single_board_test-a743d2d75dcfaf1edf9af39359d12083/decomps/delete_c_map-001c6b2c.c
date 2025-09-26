
/* WARNING: Unknown calling convention */

clib_error delete_c_map(clib_map *x)

{
  clib_map *pcVar1;
  
  pcVar1 = x;
  if (x != (clib_map *)0x0) {
    pcVar1 = (clib_map *)delete_c_rb(x->root);
    free(x);
  }
  return (clib_error)pcVar1;
}


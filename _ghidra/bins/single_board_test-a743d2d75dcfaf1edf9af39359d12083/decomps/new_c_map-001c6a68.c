
/* WARNING: Unknown calling convention */

clib_map * new_c_map(clib_compare fn_c_k,clib_destroy fn_k_d,clib_destroy fn_v_d)

{
  clib_map *pcVar1;
  clib_rb *pcVar2;
  
  pcVar1 = (clib_map *)malloc(4);
  if (pcVar1 != (clib_map *)0x0) {
    pcVar2 = new_c_rb(fn_c_k,fn_k_d,fn_v_d);
    pcVar1->root = pcVar2;
    if (pcVar2 != (clib_rb *)0x0) {
      return pcVar1;
    }
  }
  return (clib_map *)0x0;
}


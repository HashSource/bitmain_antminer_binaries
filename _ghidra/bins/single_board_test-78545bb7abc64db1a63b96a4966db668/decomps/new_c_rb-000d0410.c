
/* WARNING: Unknown calling convention */

clib_rb * new_c_rb(clib_compare fn_c,clib_destroy fn_ed,clib_destroy fn_vd)

{
  clib_rb *pcVar1;
  clib_rb_node *pcVar2;
  
  pcVar1 = (clib_rb *)malloc(0x28);
  if (pcVar1 != (clib_rb *)0x0) {
    pcVar2 = &pcVar1->sentinel;
    (pcVar1->sentinel).parent = (clib_rb_node *)0x0;
    (pcVar1->sentinel).color = 0;
    (pcVar1->sentinel).key = (clib_object *)0x0;
    (pcVar1->sentinel).value = (clib_object *)0x0;
    pcVar1->destruct_k_fn = (clib_destroy)0x0;
    pcVar1->destruct_v_fn = (clib_destroy)0x0;
    pcVar1->compare_fn = (clib_compare)0x0;
    (pcVar1->sentinel).parent = (clib_rb_node *)0x0;
    (pcVar1->sentinel).color = 0;
    pcVar1->compare_fn = fn_c;
    pcVar1->destruct_k_fn = fn_ed;
    pcVar1->destruct_v_fn = fn_vd;
    pcVar1->root = pcVar2;
    (pcVar1->sentinel).left = pcVar2;
    (pcVar1->sentinel).right = pcVar2;
  }
  return pcVar1;
}


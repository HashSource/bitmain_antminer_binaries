
/* WARNING: Unknown calling convention */

clib_rb_node * maximum_c_rb(clib_rb *pTree,clib_rb_node *x)

{
  clib_rb_node *pcVar1;
  
  do {
    pcVar1 = x;
    x = pcVar1->right;
  } while (x != &pTree->sentinel);
  return pcVar1;
}


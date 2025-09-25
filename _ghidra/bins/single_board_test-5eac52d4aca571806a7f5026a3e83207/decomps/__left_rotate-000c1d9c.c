
/* WARNING: Unknown calling convention */

void __left_rotate(clib_rb *pTree,clib_rb_node *x)

{
  clib_rb_node *pcVar1;
  clib_rb_node *y;
  clib_rb_node *pcVar2;
  bool bVar3;
  
  y = x->right;
  pcVar1 = &pTree->sentinel;
  pcVar2 = y->left;
  x->right = pcVar2;
  if (pcVar2 != pcVar1) {
    pcVar2->parent = x;
  }
  if (y != pcVar1) {
    pcVar2 = x->parent;
  }
  if (y != pcVar1) {
    y->parent = pcVar2;
  }
  pcVar2 = x->parent;
  if (pcVar2 == (clib_rb_node *)0x0) {
    pTree->root = y;
  }
  else {
    bVar3 = x == pcVar2->left;
    if (bVar3) {
      pcVar2->left = y;
    }
    if (!bVar3) {
      pcVar2->right = y;
    }
  }
  y->left = x;
  if (x != pcVar1) {
    x->parent = y;
  }
  return;
}


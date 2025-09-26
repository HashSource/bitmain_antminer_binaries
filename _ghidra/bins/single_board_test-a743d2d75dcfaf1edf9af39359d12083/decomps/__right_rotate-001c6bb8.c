
/* WARNING: Unknown calling convention */

void __right_rotate(clib_rb *pTree,clib_rb_node *x)

{
  clib_rb_node *pcVar1;
  clib_rb_node *y;
  clib_rb_node *pcVar2;
  
  y = x->left;
  pcVar1 = &pTree->sentinel;
  pcVar2 = y->right;
  x->left = pcVar2;
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
  else if (x == pcVar2->right) {
    pcVar2->right = y;
  }
  else {
    pcVar2->left = y;
  }
  y->right = x;
  if (x != pcVar1) {
    x->parent = y;
  }
  return;
}


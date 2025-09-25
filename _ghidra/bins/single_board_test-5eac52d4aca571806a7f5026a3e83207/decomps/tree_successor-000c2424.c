
/* WARNING: Unknown calling convention */

clib_rb_node * tree_successor(clib_rb *pTree,clib_rb_node *x)

{
  clib_rb_node *pcVar1;
  clib_rb_node *pcVar2;
  clib_rb_node *pcVar3;
  bool bVar4;
  
  pcVar1 = x->right;
  if (pcVar1 == &pTree->sentinel) {
    pcVar2 = pTree->root;
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3->right;
    } while (pcVar1 != pcVar2);
    if (x == pcVar3) {
      pcVar2 = (clib_rb_node *)0x0;
    }
    else {
      pcVar3 = x->parent;
      pcVar2 = pcVar1;
      if ((pcVar1 != pcVar3) && (pcVar2 = pcVar3, x == pcVar3->right)) {
        do {
          pcVar2 = pcVar3->parent;
          if (pcVar1 == pcVar2) {
            return pcVar1;
          }
          bVar4 = pcVar2->right == pcVar3;
          pcVar3 = pcVar2;
        } while (bVar4);
      }
    }
  }
  else {
    do {
      pcVar2 = pcVar1;
      pcVar1 = pcVar2->left;
    } while (&pTree->sentinel != pcVar2->left);
  }
  return pcVar2;
}


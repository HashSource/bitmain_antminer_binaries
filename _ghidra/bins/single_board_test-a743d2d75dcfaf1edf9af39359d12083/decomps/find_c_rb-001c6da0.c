
/* WARNING: Unknown calling convention */

clib_rb_node * find_c_rb(clib_rb *pTree,void *key)

{
  clib_rb_node *pcVar1;
  int iVar2;
  clib_rb_node *pcVar3;
  void *cur_key;
  
  pcVar3 = pTree->root;
  while( true ) {
    if (pcVar3 == &pTree->sentinel) {
      return (clib_rb_node *)0x0;
    }
    get_raw_clib_object(pcVar3->key,&cur_key);
    iVar2 = (*pTree->compare_fn)(key,cur_key);
    free(cur_key);
    if (iVar2 == 0) break;
    pcVar1 = (clib_rb_node *)&pcVar3->right;
    if (iVar2 < 0) {
      pcVar1 = pcVar3;
    }
    pcVar3 = pcVar1->left;
  }
  if (pcVar3 == &pTree->sentinel) {
    return (clib_rb_node *)0x0;
  }
  return pcVar3;
}


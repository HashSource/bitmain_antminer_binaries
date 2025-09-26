
/* WARNING: Unknown calling convention */

clib_object * get_next_c_map(clib_iterator *pIterator)

{
  clib_rb *pTree;
  clib_rb_node *pcVar1;
  
                    /* WARNING: Load size is inaccurate */
  pTree = *pIterator->pContainer;
  if ((clib_rb_node *)pIterator->pCurrentElement == (clib_rb_node *)0x0) {
    pcVar1 = minimum_c_rb(pTree,pTree->root);
    pIterator->pCurrentElement = pcVar1;
  }
  else {
    pcVar1 = tree_successor(pTree,(clib_rb_node *)pIterator->pCurrentElement);
    pIterator->pCurrentElement = pcVar1;
  }
  if (pcVar1 != (clib_rb_node *)0x0) {
    return pcVar1->value;
  }
  return (clib_object *)0x0;
}



/* WARNING: Unknown calling convention */

clib_error delete_c_rb(clib_rb *pTree)

{
  clib_object *inObject;
  clib_rb_node *__ptr;
  clib_rb_node *pcVar1;
  clib_rb_node *pcVar2;
  clib_rb_node *pcVar3;
  void *key;
  void *value;
  
  pcVar3 = &pTree->sentinel;
  pcVar1 = pTree->root;
  while (__ptr = pcVar1, __ptr != pcVar3) {
    pcVar2 = __ptr->left;
    pcVar1 = pcVar2;
    if ((pcVar3 == pcVar2) && (pcVar1 = __ptr->right, __ptr->right == pcVar3)) {
      if (pTree->destruct_k_fn != (clib_destroy)0x0) {
        get_raw_clib_object(__ptr->key,&key);
        (*pTree->destruct_k_fn)(key);
      }
      delete_clib_object(__ptr->key);
      inObject = __ptr->value;
      if (inObject != (clib_object *)0x0) {
        if (pTree->destruct_v_fn != (clib_destroy)0x0) {
          get_raw_clib_object(inObject,&value);
          (*pTree->destruct_v_fn)(value);
          inObject = __ptr->value;
        }
        delete_clib_object(inObject);
      }
      pcVar1 = __ptr->parent;
      if (pcVar1 == (clib_rb_node *)0x0) {
        free(__ptr);
        pcVar1 = pcVar2;
      }
      else if (pcVar1->left == pcVar3) {
        if (pcVar3 != pcVar1->right) {
          free(pcVar1->right);
          pcVar1->right = pcVar3;
        }
      }
      else {
        free(pcVar1->left);
        pcVar1->left = pcVar3;
      }
    }
  }
  free(pTree);
  return 0;
}


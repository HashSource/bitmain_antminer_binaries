
/* WARNING: Unknown calling convention */

clib_error insert_c_rb(clib_rb *pTree,void *k,size_t key_size,void *v,size_t value_size)

{
  clib_rb_node *x;
  clib_object *pcVar1;
  int iVar2;
  clib_rb_node *pcVar3;
  clib_rb_node *pcVar4;
  clib_rb_node *pcVar5;
  clib_rb_node *pcVar6;
  void *cur_key;
  void *new_key;
  
  x = (clib_rb_node *)malloc(0x18);
  if (x == (clib_rb_node *)0x0) {
    return 2;
  }
  pcVar3 = &pTree->sentinel;
  x->left = pcVar3;
  x->right = pcVar3;
  x->color = 1;
  pcVar1 = new_clib_object(k,key_size);
  x->key = pcVar1;
  if (v == (void *)0x0) {
    x->value = (clib_object *)0x0;
  }
  else {
    pcVar1 = new_clib_object(v,value_size);
    x->value = pcVar1;
  }
  pcVar6 = pTree->root;
  if (pcVar3 == pTree->root) {
    pTree->root = x;
    x->parent = (clib_rb_node *)0x0;
    pcVar3 = x;
  }
  else {
    do {
      pcVar5 = pcVar6;
      get_raw_clib_object(pcVar5->key,&cur_key);
      get_raw_clib_object(x->key,&new_key);
      iVar2 = (*pTree->compare_fn)(new_key,cur_key);
      free(cur_key);
      free(new_key);
      if (iVar2 == 0) {
        return 0x191;
      }
      pcVar4 = (clib_rb_node *)&pcVar5->right;
      if (iVar2 < 0) {
        pcVar4 = pcVar5;
      }
      pcVar6 = pcVar4->left;
    } while (pcVar4->left != pcVar3);
    x->parent = pcVar5;
    get_raw_clib_object(pcVar5->key,&cur_key);
    get_raw_clib_object(x->key,&new_key);
    iVar2 = (*pTree->compare_fn)(new_key,cur_key);
    free(cur_key);
    free(new_key);
    pcVar3 = pTree->root;
    if (iVar2 < 0) {
      pcVar5->left = x;
    }
    if (iVar2 >= 0) {
      pcVar5->right = x;
    }
  }
LAB_000d0578:
  do {
    pcVar6 = x;
    if (x == pcVar3) {
LAB_000d05b2:
      pcVar3->color = 0;
      debug_verify_properties(pTree);
      return 0;
    }
    while( true ) {
      pcVar5 = pcVar6->parent;
      if (pcVar5->color != 1) goto LAB_000d05b2;
      x = pcVar5->parent;
      pcVar4 = x->left;
      if (pcVar5 == pcVar4) {
        pcVar4 = x->right;
        if (pcVar4->color == 1) {
          pcVar5->color = 0;
          pcVar4->color = 0;
          x->color = 1;
        }
        else {
          pcVar3 = pcVar5;
          if (pcVar5->right == pcVar6) {
            __left_rotate(pTree,pcVar5);
            x = pcVar5->parent->parent;
            pcVar3 = pcVar5->parent;
            pcVar6 = pcVar5;
          }
          pcVar3->color = 0;
          x->color = 1;
          __right_rotate(pTree,x);
          pcVar3 = pTree->root;
          x = pcVar6;
        }
        goto LAB_000d0578;
      }
      if (pcVar4->color == 1) break;
      pcVar3 = pcVar5;
      if (pcVar6 == pcVar5->left) {
        __right_rotate(pTree,pcVar5);
        x = pcVar5->parent->parent;
        pcVar3 = pcVar5->parent;
        pcVar6 = pcVar5;
      }
      pcVar3->color = 0;
      x->color = 1;
      __left_rotate(pTree,x);
      pcVar3 = pTree->root;
      if (pcVar6 == pcVar3) goto LAB_000d05b2;
    }
    pcVar5->color = 0;
    pcVar4->color = 0;
    x->color = 1;
  } while( true );
}


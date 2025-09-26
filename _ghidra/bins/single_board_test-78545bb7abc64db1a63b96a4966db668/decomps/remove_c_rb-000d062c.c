
/* WARNING: Unknown calling convention */

clib_rb_node * remove_c_rb(clib_rb *pTree,void *key)

{
  int iVar1;
  clib_object *pcVar2;
  clib_object *pcVar3;
  clib_rb_node *pcVar4;
  clib_object *pcVar5;
  clib_rb_node *pcVar6;
  clib_rb_node *pcVar7;
  clib_rb_node *pcVar8;
  clib_rb_node *pcVar9;
  bool bVar10;
  void *cur_key;
  
  pcVar4 = &pTree->sentinel;
  pcVar6 = pTree->root;
  while( true ) {
    if (pcVar6 == pcVar4) {
      return (clib_rb_node *)0x0;
    }
    get_raw_clib_object(pcVar6->key,&cur_key);
    iVar1 = (*pTree->compare_fn)(key,cur_key);
    free(cur_key);
    if (iVar1 == 0) break;
    pcVar7 = (clib_rb_node *)&pcVar6->right;
    if (iVar1 < 0) {
      pcVar7 = pcVar6;
    }
    pcVar6 = pcVar7->left;
  }
  if (pcVar6 == pcVar4) {
    return (clib_rb_node *)0x0;
  }
  pcVar7 = pcVar6->left;
  pcVar8 = pcVar6;
  if (pcVar7 != pcVar4) {
    pcVar9 = pcVar6->right;
    if (pcVar6->right == pcVar4) goto LAB_000d0688;
    do {
      pcVar8 = pcVar9;
      pcVar9 = pcVar8->left;
    } while (pcVar9 != pcVar4);
  }
  pcVar7 = pcVar8->right;
LAB_000d0688:
  pcVar7->parent = pcVar8->parent;
  pcVar4 = pcVar8->parent;
  if (pcVar4 == (clib_rb_node *)0x0) {
    pTree->root = pcVar7;
  }
  else {
    bVar10 = pcVar8 == pcVar4->left;
    if (bVar10) {
      pcVar4->left = pcVar7;
    }
    if (!bVar10) {
      pcVar4->right = pcVar7;
    }
  }
  if (pcVar6 != pcVar8) {
    pcVar2 = pcVar6->key;
    pcVar5 = pcVar6->value;
    pcVar3 = pcVar8->value;
    pcVar6->key = pcVar8->key;
    pcVar8->key = pcVar2;
    pcVar6->value = pcVar3;
    pcVar8->value = pcVar5;
  }
  if (pcVar8->color == 0) {
    pcVar6 = pTree->root;
LAB_000d06d2:
    if (pcVar7 != pcVar6) {
      while( true ) {
        if (pcVar7->color != 0) {
          pcVar7->color = 0;
          goto LAB_000d06b6;
        }
        pcVar4 = pcVar7->parent;
        pcVar9 = pcVar4->left;
        if (pcVar7 == pcVar9) {
          pcVar9 = pcVar4->right;
          if (pcVar9->color == 1) {
            pcVar9->color = 0;
            pcVar4->color = 1;
            __left_rotate(pTree,pcVar4);
            pcVar4 = pcVar7->parent;
            pcVar9 = pcVar4->right;
          }
          pcVar6 = pcVar9->right;
          if (pcVar9->left->color == 0) {
            if (pcVar6->color == 0) goto LAB_000d0700;
          }
          else if (pcVar6->color == 0) {
            pcVar9->left->color = 0;
            pcVar9->color = 1;
            __right_rotate(pTree,pcVar9);
            pcVar4 = pcVar7->parent;
            pcVar9 = pcVar4->right;
            pcVar6 = pcVar9->right;
          }
          pcVar9->color = pcVar4->color;
          pcVar4->color = 0;
          pcVar6->color = 0;
          __left_rotate(pTree,pcVar4);
          pcVar6 = pTree->root;
          pcVar7 = pcVar6;
          goto LAB_000d06d2;
        }
        if (pcVar9->color == 1) {
          pcVar9->color = 0;
          pcVar4->color = 1;
          __right_rotate(pTree,pcVar4);
          pcVar4 = pcVar7->parent;
          pcVar9 = pcVar4->left;
        }
        pcVar6 = pcVar9->left;
        if (pcVar9->right->color != 0) break;
        if (pcVar6->color != 0) goto LAB_000d0730;
LAB_000d0700:
        pcVar6 = pTree->root;
        pcVar9->color = 1;
        pcVar7 = pcVar4;
        if (pcVar4 == pcVar6) goto LAB_000d070c;
      }
      if (pcVar6->color == 0) {
        pcVar9->right->color = 0;
        pcVar9->color = 1;
        __left_rotate(pTree,pcVar9);
        pcVar4 = pcVar7->parent;
        pcVar9 = pcVar4->left;
        pcVar6 = pcVar9->left;
      }
LAB_000d0730:
      pcVar9->color = pcVar4->color;
      pcVar4->color = 0;
      pcVar6->color = 0;
      __right_rotate(pTree,pcVar4);
      pcVar6 = pTree->root;
      pcVar7 = pcVar6;
      goto LAB_000d06d2;
    }
LAB_000d070c:
    pcVar6->color = 0;
  }
LAB_000d06b6:
  debug_verify_properties(pTree);
  return pcVar8;
}


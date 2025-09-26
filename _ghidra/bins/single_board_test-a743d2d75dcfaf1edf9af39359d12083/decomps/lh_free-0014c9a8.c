
void lh_free(_LHASH *lh)

{
  LHASH_NODE *ptr;
  uint uVar1;
  LHASH_NODE **ptr_00;
  lhash_node_st *plVar2;
  uint uVar3;
  
  if (lh != (_LHASH *)0x0) {
    uVar1 = lh->num_nodes;
    ptr_00 = lh->b;
    if (uVar1 != 0) {
      uVar3 = 0;
      do {
        ptr = ptr_00[uVar3];
        if (ptr_00[uVar3] != (LHASH_NODE *)0x0) {
          do {
            plVar2 = ptr->next;
            CRYPTO_free(ptr);
            ptr = plVar2;
          } while (plVar2 != (lhash_node_st *)0x0);
          ptr_00 = lh->b;
          uVar1 = lh->num_nodes;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
    CRYPTO_free(ptr_00);
    CRYPTO_free(lh);
    return;
  }
  return;
}


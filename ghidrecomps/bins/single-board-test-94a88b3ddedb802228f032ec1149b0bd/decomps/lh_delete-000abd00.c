
void * lh_delete(_LHASH *lh,void *data)

{
  ulong uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  LHASH_NODE **ppLVar5;
  uint extraout_r1;
  uint extraout_r1_00;
  LHASH_NODE *pLVar6;
  LHASH_NODE *pLVar7;
  ulong uVar8;
  lhash_node_st *ptr;
  uint uVar9;
  LHASH_NODE *pLVar10;
  uint uVar11;
  lhash_node_st **pplVar12;
  LHASH_COMP_FN_TYPE pLVar13;
  
  lh->error = 0;
  uVar1 = (*lh->hash)(data);
  lh->num_hash_calls = lh->num_hash_calls + 1;
  __aeabi_uidivmod(uVar1,lh->pmax);
  uVar11 = extraout_r1;
  if (extraout_r1 < lh->p) {
    __aeabi_uidivmod(uVar1,lh->num_alloc_nodes);
    uVar11 = extraout_r1_00;
  }
  pLVar13 = lh->comp;
  pLVar10 = lh->b[uVar11];
  pplVar12 = lh->b + uVar11;
  do {
    if (pLVar10 == (LHASH_NODE *)0x0) {
LAB_000abdde:
      lh->num_no_delete = lh->num_no_delete + 1;
      return (void *)0x0;
    }
    uVar8 = pLVar10->hash;
    lh->num_hash_comps = lh->num_hash_comps + 1;
    if (uVar1 == uVar8) {
      pvVar2 = pLVar10->data;
      lh->num_comp_calls = lh->num_comp_calls + 1;
      iVar3 = (*pLVar13)(pvVar2,data);
      if (iVar3 == 0) {
        ptr = *pplVar12;
        if (ptr != (lhash_node_st *)0x0) {
          *pplVar12 = ptr->next;
          pvVar2 = ptr->data;
          CRYPTO_free(ptr);
          uVar11 = lh->num_nodes;
          uVar1 = lh->num_items - 1;
          lh->num_delete = lh->num_delete + 1;
          lh->num_items = uVar1;
          if (uVar11 < 0x11) {
            return pvVar2;
          }
          uVar4 = __aeabi_uidiv(uVar1 * 0x100,uVar11);
          if (lh->down_load < uVar4) {
            return pvVar2;
          }
          uVar9 = lh->p;
          uVar4 = lh->pmax;
          iVar3 = uVar9 + uVar4 + -1;
          pLVar10 = lh->b[iVar3];
          lh->b[iVar3] = (LHASH_NODE *)0x0;
          if (uVar9 == 0) {
            ppLVar5 = (LHASH_NODE **)CRYPTO_realloc(lh->b,uVar4 << 2,DAT_000abe28,0x16b);
            if (ppLVar5 == (LHASH_NODE **)0x0) {
              lh->error = lh->error + 1;
              return pvVar2;
            }
            lh->b = ppLVar5;
            uVar4 = lh->pmax >> 1;
            uVar11 = lh->num_nodes;
            uVar9 = uVar4 - 1;
            lh->pmax = uVar4;
            lh->p = uVar9;
            lh->num_alloc_nodes = lh->num_alloc_nodes >> 1;
            lh->num_contract_reallocs = lh->num_contract_reallocs + 1;
          }
          else {
            ppLVar5 = lh->b;
            uVar9 = uVar9 - 1;
            lh->p = uVar9;
          }
          pLVar6 = ppLVar5[uVar9];
          lh->num_nodes = uVar11 - 1;
          lh->num_contracts = lh->num_contracts + 1;
          if (pLVar6 == (LHASH_NODE *)0x0) {
            ppLVar5[uVar9] = pLVar10;
            return pvVar2;
          }
          do {
            pLVar7 = pLVar6;
            pLVar6 = pLVar7->next;
          } while (pLVar6 != (lhash_node_st *)0x0);
          pLVar7->next = pLVar10;
          return pvVar2;
        }
        goto LAB_000abdde;
      }
    }
    pplVar12 = &pLVar10->next;
    pLVar10 = pLVar10->next;
  } while( true );
}


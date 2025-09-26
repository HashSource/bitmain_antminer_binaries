
void * lh_insert(_LHASH *lh,void *data)

{
  uint uVar1;
  ulong uVar2;
  void *pvVar3;
  int iVar4;
  lhash_node_st *plVar5;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  ulong uVar6;
  LHASH_NODE **ppLVar7;
  LHASH_NODE *extraout_r2;
  LHASH_NODE *pLVar8;
  ulong uVar9;
  LHASH_NODE **ppLVar10;
  LHASH_NODE *pLVar11;
  uint uVar12;
  LHASH_COMP_FN_TYPE pLVar13;
  uint uVar14;
  lhash_node_st **pplVar15;
  uint uVar16;
  
  uVar12 = lh->num_nodes;
  lh->error = 0;
  uVar1 = __aeabi_uidiv(lh->num_items << 8,uVar12);
  if (lh->up_load <= uVar1) {
    uVar14 = lh->p;
    uVar16 = lh->pmax;
    ppLVar7 = lh->b;
    iVar4 = uVar16 + uVar14;
    lh->num_expands = lh->num_expands + 1;
    lh->num_nodes = uVar12 + 1;
    pplVar15 = ppLVar7 + uVar14;
    uVar1 = lh->num_alloc_nodes;
    lh->p = uVar14 + 1;
    ppLVar7[iVar4] = (LHASH_NODE *)0x0;
    pLVar11 = ppLVar7[uVar14];
    while (pLVar11 != (LHASH_NODE *)0x0) {
      __aeabi_uidivmod(pLVar11->hash,uVar1);
      if (uVar14 != extraout_r1_01) {
        *pplVar15 = pLVar11->next;
        pLVar8 = ppLVar7[iVar4];
      }
      else {
        pplVar15 = &pLVar11->next;
        pLVar8 = extraout_r2;
      }
      if (uVar14 != extraout_r1_01) {
        pLVar11->next = pLVar8;
        ppLVar7[iVar4] = pLVar11;
      }
      pLVar11 = *pplVar15;
    }
    if (uVar16 <= uVar14 + 1) {
      ppLVar7 = (LHASH_NODE **)CRYPTO_realloc(lh->b,uVar1 << 3,"lhash.c",0x150);
      uVar1 = uVar1 * 2;
      if (ppLVar7 == (LHASH_NODE **)0x0) {
        lh->p = 0;
        lh->error = lh->error + 1;
      }
      else {
        uVar12 = lh->num_alloc_nodes;
        if (uVar12 < uVar1) {
          uVar14 = uVar12;
          if (6 < uVar1 && uVar12 + 1 < uVar1 - 7) {
            ppLVar10 = ppLVar7 + uVar12;
            do {
              uVar16 = uVar14 + 9;
              uVar14 = uVar14 + 8;
              HintPreloadData(ppLVar10 + 0x22);
              *ppLVar10 = (LHASH_NODE *)0x0;
              ppLVar10[1] = (LHASH_NODE *)0x0;
              ppLVar10[2] = (LHASH_NODE *)0x0;
              ppLVar10[3] = (LHASH_NODE *)0x0;
              ppLVar10[4] = (LHASH_NODE *)0x0;
              ppLVar10[5] = (LHASH_NODE *)0x0;
              ppLVar10[6] = (LHASH_NODE *)0x0;
              ppLVar10[7] = (LHASH_NODE *)0x0;
              ppLVar10 = ppLVar10 + 8;
            } while (uVar16 < uVar1 - 7);
          }
          ppLVar10 = ppLVar7 + (uVar14 - 1);
          do {
            uVar14 = uVar14 + 1;
            ppLVar10 = ppLVar10 + 1;
            *ppLVar10 = (LHASH_NODE *)0x0;
          } while (uVar14 < uVar1);
        }
        lh->pmax = uVar12;
        lh->num_alloc_nodes = uVar1;
        lh->b = ppLVar7;
        lh->num_expand_reallocs = lh->num_expand_reallocs + 1;
        lh->p = 0;
      }
    }
  }
  uVar2 = (*lh->hash)(data);
  lh->num_hash_calls = lh->num_hash_calls + 1;
  __aeabi_uidivmod(uVar2,lh->pmax);
  uVar1 = extraout_r1;
  if (extraout_r1 < lh->p) {
    __aeabi_uidivmod(uVar2,lh->num_alloc_nodes);
    uVar1 = extraout_r1_00;
  }
  pLVar13 = lh->comp;
  pLVar11 = lh->b[uVar1];
  pplVar15 = lh->b + uVar1;
  do {
    if (pLVar11 == (LHASH_NODE *)0x0) {
LAB_0014f6a6:
      plVar5 = (lhash_node_st *)CRYPTO_malloc(0xc,"lhash.c",0xbf);
      if (plVar5 == (lhash_node_st *)0x0) {
        lh->error = lh->error + 1;
      }
      else {
        uVar6 = lh->num_insert;
        uVar9 = lh->num_items;
        plVar5->data = data;
        plVar5->hash = uVar2;
        plVar5->next = (lhash_node_st *)0x0;
        *pplVar15 = plVar5;
        lh->num_insert = uVar6 + 1;
        lh->num_items = uVar9 + 1;
      }
      return (void *)0x0;
    }
    uVar6 = pLVar11->hash;
    lh->num_hash_comps = lh->num_hash_comps + 1;
    if (uVar2 == uVar6) {
      pvVar3 = pLVar11->data;
      lh->num_comp_calls = lh->num_comp_calls + 1;
      iVar4 = (*pLVar13)(pvVar3,data);
      if (iVar4 == 0) {
        plVar5 = *pplVar15;
        if (plVar5 != (lhash_node_st *)0x0) {
          uVar2 = lh->num_replace;
          pvVar3 = plVar5->data;
          plVar5->data = data;
          lh->num_replace = uVar2 + 1;
          return pvVar3;
        }
        goto LAB_0014f6a6;
      }
    }
    pplVar15 = &pLVar11->next;
    pLVar11 = pLVar11->next;
  } while( true );
}


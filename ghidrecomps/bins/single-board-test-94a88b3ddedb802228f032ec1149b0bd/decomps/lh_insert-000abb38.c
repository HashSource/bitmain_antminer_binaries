
void * lh_insert(_LHASH *lh,void *data)

{
  void **ppvVar1;
  uint uVar2;
  ulong uVar3;
  void *pvVar4;
  int iVar5;
  LHASH_NODE **ppLVar6;
  lhash_node_st *plVar7;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  ulong uVar8;
  ulong uVar9;
  LHASH_NODE **ppLVar10;
  LHASH_NODE *pLVar11;
  LHASH_NODE *pLVar12;
  uint uVar13;
  LHASH_COMP_FN_TYPE pLVar14;
  uint uVar15;
  lhash_node_st **pplVar16;
  uint uVar17;
  
  uVar13 = lh->num_nodes;
  lh->error = 0;
  uVar2 = __aeabi_uidiv(lh->num_items << 8,uVar13);
  if (lh->up_load <= uVar2) {
    uVar15 = lh->p;
    uVar17 = lh->pmax;
    pLVar11 = (LHASH_NODE *)lh->b;
    iVar5 = uVar17 + uVar15;
    lh->num_expands = lh->num_expands + 1;
    ppvVar1 = &pLVar11->data;
    lh->num_nodes = uVar13 + 1;
    pplVar16 = (lhash_node_st **)(&pLVar11->data + uVar15);
    uVar2 = lh->num_alloc_nodes;
    lh->p = uVar15 + 1;
    (&pLVar11->data)[iVar5] = (void *)0x0;
    pLVar12 = (LHASH_NODE *)(&pLVar11->data)[uVar15];
    while (pLVar12 != (LHASH_NODE *)0x0) {
      __aeabi_uidivmod(pLVar12->hash,uVar2);
      if (uVar15 != extraout_r1_01) {
        *pplVar16 = pLVar12->next;
        pLVar11 = (LHASH_NODE *)ppvVar1[iVar5];
      }
      else {
        pplVar16 = &pLVar12->next;
      }
      if (uVar15 != extraout_r1_01) {
        pLVar12->next = pLVar11;
        ppvVar1[iVar5] = pLVar12;
      }
      pLVar12 = *pplVar16;
    }
    if (uVar17 <= uVar15 + 1) {
      ppLVar6 = (LHASH_NODE **)CRYPTO_realloc(lh->b,uVar2 << 3,DAT_000abcfc,0x150);
      uVar2 = uVar2 * 2;
      if (ppLVar6 == (LHASH_NODE **)0x0) {
        lh->p = 0;
        lh->error = lh->error + 1;
      }
      else {
        uVar13 = lh->num_alloc_nodes;
        if (uVar13 < uVar2) {
          uVar15 = uVar13;
          if (6 < uVar2 && uVar13 + 1 < uVar2 - 7) {
            ppLVar10 = ppLVar6 + uVar13;
            do {
              uVar17 = uVar15 + 9;
              uVar15 = uVar15 + 8;
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
            } while (uVar17 < uVar2 - 7);
          }
          ppLVar10 = ppLVar6 + (uVar15 - 1);
          do {
            uVar15 = uVar15 + 1;
            ppLVar10 = ppLVar10 + 1;
            *ppLVar10 = (LHASH_NODE *)0x0;
          } while (uVar15 < uVar2);
        }
        lh->pmax = uVar13;
        lh->num_alloc_nodes = uVar2;
        lh->b = ppLVar6;
        lh->num_expand_reallocs = lh->num_expand_reallocs + 1;
        lh->p = 0;
      }
    }
  }
  uVar3 = (*lh->hash)(data);
  lh->num_hash_calls = lh->num_hash_calls + 1;
  __aeabi_uidivmod(uVar3,lh->pmax);
  uVar2 = extraout_r1;
  if (extraout_r1 < lh->p) {
    __aeabi_uidivmod(uVar3,lh->num_alloc_nodes);
    uVar2 = extraout_r1_00;
  }
  pLVar14 = lh->comp;
  pLVar11 = lh->b[uVar2];
  pplVar16 = lh->b + uVar2;
  do {
    if (pLVar11 == (LHASH_NODE *)0x0) {
LAB_000abcba:
      plVar7 = (lhash_node_st *)CRYPTO_malloc(0xc,DAT_000abcfc,0xbf);
      if (plVar7 == (lhash_node_st *)0x0) {
        lh->error = lh->error + 1;
      }
      else {
        uVar8 = lh->num_insert;
        uVar9 = lh->num_items;
        plVar7->data = data;
        plVar7->hash = uVar3;
        plVar7->next = (lhash_node_st *)0x0;
        *pplVar16 = plVar7;
        lh->num_insert = uVar8 + 1;
        lh->num_items = uVar9 + 1;
      }
      return (void *)0x0;
    }
    uVar8 = pLVar11->hash;
    lh->num_hash_comps = lh->num_hash_comps + 1;
    if (uVar3 == uVar8) {
      pvVar4 = pLVar11->data;
      lh->num_comp_calls = lh->num_comp_calls + 1;
      iVar5 = (*pLVar14)(pvVar4,data);
      if (iVar5 == 0) {
        plVar7 = *pplVar16;
        if (plVar7 != (lhash_node_st *)0x0) {
          uVar3 = lh->num_replace;
          pvVar4 = plVar7->data;
          plVar7->data = data;
          lh->num_replace = uVar3 + 1;
          return pvVar4;
        }
        goto LAB_000abcba;
      }
    }
    pplVar16 = &pLVar11->next;
    pLVar11 = pLVar11->next;
  } while( true );
}


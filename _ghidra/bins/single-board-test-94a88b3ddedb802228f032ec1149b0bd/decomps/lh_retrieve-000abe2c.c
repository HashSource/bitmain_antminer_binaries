
void * lh_retrieve(_LHASH *lh,void *data)

{
  ulong uVar1;
  void *pvVar2;
  int iVar3;
  uint extraout_r1;
  uint extraout_r1_00;
  uint uVar4;
  ulong uVar5;
  LHASH_NODE *pLVar6;
  LHASH_COMP_FN_TYPE pLVar7;
  lhash_node_st **pplVar8;
  
  lh->error = 0;
  uVar1 = (*lh->hash)(data);
  lh->num_hash_calls = lh->num_hash_calls + 1;
  __aeabi_uidivmod(uVar1,lh->pmax);
  uVar4 = extraout_r1;
  if (extraout_r1 < lh->p) {
    __aeabi_uidivmod(uVar1,lh->num_alloc_nodes);
    uVar4 = extraout_r1_00;
  }
  pLVar7 = lh->comp;
  pLVar6 = lh->b[uVar4];
  pplVar8 = lh->b + uVar4;
  do {
    if (pLVar6 == (LHASH_NODE *)0x0) {
LAB_000abea2:
      lh->num_retrieve_miss = lh->num_retrieve_miss + 1;
      return (void *)0x0;
    }
    uVar5 = pLVar6->hash;
    lh->num_hash_comps = lh->num_hash_comps + 1;
    if (uVar1 == uVar5) {
      pvVar2 = pLVar6->data;
      lh->num_comp_calls = lh->num_comp_calls + 1;
      iVar3 = (*pLVar7)(pvVar2,data);
      if (iVar3 == 0) {
        if (*pplVar8 != (lhash_node_st *)0x0) {
          pvVar2 = (*pplVar8)->data;
          lh->num_retrieve = lh->num_retrieve + 1;
          return pvVar2;
        }
        goto LAB_000abea2;
      }
    }
    pplVar8 = &pLVar6->next;
    pLVar6 = pLVar6->next;
  } while( true );
}


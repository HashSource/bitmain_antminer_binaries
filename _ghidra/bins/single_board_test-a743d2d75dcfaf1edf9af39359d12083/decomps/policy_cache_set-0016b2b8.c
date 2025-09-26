
X509_POLICY_CACHE * policy_cache_set(X509 *param_1)

{
  X509_POLICY_CACHE *pXVar1;
  POLICY_CONSTRAINTS *a;
  ASN1_INTEGER *pAVar2;
  long lVar3;
  _STACK *st;
  int iVar4;
  void *pvVar5;
  _STACK *p_Var6;
  int iVar7;
  int iVar8;
  X509_POLICY_CACHE *pXVar9;
  int local_2c [2];
  
  if (param_1->policy_cache != (X509_POLICY_CACHE *)0x0) {
    return param_1->policy_cache;
  }
  CRYPTO_lock(9,3,"pcy_cache.c",0xea);
  pXVar1 = (X509_POLICY_CACHE *)CRYPTO_malloc(0x14,"pcy_cache.c",0x83);
  if (pXVar1 == (X509_POLICY_CACHE *)0x0) goto LAB_0016b3b8;
  *(undefined4 *)pXVar1 = 0;
  *(undefined4 *)(pXVar1 + 4) = 0;
  *(undefined4 *)(pXVar1 + 8) = 0xffffffff;
  *(undefined4 *)(pXVar1 + 0xc) = 0xffffffff;
  *(undefined4 *)(pXVar1 + 0x10) = 0xffffffff;
  param_1->policy_cache = pXVar1;
  a = (POLICY_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x191,local_2c,(int *)0x0);
  if (a == (POLICY_CONSTRAINTS *)0x0) {
    if (local_2c[0] != -1) goto LAB_0016b3ce;
LAB_0016b334:
    st = (_STACK *)X509_get_ext_d2i(param_1,0x59,local_2c,(int *)0x0);
    iVar8 = local_2c[0];
    if (st == (_STACK *)0x0) {
      if (local_2c[0] == -1) goto LAB_0016b3b8;
      goto LAB_0016b3ce;
    }
    pXVar9 = param_1->policy_cache;
    iVar4 = sk_num(st);
    if (iVar4 == 0) {
LAB_0016b356:
      iVar8 = 0;
    }
    else {
      iVar4 = 0;
      p_Var6 = sk_new((cmp *)0x16b285);
      *(_STACK **)(pXVar9 + 4) = p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_0016b356;
      for (; iVar7 = sk_num(st), iVar4 < iVar7; iVar4 = iVar4 + 1) {
        pvVar5 = sk_value(st,iVar4);
        pvVar5 = (void *)policy_data_new(pvVar5,0,iVar8);
        if (pvVar5 == (void *)0x0) goto LAB_0016b356;
        iVar7 = OBJ_obj2nid(*(ASN1_OBJECT **)((int)pvVar5 + 4));
        if (iVar7 != 0x2ea) {
          iVar7 = sk_find(*(_STACK **)(pXVar9 + 4),pvVar5);
          if (iVar7 != -1) goto LAB_0016b482;
          iVar7 = sk_push(*(_STACK **)(pXVar9 + 4),pvVar5);
          if (iVar7 != 0) goto LAB_0016b406;
          iVar8 = 0;
LAB_0016b454:
          policy_data_free(pvVar5);
          goto LAB_0016b358;
        }
        if (*(int *)pXVar9 != 0) {
LAB_0016b482:
          iVar8 = -1;
          param_1->ex_flags = param_1->ex_flags | 0x800;
          goto LAB_0016b454;
        }
        *(void **)pXVar9 = pvVar5;
LAB_0016b406:
      }
      iVar8 = 1;
    }
LAB_0016b358:
    sk_pop_free(st,(func *)0x167d01);
    if (iVar8 != 1) {
      sk_pop_free(*(_STACK **)(pXVar9 + 4),policy_data_free);
      *(undefined4 *)(pXVar9 + 4) = 0;
      goto LAB_0016b3b8;
    }
    local_2c[0] = iVar8;
    pvVar5 = X509_get_ext_d2i(param_1,0x2eb,local_2c,(int *)0x0);
    if (pvVar5 == (void *)0x0) {
      if (local_2c[0] == -1) goto LAB_0016b386;
      goto LAB_0016b3ce;
    }
    local_2c[0] = policy_cache_set_mapping(param_1,pvVar5);
    if (local_2c[0] < 1) goto LAB_0016b3ce;
LAB_0016b386:
    pAVar2 = (ASN1_INTEGER *)X509_get_ext_d2i(param_1,0x2ec,local_2c,(int *)0x0);
    if (pAVar2 != (ASN1_INTEGER *)0x0) {
      if (pAVar2->type != 0x102) {
        lVar3 = ASN1_INTEGER_get(pAVar2);
        *(long *)(pXVar1 + 8) = lVar3;
        goto LAB_0016b3a8;
      }
      goto LAB_0016b3d0;
    }
    if (local_2c[0] != -1) goto LAB_0016b3ce;
  }
  else {
    pAVar2 = a->requireExplicitPolicy;
    if (pAVar2 == (ASN1_INTEGER *)0x0) {
      pAVar2 = a->inhibitPolicyMapping;
      if (pAVar2 != (ASN1_INTEGER *)0x0) goto LAB_0016b324;
    }
    else if (pAVar2->type != 0x102) {
      lVar3 = ASN1_INTEGER_get(pAVar2);
      pAVar2 = a->inhibitPolicyMapping;
      *(long *)(pXVar1 + 0xc) = lVar3;
      if (pAVar2 == (ASN1_INTEGER *)0x0) goto LAB_0016b334;
LAB_0016b324:
      if (pAVar2->type != 0x102) {
        lVar3 = ASN1_INTEGER_get(pAVar2);
        *(long *)(pXVar1 + 0x10) = lVar3;
        goto LAB_0016b334;
      }
    }
LAB_0016b3ce:
    pAVar2 = (ASN1_INTEGER *)0x0;
LAB_0016b3d0:
    param_1->ex_flags = param_1->ex_flags | 0x800;
  }
LAB_0016b3a8:
  if (a != (POLICY_CONSTRAINTS *)0x0) {
    POLICY_CONSTRAINTS_free(a);
  }
  if (pAVar2 != (ASN1_INTEGER *)0x0) {
    ASN1_INTEGER_free(pAVar2);
  }
LAB_0016b3b8:
  CRYPTO_lock(10,3,"pcy_cache.c",0xec);
  return param_1->policy_cache;
}


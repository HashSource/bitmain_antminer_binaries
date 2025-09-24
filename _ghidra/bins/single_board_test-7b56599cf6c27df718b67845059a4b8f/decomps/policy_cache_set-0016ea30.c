
ulong policy_cache_set(X509 *param_1)

{
  undefined4 *puVar1;
  POLICY_CONSTRAINTS *a;
  ASN1_INTEGER *pAVar2;
  long lVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int local_2c [2];
  
  if (param_1[1].ex_flags != 0) {
    return param_1[1].ex_flags;
  }
  CRYPTO_THREAD_write_lock(*(undefined4 *)param_1[1].sha1_hash);
  if (param_1[1].ex_flags != 0) goto LAB_0016ea58;
  puVar1 = (undefined4 *)CRYPTO_malloc(0x14,"crypto/x509v3/pcy_cache.c",0x5c);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x22,0xaa,0x41,"crypto/x509v3/pcy_cache.c",0x5e);
    goto LAB_0016ea58;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0xffffffff;
  puVar1[3] = 0xffffffff;
  puVar1[4] = 0xffffffff;
  param_1[1].ex_flags = (ulong)puVar1;
  a = (POLICY_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x191,local_2c,(int *)0x0);
  if (a == (POLICY_CONSTRAINTS *)0x0) {
    if (local_2c[0] != -1) goto LAB_0016ebcc;
LAB_0016eae4:
    pvVar4 = X509_get_ext_d2i(param_1,0x59,local_2c,(int *)0x0);
    iVar9 = local_2c[0];
    if (pvVar4 == (void *)0x0) {
      if (local_2c[0] == -1) goto LAB_0016ea58;
      goto LAB_0016ebcc;
    }
    piVar11 = (int *)param_1[1].ex_flags;
    iVar5 = OPENSSL_sk_num();
    if (iVar5 < 1) {
      iVar6 = 0;
LAB_0016eba2:
      policy_data_free(iVar6);
LAB_0016eba6:
      OPENSSL_sk_pop_free(pvVar4,0x173ce5);
      OPENSSL_sk_pop_free(piVar11[1],(undefined *)0x16ecf5);
      piVar11[1] = 0;
      goto LAB_0016ea58;
    }
    iVar6 = OPENSSL_sk_new(0x16e9ed);
    piVar11[1] = iVar6;
    if (iVar6 == 0) {
      iVar9 = 0x26;
LAB_0016ec98:
      ERR_put_error(0x22,0xa9,0x41,"crypto/x509v3/pcy_cache.c",iVar9);
      goto LAB_0016eba6;
    }
    iVar10 = 0;
    do {
      uVar7 = OPENSSL_sk_value(pvVar4,iVar10);
      iVar6 = policy_data_new(uVar7,0,iVar9);
      if (iVar6 == 0) {
        iVar9 = 0x2d;
        goto LAB_0016ec98;
      }
      iVar8 = OBJ_obj2nid(*(ASN1_OBJECT **)(iVar6 + 4));
      if (iVar8 == 0x2ea) {
        if (*piVar11 != 0) goto LAB_0016ec12;
        *piVar11 = iVar6;
      }
      else {
        iVar8 = OPENSSL_sk_find(piVar11[1],iVar6);
        if (-1 < iVar8) {
LAB_0016ec12:
          param_1[1].references = param_1[1].references | 0x800;
          goto LAB_0016eba2;
        }
        iVar8 = OPENSSL_sk_push(piVar11[1],iVar6);
        if (iVar8 == 0) {
          ERR_put_error(0x22,0xa9,0x41,"crypto/x509v3/pcy_cache.c",0x3d);
          goto LAB_0016eba2;
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar5 != iVar10);
    policy_data_free(0);
    OPENSSL_sk_pop_free(pvVar4,0x173ce5);
    local_2c[0] = 1;
    pvVar4 = X509_get_ext_d2i(param_1,0x2eb,local_2c,(int *)0x0);
    if (pvVar4 == (void *)0x0) {
      if (local_2c[0] == -1) goto LAB_0016ec64;
      goto LAB_0016ebcc;
    }
    local_2c[0] = policy_cache_set_mapping(param_1,pvVar4);
    if (local_2c[0] < 1) goto LAB_0016ebcc;
LAB_0016ec64:
    pAVar2 = (ASN1_INTEGER *)X509_get_ext_d2i(param_1,0x2ec,local_2c,(int *)0x0);
    if (pAVar2 != (ASN1_INTEGER *)0x0) {
      if (pAVar2->type != 0x102) {
        lVar3 = ASN1_INTEGER_get(pAVar2);
        puVar1[2] = lVar3;
        goto LAB_0016ebda;
      }
      goto LAB_0016ebce;
    }
    if (local_2c[0] != -1) goto LAB_0016ebcc;
  }
  else {
    pAVar2 = a->requireExplicitPolicy;
    if (pAVar2 == (ASN1_INTEGER *)0x0) {
      pAVar2 = a->inhibitPolicyMapping;
      if (pAVar2 != (ASN1_INTEGER *)0x0) goto LAB_0016ead4;
    }
    else if (pAVar2->type != 0x102) {
      lVar3 = ASN1_INTEGER_get(pAVar2);
      pAVar2 = a->inhibitPolicyMapping;
      puVar1[3] = lVar3;
      if (pAVar2 == (ASN1_INTEGER *)0x0) goto LAB_0016eae4;
LAB_0016ead4:
      if (pAVar2->type != 0x102) {
        lVar3 = ASN1_INTEGER_get(pAVar2);
        puVar1[4] = lVar3;
        goto LAB_0016eae4;
      }
    }
LAB_0016ebcc:
    pAVar2 = (ASN1_INTEGER *)0x0;
LAB_0016ebce:
    param_1[1].references = param_1[1].references | 0x800;
  }
LAB_0016ebda:
  POLICY_CONSTRAINTS_free(a);
  ASN1_INTEGER_free(pAVar2);
LAB_0016ea58:
  CRYPTO_THREAD_unlock(*(undefined4 *)param_1[1].sha1_hash);
  return param_1[1].ex_flags;
}


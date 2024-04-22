
DH * make_cp_exchange_key(BIGNUM *param_1,EVP_PKEY *param_2,undefined4 param_3)

{
  DH *dh;
  BIGNUM *pBVar1;
  void *pvVar2;
  int iVar3;
  uchar *puVar4;
  uchar *puVar5;
  uchar uStack_119;
  uchar local_118 [128];
  uchar auStack_98 [128];
  
  dh = DH_new();
  if (dh != (DH *)0x0) {
    memset(local_118,0,0x80);
    pBVar1 = BN_dup(((param_2->pkey).rsa)->e);
    dh->g = pBVar1;
    pBVar1 = BN_dup(((param_2->pkey).dsa)->p);
    dh->p = pBVar1;
    pBVar1 = BN_dup(param_1);
    dh->priv_key = pBVar1;
    pvVar2 = EVP_PKEY_get0(param_2);
    iVar3 = DH_compute_key(auStack_98,*(BIGNUM **)((int)pvVar2 + 0x18),dh);
    if (iVar3 == 0) {
      DH_free(dh);
      dh = (DH *)0x0;
    }
    else {
      memset(local_118,0,0x80);
      if (0 < iVar3) {
        puVar4 = auStack_98 + iVar3;
        puVar5 = &uStack_119;
        do {
          puVar4 = puVar4 + -1;
          puVar5 = puVar5 + 1;
          *puVar5 = *puVar4;
        } while (puVar4 != auStack_98);
      }
      DH_free(dh);
      init_gost_hash_ctx(auStack_98,DAT_00114ef0);
      start_hash(auStack_98);
      hash_block(auStack_98,local_118,0x80);
      finish_hash(auStack_98,param_3);
      done_gost_hash_ctx(auStack_98);
      dh = (DH *)0x1;
    }
  }
  return dh;
}


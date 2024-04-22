
int pkey_ec_kdf_derive(int param_1,void *param_2,size_t *param_3)

{
  EC_KEY *pEVar1;
  EC_GROUP *pEVar2;
  int iVar3;
  void *out;
  EC_POINT *pEVar4;
  size_t sVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(param_1 + 0x14);
  if (*(char *)(iVar8 + 0xd) == '\x01') {
    if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0xc) != 0)) {
      pEVar1 = *(EC_KEY **)(iVar8 + 8);
      if (pEVar1 == (EC_KEY *)0x0) {
        pEVar1 = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x14);
      }
      if (param_2 == (void *)0x0) {
        pEVar2 = EC_KEY_get0_group(pEVar1);
        iVar7 = EC_GROUP_get_degree(pEVar2);
        iVar8 = iVar7 + 0xe;
        if (-1 < iVar7 + 7) {
          iVar8 = iVar7 + 7;
        }
        *param_3 = iVar8 >> 3;
        return 1;
      }
      pEVar4 = EC_KEY_get0_public_key(*(EC_KEY **)(*(int *)(param_1 + 0xc) + 0x14));
      sVar6 = ECDH_compute_key(param_2,*param_3,pEVar4,pEVar1,(KDF *)0x0);
      if (0 < (int)sVar6) {
        *param_3 = sVar6;
        return 1;
      }
      return 0;
    }
LAB_000f8abe:
    ERR_put_error(0x10,0xd9,0x8c,DAT_000f8af4,0xd8);
    return 0;
  }
  if (param_2 == (void *)0x0) {
    *param_3 = *(size_t *)(iVar8 + 0x1c);
    return 1;
  }
  if (*param_3 != *(size_t *)(iVar8 + 0x1c)) {
    return 0;
  }
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) goto LAB_000f8abe;
  pEVar1 = *(EC_KEY **)(iVar8 + 8);
  if (pEVar1 == (EC_KEY *)0x0) {
    pEVar1 = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x14);
  }
  pEVar2 = EC_KEY_get0_group(pEVar1);
  iVar3 = EC_GROUP_get_degree(pEVar2);
  iVar7 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar7 = iVar3 + 7;
  }
  sVar6 = iVar7 >> 3;
  out = CRYPTO_malloc(sVar6,DAT_000f8af4,0x105);
  if (out == (void *)0x0) {
    return 0;
  }
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) {
    ERR_put_error(0x10,0xd9,0x8c,DAT_000f8af4,0xd8);
  }
  else {
    pEVar1 = *(EC_KEY **)(*(int *)(param_1 + 0x14) + 8);
    if (pEVar1 == (EC_KEY *)0x0) {
      pEVar1 = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x14);
    }
    pEVar4 = EC_KEY_get0_public_key(*(EC_KEY **)(*(int *)(param_1 + 0xc) + 0x14));
    sVar5 = ECDH_compute_key(out,sVar6,pEVar4,pEVar1,(KDF *)0x0);
    if (0 < (int)sVar5) {
      iVar8 = ECDH_KDF_X9_62(param_2,*param_3,out,sVar5,*(undefined4 *)(iVar8 + 0x14),
                             *(undefined4 *)(iVar8 + 0x18),*(undefined4 *)(iVar8 + 0x10));
      sVar6 = sVar5;
      if (iVar8 != 0) {
        iVar8 = 1;
      }
      goto LAB_000f8a60;
    }
  }
  iVar8 = 0;
LAB_000f8a60:
  OPENSSL_cleanse(out,sVar6);
  CRYPTO_free(out);
  return iVar8;
}


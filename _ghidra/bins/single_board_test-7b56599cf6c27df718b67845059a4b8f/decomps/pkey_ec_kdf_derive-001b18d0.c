
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
        pEVar1 = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x18);
      }
      if (param_2 != (void *)0x0) {
        pEVar4 = EC_KEY_get0_public_key(*(EC_KEY **)(*(int *)(param_1 + 0xc) + 0x18));
        sVar6 = ECDH_compute_key(param_2,*param_3,pEVar4,pEVar1,(KDF *)0x0);
        if ((int)sVar6 < 1) {
          return 0;
        }
        *param_3 = sVar6;
        return 1;
      }
      pEVar2 = EC_KEY_get0_group(pEVar1);
      iVar7 = EC_GROUP_get_degree(pEVar2);
      iVar8 = iVar7 + 0xe;
      if (-1 < iVar7 + 7) {
        iVar8 = iVar7 + 7;
      }
      *param_3 = iVar8 >> 3;
      return 1;
    }
LAB_001b19ea:
    ERR_put_error(0x10,0xd9,0x8c,"crypto/ec/ec_pmeth.c",0xa0);
    return 0;
  }
  if (param_2 == (void *)0x0) {
    *param_3 = *(size_t *)(iVar8 + 0x1c);
    return 1;
  }
  if (*param_3 != *(size_t *)(iVar8 + 0x1c)) {
    return 0;
  }
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) goto LAB_001b19ea;
  pEVar1 = *(EC_KEY **)(iVar8 + 8);
  if (pEVar1 == (EC_KEY *)0x0) {
    pEVar1 = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x18);
  }
  pEVar2 = EC_KEY_get0_group(pEVar1);
  iVar3 = EC_GROUP_get_degree(pEVar2);
  iVar7 = iVar3 + 7;
  if (iVar3 + 7 < 0) {
    iVar7 = iVar3 + 0xe;
  }
  sVar6 = iVar7 >> 3;
  out = CRYPTO_malloc(sVar6,"crypto/ec/ec_pmeth.c",0xcd);
  if (out == (void *)0x0) {
    ERR_put_error(0x10,0x11b,0x41,"crypto/ec/ec_pmeth.c",0xce);
    return 0;
  }
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) {
    ERR_put_error(0x10,0xd9,0x8c,"crypto/ec/ec_pmeth.c",0xa0);
  }
  else {
    pEVar1 = *(EC_KEY **)(*(int *)(param_1 + 0x14) + 8);
    if (pEVar1 == (EC_KEY *)0x0) {
      pEVar1 = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x18);
    }
    pEVar4 = EC_KEY_get0_public_key(*(EC_KEY **)(*(int *)(param_1 + 0xc) + 0x18));
    sVar5 = ECDH_compute_key(out,sVar6,pEVar4,pEVar1,(KDF *)0x0);
    if (0 < (int)sVar5) {
      iVar8 = ecdh_KDF_X9_63(param_2,*param_3,out,sVar5,*(undefined4 *)(iVar8 + 0x14),
                             *(undefined4 *)(iVar8 + 0x18),*(undefined4 *)(iVar8 + 0x10));
      sVar6 = sVar5;
      if (iVar8 != 0) {
        iVar8 = 1;
      }
      goto LAB_001b1986;
    }
  }
  iVar8 = 0;
LAB_001b1986:
  CRYPTO_clear_free(out,sVar6,"crypto/ec/ec_pmeth.c",0xda);
  return iVar8;
}


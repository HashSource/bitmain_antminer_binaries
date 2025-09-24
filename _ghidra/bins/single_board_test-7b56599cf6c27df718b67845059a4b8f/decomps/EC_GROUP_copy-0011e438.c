
int EC_GROUP_copy(EC_GROUP *dst,EC_GROUP *src)

{
  BN_MONT_CTX *pBVar1;
  EC_POINT *point;
  void *pvVar2;
  BIGNUM *pBVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  BN_MONT_CTX *from;
  EC_POINT *src_00;
  
  if (*(int *)(*(int *)dst + 0x14) == 0) {
    ERR_put_error(0x10,0x6a,0x42,"crypto/ec/ec_lib.c",0x85);
    return 0;
  }
  if (*(int *)dst != *(int *)src) {
    ERR_put_error(0x10,0x6a,0x65,"crypto/ec/ec_lib.c",0x89);
    return 0;
  }
  if (dst == src) {
    return 1;
  }
  uVar4 = *(undefined4 *)(src + 0x10);
  *(undefined4 *)(dst + 0x60) = *(undefined4 *)(src + 0x60);
  iVar5 = *(int *)(src + 0x60);
  *(undefined4 *)(dst + 0x10) = uVar4;
  if (iVar5 == 0) {
    *(undefined4 *)(dst + 100) = 0;
  }
  else if (iVar5 == 5) {
    uVar4 = EC_ec_pre_comp_dup(*(undefined4 *)(src + 100));
    *(undefined4 *)(dst + 100) = uVar4;
  }
  from = *(BN_MONT_CTX **)(src + 0x5c);
  pBVar1 = *(BN_MONT_CTX **)(dst + 0x5c);
  if (from == (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(pBVar1);
    *(undefined4 *)(dst + 0x5c) = 0;
  }
  else {
    if (pBVar1 == (BN_MONT_CTX *)0x0) {
      pBVar1 = BN_MONT_CTX_new();
      *(BN_MONT_CTX **)(dst + 0x5c) = pBVar1;
      if (pBVar1 == (BN_MONT_CTX *)0x0) {
        return 0;
      }
      from = *(BN_MONT_CTX **)(src + 0x5c);
    }
    pBVar1 = BN_MONT_CTX_copy(pBVar1,from);
    if (pBVar1 == (BN_MONT_CTX *)0x0) {
      return 0;
    }
  }
  src_00 = *(EC_POINT **)(src + 4);
  point = *(EC_POINT **)(dst + 4);
  if (src_00 == (EC_POINT *)0x0) {
    EC_POINT_clear_free(point);
    *(undefined4 *)(dst + 4) = 0;
  }
  else {
    if (point == (EC_POINT *)0x0) {
      point = EC_POINT_new(dst);
      *(EC_POINT **)(dst + 4) = point;
      if (point == (EC_POINT *)0x0) {
        return 0;
      }
      src_00 = *(EC_POINT **)(src + 4);
    }
    iVar5 = EC_POINT_copy(point,src_00);
    if (iVar5 == 0) {
      return 0;
    }
  }
  if ((-1 < **(int **)src << 0x1e) &&
     ((pBVar3 = BN_copy(*(BIGNUM **)(dst + 8),*(BIGNUM **)(src + 8)), pBVar3 == (BIGNUM *)0x0 ||
      (pBVar3 = BN_copy(*(BIGNUM **)(dst + 0xc),*(BIGNUM **)(src + 0xc)), pBVar3 == (BIGNUM *)0x0)))
     ) {
    return 0;
  }
  iVar5 = *(int *)(src + 0x20);
  uVar4 = *(undefined4 *)(src + 0x1c);
  uVar6 = *(undefined4 *)(src + 0x18);
  *(undefined4 *)(dst + 0x14) = *(undefined4 *)(src + 0x14);
  *(undefined4 *)(dst + 0x1c) = uVar4;
  *(undefined4 *)(dst + 0x18) = uVar6;
  if (iVar5 == 0) {
    CRYPTO_free(*(void **)(dst + 0x20));
    *(undefined4 *)(dst + 0x20) = 0;
    *(undefined4 *)(dst + 0x24) = 0;
  }
  else {
    CRYPTO_free(*(void **)(dst + 0x20));
    pvVar2 = CRYPTO_malloc(*(int *)(src + 0x24),"crypto/ec/ec_lib.c",0xda);
    *(void **)(dst + 0x20) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      ERR_put_error(0x10,0x6a,0x41,"crypto/ec/ec_lib.c",0xdb);
      return 0;
    }
    pvVar2 = memcpy(pvVar2,*(void **)(src + 0x20),*(size_t *)(src + 0x24));
    if (pvVar2 == (void *)0x0) {
      return 0;
    }
    *(undefined4 *)(dst + 0x24) = *(undefined4 *)(src + 0x24);
  }
                    /* WARNING: Could not recover jumptable at 0x0011e4fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar5 = (**(code **)(*(int *)dst + 0x14))(dst,src);
  return iVar5;
}


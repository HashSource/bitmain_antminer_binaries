
EC_KEY * EC_KEY_copy(EC_KEY *dst,EC_KEY *src)

{
  int iVar1;
  EC_METHOD *meth;
  EC_GROUP *dst_00;
  EC_POINT *dst_01;
  BIGNUM *a;
  ENGINE *e;
  BIGNUM *pBVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (src == (EC_KEY *)0x0 || dst == (EC_KEY *)0x0) {
    ERR_put_error(0x10,0xb2,0x43,"crypto/ec/ec_key.c",0x4d);
    return (EC_KEY *)0x0;
  }
  if (*(int *)src != *(int *)dst) {
    pcVar3 = *(code **)(*(int *)dst + 0xc);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)();
    }
    if ((*(int **)(dst + 0xc) != (int *)0x0) &&
       (pcVar3 = *(code **)(**(int **)(dst + 0xc) + 0xc0), pcVar3 != (code *)0x0)) {
      (*pcVar3)(dst);
    }
    iVar1 = ENGINE_finish(*(ENGINE **)(dst + 4));
    if (iVar1 == 0) {
      return (EC_KEY *)0x0;
    }
    *(undefined4 *)(dst + 4) = 0;
  }
  if (*(EC_GROUP **)(src + 0xc) != (EC_GROUP *)0x0) {
    meth = EC_GROUP_method_of(*(EC_GROUP **)(src + 0xc));
    EC_GROUP_free(*(EC_GROUP **)(dst + 0xc));
    dst_00 = EC_GROUP_new(meth);
    *(EC_GROUP **)(dst + 0xc) = dst_00;
    if (dst_00 == (EC_GROUP *)0x0) {
      return (EC_KEY *)0x0;
    }
    iVar1 = EC_GROUP_copy(dst_00,*(EC_GROUP **)(src + 0xc));
    if (iVar1 == 0) {
      return (EC_KEY *)0x0;
    }
    if (*(int *)(src + 0x10) != 0) {
      EC_POINT_free(*(EC_POINT **)(dst + 0x10));
      dst_01 = EC_POINT_new(*(EC_GROUP **)(src + 0xc));
      *(EC_POINT **)(dst + 0x10) = dst_01;
      if (dst_01 == (EC_POINT *)0x0) {
        return (EC_KEY *)0x0;
      }
      iVar1 = EC_POINT_copy(dst_01,*(EC_POINT **)(src + 0x10));
      if (iVar1 == 0) {
        return (EC_KEY *)0x0;
      }
    }
    pBVar2 = *(BIGNUM **)(src + 0x14);
    if (pBVar2 != (BIGNUM *)0x0) {
      a = *(BIGNUM **)(dst + 0x14);
      if (a == (BIGNUM *)0x0) {
        a = BN_new();
        *(BIGNUM **)(dst + 0x14) = a;
        if (a == (BIGNUM *)0x0) {
          return (EC_KEY *)0x0;
        }
        pBVar2 = *(BIGNUM **)(src + 0x14);
      }
      pBVar2 = BN_copy(a,pBVar2);
      if (pBVar2 == (BIGNUM *)0x0) {
        return (EC_KEY *)0x0;
      }
      if ((*(code **)(**(int **)(src + 0xc) + 0xbc) != (code *)0x0) &&
         (iVar1 = (**(code **)(**(int **)(src + 0xc) + 0xbc))(dst,src), iVar1 == 0)) {
        return (EC_KEY *)0x0;
      }
    }
  }
  uVar6 = *(undefined4 *)(src + 0x1c);
  uVar5 = *(undefined4 *)(src + 8);
  uVar4 = *(undefined4 *)(src + 0x24);
  *(undefined4 *)(dst + 0x18) = *(undefined4 *)(src + 0x18);
  *(undefined4 *)(dst + 0x1c) = uVar6;
  *(undefined4 *)(dst + 8) = uVar5;
  *(undefined4 *)(dst + 0x24) = uVar4;
  iVar1 = CRYPTO_dup_ex_data(8,(CRYPTO_EX_DATA *)(dst + 0x28),(CRYPTO_EX_DATA *)(src + 0x28));
  if (iVar1 != 0) {
    iVar1 = *(int *)src;
    if (iVar1 != *(int *)dst) {
      e = *(ENGINE **)(src + 4);
      if (e != (ENGINE *)0x0) {
        iVar1 = ENGINE_init(e);
        if (iVar1 == 0) {
          return (EC_KEY *)0x0;
        }
        e = *(ENGINE **)(src + 4);
        iVar1 = *(int *)src;
      }
      *(int *)dst = iVar1;
      iVar1 = *(int *)src;
      *(ENGINE **)(dst + 4) = e;
    }
    if (*(code **)(iVar1 + 0x10) == (code *)0x0) {
      return dst;
    }
    iVar1 = (**(code **)(iVar1 + 0x10))(dst,src);
    if (iVar1 != 0) {
      return dst;
    }
  }
  return (EC_KEY *)0x0;
}


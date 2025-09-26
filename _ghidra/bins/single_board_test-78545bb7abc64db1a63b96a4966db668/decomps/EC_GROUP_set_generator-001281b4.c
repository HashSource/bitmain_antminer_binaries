
int EC_GROUP_set_generator(EC_GROUP *group,EC_POINT *generator,BIGNUM *order,BIGNUM *cofactor)

{
  int iVar1;
  int iVar2;
  EC_POINT *dst;
  BIGNUM *pBVar3;
  BN_CTX *pBVar4;
  BIGNUM *pBVar5;
  BN_MONT_CTX *mont;
  
  if (generator == (EC_POINT *)0x0) {
    ERR_put_error(0x10,0x6f,0x43,"crypto/ec/ec_lib.c",0x14e);
    return 0;
  }
  if (((*(int *)(group + 0x28) == 0) || (iVar1 = BN_is_zero(), iVar1 != 0)) ||
     (iVar1 = BN_is_negative(*(undefined4 *)(group + 0x28)), iVar1 != 0)) {
    ERR_put_error(0x10,0x6f,0x67,"crypto/ec/ec_lib.c",0x155);
    return 0;
  }
  if (((order == (BIGNUM *)0x0) || (iVar1 = BN_is_zero(order), iVar1 != 0)) ||
     (iVar1 = BN_is_negative(order), iVar1 != 0)) {
LAB_00128204:
    ERR_put_error(0x10,0x6f,0x7a,"crypto/ec/ec_lib.c",0x160);
    return 0;
  }
  iVar1 = BN_num_bits(order);
  iVar2 = BN_num_bits(*(BIGNUM **)(group + 0x28));
  if (iVar2 + 1 < iVar1) goto LAB_00128204;
  if ((cofactor != (BIGNUM *)0x0) && (iVar1 = BN_is_negative(cofactor), iVar1 != 0)) {
    ERR_put_error(0x10,0x6f,0xa4,"crypto/ec/ec_lib.c",0x16a);
    return 0;
  }
  dst = *(EC_POINT **)(group + 4);
  if (dst == (EC_POINT *)0x0) {
    dst = EC_POINT_new(group);
    *(EC_POINT **)(group + 4) = dst;
    if (dst == (EC_POINT *)0x0) {
      return 0;
    }
  }
  iVar1 = EC_POINT_copy(dst,generator);
  if (iVar1 == 0) {
    return 0;
  }
  pBVar3 = BN_copy(*(BIGNUM **)(group + 8),order);
  if (pBVar3 == (BIGNUM *)0x0) {
    return 0;
  }
  if ((cofactor == (BIGNUM *)0x0) || (iVar1 = BN_is_zero(cofactor), iVar1 != 0)) {
    iVar1 = BN_num_bits(*(BIGNUM **)(group + 8));
    iVar2 = BN_num_bits(*(BIGNUM **)(group + 0x28));
    if ((iVar2 + 1) / 2 + 3 < iVar1) {
      pBVar4 = BN_CTX_new();
      if (pBVar4 == (BN_CTX *)0x0) goto LAB_001282f2;
      BN_CTX_start(pBVar4);
      pBVar3 = BN_CTX_get(pBVar4);
      if (pBVar3 != (BIGNUM *)0x0) {
        if (*(int *)(*(int *)group + 4) == 0x197) {
          BN_set_word(pBVar3,0);
          iVar1 = BN_num_bits(*(BIGNUM **)(group + 0x28));
          pBVar5 = (BIGNUM *)BN_set_bit(pBVar3,iVar1 + -1);
        }
        else {
          pBVar5 = BN_copy(pBVar3,*(BIGNUM **)(group + 0x28));
        }
        if (((pBVar5 != (BIGNUM *)0x0) &&
            (iVar1 = BN_rshift1(*(BIGNUM **)(group + 0xc),*(BIGNUM **)(group + 8)), iVar1 != 0)) &&
           (iVar1 = BN_add(*(BIGNUM **)(group + 0xc),*(BIGNUM **)(group + 0xc),pBVar3), iVar1 != 0))
        {
          pBVar5 = *(BIGNUM **)(group + 0xc);
          pBVar3 = BN_value_one();
          iVar1 = BN_add(pBVar5,pBVar5,pBVar3);
          if (iVar1 != 0) {
            iVar1 = BN_div(*(BIGNUM **)(group + 0xc),(BIGNUM *)0x0,*(BIGNUM **)(group + 0xc),
                           *(BIGNUM **)(group + 8),pBVar4);
            BN_CTX_end(pBVar4);
            BN_CTX_free(pBVar4);
            if (iVar1 == 0) goto LAB_001282f2;
            goto LAB_0012832a;
          }
        }
      }
      BN_CTX_end(pBVar4);
      BN_CTX_free(pBVar4);
LAB_001282f2:
      BN_set_word(*(BIGNUM **)(group + 0xc),0);
      return 0;
    }
    BN_set_word(*(BIGNUM **)(group + 0xc),0);
  }
  else {
    pBVar3 = BN_copy(*(BIGNUM **)(group + 0xc),cofactor);
    if (pBVar3 == (BIGNUM *)0x0) {
      return 0;
    }
  }
LAB_0012832a:
  iVar1 = BN_is_odd(*(undefined4 *)(group + 8));
  if (iVar1 == 0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(group + 0x5c));
    *(undefined4 *)(group + 0x5c) = 0;
    return 1;
  }
  pBVar4 = BN_CTX_new();
  BN_MONT_CTX_free(*(BN_MONT_CTX **)(group + 0x5c));
  *(undefined4 *)(group + 0x5c) = 0;
  if (pBVar4 != (BN_CTX *)0x0) {
    mont = BN_MONT_CTX_new();
    *(BN_MONT_CTX **)(group + 0x5c) = mont;
    if (mont != (BN_MONT_CTX *)0x0) {
      iVar2 = BN_MONT_CTX_set(mont,*(BIGNUM **)(group + 8),pBVar4);
      iVar1 = 1;
      if (iVar2 == 0) {
        BN_MONT_CTX_free(*(BN_MONT_CTX **)(group + 0x5c));
        *(undefined4 *)(group + 0x5c) = 0;
        iVar1 = 0;
      }
      goto LAB_00128372;
    }
  }
  iVar1 = 0;
LAB_00128372:
  BN_CTX_free(pBVar4);
  return iVar1;
}


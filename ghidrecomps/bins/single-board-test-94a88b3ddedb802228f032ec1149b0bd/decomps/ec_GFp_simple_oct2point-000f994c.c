
uint ec_GFp_simple_oct2point
               (EC_GROUP *param_1,EC_POINT *param_2,byte *param_3,int param_4,BN_CTX *param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *pBVar4;
  int iVar5;
  BIGNUM *a;
  uint uVar6;
  BN_CTX *c;
  
  if (param_4 == 0) {
    ERR_put_error(0x10,0x67,100,DAT_000f9b2c,0x152);
    return 0;
  }
  bVar1 = *param_3;
  uVar2 = (uint)bVar1;
  uVar6 = uVar2 & 0xfffffffe;
  if (((bVar1 & 0xfc) != 0) && ((uVar2 & 0xfffffffc) != 4)) {
    iVar5 = 0x15b;
LAB_000f9a50:
    ERR_put_error(0x10,0x67,0x66,DAT_000f9b2c,iVar5);
    return 0;
  }
  if ((bVar1 & 0xfa) == 0) {
    if ((bVar1 & 1) != 0) {
      ERR_put_error(0x10,0x67,0x66,DAT_000f9b2c,0x15f);
      return uVar2 & 0xfffffffa;
    }
    if ((bVar1 & 0xfe) == 0) {
      if (param_4 == 1) {
        uVar2 = EC_POINT_set_to_infinity(param_1,param_2);
        return uVar2;
      }
      ERR_put_error(0x10,0x67,0x66,DAT_000f9b2c,0x165);
      return uVar6;
    }
  }
  a = (BIGNUM *)(param_1 + 0x48);
  iVar3 = BN_num_bits(a);
  iVar5 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar5 = iVar3 + 7;
  }
  iVar5 = iVar5 >> 3;
  iVar3 = iVar5;
  if (uVar6 != 2) {
    iVar3 = iVar5 * 2;
  }
  if (iVar3 + 1 != param_4) {
    iVar5 = 0x172;
    goto LAB_000f9a50;
  }
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_5);
  ret = BN_CTX_get(param_5);
  ret_00 = BN_CTX_get(param_5);
  if ((ret_00 != (BIGNUM *)0x0) &&
     (pBVar4 = BN_bin2bn(param_3 + 1,iVar5,ret), pBVar4 != (BIGNUM *)0x0)) {
    iVar3 = BN_ucmp(ret,a);
    if (-1 < iVar3) {
      iVar5 = 0x185;
      goto LAB_000f9a28;
    }
    if (uVar6 == 2) {
      iVar5 = EC_POINT_set_compressed_coordinates_GFp(param_1,param_2,ret,uVar2 & 1,param_5);
    }
    else {
      pBVar4 = BN_bin2bn(param_3 + iVar5 + 1,iVar5,ret_00);
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_000f9a36;
      iVar5 = BN_ucmp(ret_00,a);
      if (-1 < iVar5) {
        iVar5 = 0x191;
LAB_000f9a28:
        ERR_put_error(0x10,0x67,0x66,DAT_000f9b2c,iVar5);
        goto LAB_000f9a36;
      }
      if (uVar6 == 6) {
        if (ret_00->top < 1) {
          uVar6 = 0;
        }
        else {
          uVar6 = *ret_00->d & 1;
        }
        if (uVar6 != (uVar2 & 1)) {
          iVar5 = 0x196;
          goto LAB_000f9a28;
        }
      }
      iVar5 = EC_POINT_set_affine_coordinates_GFp(param_1,param_2,ret,ret_00,param_5);
    }
    if (iVar5 != 0) {
      iVar5 = EC_POINT_is_on_curve(param_1,param_2,param_5);
      if (iVar5 < 1) {
        uVar2 = 0;
        ERR_put_error(0x10,0x67,0x6b,DAT_000f9b2c,0x1a1);
      }
      else {
        uVar2 = 1;
      }
      goto LAB_000f9a38;
    }
  }
LAB_000f9a36:
  uVar2 = 0;
LAB_000f9a38:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
    return uVar2;
  }
  return uVar2;
}


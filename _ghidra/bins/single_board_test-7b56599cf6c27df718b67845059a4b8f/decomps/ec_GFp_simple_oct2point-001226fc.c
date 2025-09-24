
int ec_GFp_simple_oct2point
              (EC_GROUP *param_1,EC_POINT *param_2,byte *param_3,int param_4,BN_CTX *param_5)

{
  byte bVar1;
  int iVar2;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *pBVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  BN_CTX *local_2c;
  
  if (param_4 == 0) {
    ERR_put_error(0x10,0x67,100,"crypto/ec/ecp_oct.c",0x118);
    return 0;
  }
  bVar1 = *param_3;
  uVar6 = bVar1 & 1;
  uVar5 = bVar1 & 0xfffffffe;
  if ((bVar1 & 0xf8) != 0) {
    iVar4 = 0x121;
    goto LAB_00122742;
  }
  if ((bVar1 & 0xfa) == 0) {
    if ((bVar1 & 1) != 0) {
      iVar4 = 0x125;
      goto LAB_00122742;
    }
    if ((bVar1 & 0xfe) == 0) {
      if (param_4 == 1) {
        iVar4 = EC_POINT_set_to_infinity(param_1,param_2);
        return iVar4;
      }
      iVar4 = 299;
      goto LAB_00122742;
    }
  }
  iVar2 = BN_num_bits(*(BIGNUM **)(param_1 + 0x28));
  iVar4 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar4 = iVar2 + 0xe;
  }
  iVar4 = iVar4 >> 3;
  iVar2 = iVar4;
  if (uVar5 != 2) {
    iVar2 = iVar4 * 2;
  }
  if (iVar2 + 1 != param_4) {
    iVar4 = 0x138;
LAB_00122742:
    ERR_put_error(0x10,0x67,0x66,"crypto/ec/ecp_oct.c",iVar4);
    return 0;
  }
  if (param_5 == (BN_CTX *)0x0) {
    param_5 = BN_CTX_new();
    local_2c = param_5;
    if (param_5 == (BN_CTX *)0x0) {
      return 0;
    }
  }
  else {
    local_2c = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_5);
  ret = BN_CTX_get(param_5);
  ret_00 = BN_CTX_get(param_5);
  if ((ret_00 != (BIGNUM *)0x0) &&
     (pBVar3 = BN_bin2bn(param_3 + 1,iVar4,ret), pBVar3 != (BIGNUM *)0x0)) {
    iVar2 = BN_ucmp(ret,*(BIGNUM **)(param_1 + 0x28));
    if (iVar2 < 0) {
      if (uVar5 == 2) {
        iVar4 = EC_POINT_set_compressed_coordinates(param_1,param_2,ret,uVar6,param_5);
        if (iVar4 != 0) {
          iVar4 = 1;
        }
        goto LAB_001227e6;
      }
      pBVar3 = BN_bin2bn(param_3 + iVar4 + 1,iVar4,ret_00);
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_001227e4;
      iVar4 = BN_ucmp(ret_00,*(BIGNUM **)(param_1 + 0x28));
      if (iVar4 < 0) {
        if ((uVar5 != 6) || (uVar5 = BN_is_odd(ret_00), uVar6 == uVar5)) {
          iVar4 = EC_POINT_set_affine_coordinates(param_1,param_2,ret,ret_00,param_5);
          if (iVar4 != 0) {
            iVar4 = 1;
          }
          goto LAB_001227e6;
        }
        iVar4 = 0x15b;
      }
      else {
        iVar4 = 0x156;
      }
    }
    else {
      iVar4 = 0x14b;
    }
    ERR_put_error(0x10,0x67,0x66,"crypto/ec/ecp_oct.c",iVar4);
  }
LAB_001227e4:
  iVar4 = 0;
LAB_001227e6:
  BN_CTX_end(param_5);
  BN_CTX_free(local_2c);
  return iVar4;
}


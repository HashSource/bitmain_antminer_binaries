
int ec_GF2m_simple_oct2point
              (EC_GROUP *param_1,EC_POINT *param_2,byte *param_3,int param_4,BN_CTX *param_5)

{
  byte bVar1;
  int iVar2;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  BN_CTX *local_38;
  
  if (param_4 == 0) {
    ERR_put_error(0x10,0xa0,100,"crypto/ec/ec2_oct.c",0xf7);
    return 0;
  }
  bVar1 = *param_3;
  uVar8 = bVar1 & 1;
  uVar7 = bVar1 & 0xfffffffe;
  if ((bVar1 & 0xf8) != 0) {
    iVar6 = 0x10c;
    goto LAB_001b0026;
  }
  if ((bVar1 & 0xfa) == 0) {
    if ((bVar1 & 1) != 0) {
      iVar6 = 0x110;
      goto LAB_001b0026;
    }
    if ((bVar1 & 0xfe) == 0) {
      if (param_4 == 1) {
        iVar6 = EC_POINT_set_to_infinity(param_1,param_2);
        return iVar6;
      }
      iVar6 = 0x117;
      goto LAB_001b0026;
    }
  }
  iVar2 = EC_GROUP_get_degree(param_1);
  iVar6 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar6 = iVar2 + 7;
  }
  iVar6 = iVar6 >> 3;
  iVar5 = iVar6;
  if (uVar7 != 2) {
    iVar5 = iVar6 * 2;
  }
  if (iVar5 + 1 != param_4) {
    iVar6 = 0x125;
LAB_001b0026:
    ERR_put_error(0x10,0xa0,0x66,"crypto/ec/ec2_oct.c",iVar6);
    return 0;
  }
  if (param_5 == (BN_CTX *)0x0) {
    param_5 = BN_CTX_new();
    local_38 = param_5;
    if (param_5 == (BN_CTX *)0x0) {
      return 0;
    }
  }
  else {
    local_38 = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_5);
  ret = BN_CTX_get(param_5);
  ret_00 = BN_CTX_get(param_5);
  pBVar3 = BN_CTX_get(param_5);
  if ((pBVar3 != (BIGNUM *)0x0) &&
     (pBVar4 = BN_bin2bn(param_3 + 1,iVar6,ret), pBVar4 != (BIGNUM *)0x0)) {
    iVar5 = BN_num_bits(ret);
    if (iVar2 < iVar5) {
      iVar6 = 0x139;
    }
    else {
      if (uVar7 == 2) {
        iVar6 = EC_POINT_set_compressed_coordinates(param_1,param_2,ret,uVar8,param_5);
        if (iVar6 != 0) {
          iVar6 = 1;
        }
        goto LAB_001b011c;
      }
      pBVar4 = BN_bin2bn(param_3 + iVar6 + 1,iVar6,ret_00);
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_001b011a;
      iVar6 = BN_num_bits(ret_00);
      if (iVar6 <= iVar2) {
        if (uVar7 == 6) {
          iVar6 = BN_is_zero(ret);
          if (iVar6 == 0) {
            iVar6 = (**(code **)(*(int *)param_1 + 0x90))(param_1,pBVar3,ret_00,ret,param_5);
            if (iVar6 == 0) goto LAB_001b011a;
            uVar7 = BN_is_odd(pBVar3);
            if (uVar8 != uVar7) {
              iVar6 = 0;
              ERR_put_error(0x10,0x10,0x66,"crypto/ec/ec2_oct.c",0x156);
              goto LAB_001b011c;
            }
          }
          else if ((bVar1 & 1) != 0) {
            iVar6 = 0;
            ERR_put_error(0x10,0x10,0x66,"crypto/ec/ec2_oct.c",0x14f);
            goto LAB_001b011c;
          }
        }
        iVar6 = EC_POINT_set_affine_coordinates(param_1,param_2,ret,ret_00,param_5);
        if (iVar6 != 0) {
          iVar6 = 1;
        }
        goto LAB_001b011c;
      }
      iVar6 = 0x144;
    }
    ERR_put_error(0x10,0xa0,0x66,"crypto/ec/ec2_oct.c",iVar6);
  }
LAB_001b011a:
  iVar6 = 0;
LAB_001b011c:
  BN_CTX_end(param_5);
  BN_CTX_free(local_38);
  return iVar6;
}


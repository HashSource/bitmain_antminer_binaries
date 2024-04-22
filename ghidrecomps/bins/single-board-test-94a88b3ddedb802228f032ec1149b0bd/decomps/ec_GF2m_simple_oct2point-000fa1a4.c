
uint ec_GF2m_simple_oct2point
               (int *param_1,EC_POINT *param_2,byte *param_3,int param_4,BN_CTX *param_5)

{
  byte bVar1;
  int iVar2;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  BN_CTX *c;
  
  if (param_4 == 0) {
    ERR_put_error(0x10,0xa0,100,DAT_000fa3a4,0x135);
    return 0;
  }
  bVar1 = *param_3;
  uVar5 = (uint)bVar1;
  uVar7 = uVar5 & 0xfffffffe;
  if (((bVar1 & 0xfc) != 0) && ((uVar5 & 0xfffffffc) != 4)) {
    iVar6 = 0x13e;
LAB_000fa2b0:
    ERR_put_error(0x10,0xa0,0x66,DAT_000fa3a4,iVar6);
    return 0;
  }
  if ((bVar1 & 0xfa) == 0) {
    if ((bVar1 & 1) != 0) {
      ERR_put_error(0x10,0xa0,0x66,DAT_000fa3a4,0x142);
      return uVar5 & 0xfffffffa;
    }
    if ((bVar1 & 0xfe) == 0) {
      if (param_4 == 1) {
        uVar5 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
        return uVar5;
      }
      ERR_put_error(0x10,0xa0,0x66,DAT_000fa3a4,0x148);
      return uVar7;
    }
  }
  iVar2 = EC_GROUP_get_degree((EC_GROUP *)param_1);
  iVar6 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar6 = iVar2 + 7;
  }
  iVar6 = iVar6 >> 3;
  iVar2 = iVar6;
  if (uVar7 != 2) {
    iVar2 = iVar6 * 2;
  }
  if (iVar2 + 1 != param_4) {
    iVar6 = 0x155;
    goto LAB_000fa2b0;
  }
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_5);
  ret = BN_CTX_get(param_5);
  ret_00 = BN_CTX_get(param_5);
  pBVar3 = BN_CTX_get(param_5);
  if ((pBVar3 != (BIGNUM *)0x0) &&
     (pBVar4 = BN_bin2bn(param_3 + 1,iVar6,ret), pBVar4 != (BIGNUM *)0x0)) {
    iVar2 = BN_ucmp(ret,(BIGNUM *)(param_1 + 0x12));
    if (iVar2 < 0) {
      if (uVar7 == 2) {
        iVar6 = EC_POINT_set_compressed_coordinates_GF2m(param_1,param_2,ret,uVar5 & 1,param_5);
      }
      else {
        pBVar4 = BN_bin2bn(param_3 + iVar6 + 1,iVar6,ret_00);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_000fa296;
        iVar6 = BN_ucmp(ret_00,(BIGNUM *)(param_1 + 0x12));
        if (-1 < iVar6) {
          iVar6 = 0x175;
          goto LAB_000fa288;
        }
        if (uVar7 == 6) {
          iVar6 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar3,ret_00,ret,param_5);
          if (iVar6 == 0) goto LAB_000fa296;
          if (pBVar3->top < 1) {
            uVar7 = 0;
          }
          else {
            uVar7 = *pBVar3->d & 1;
          }
          if (uVar7 != (uVar5 & 1)) {
            iVar6 = 0x17c;
            goto LAB_000fa288;
          }
        }
        iVar6 = EC_POINT_set_affine_coordinates_GF2m(param_1,param_2,ret,ret_00,param_5);
      }
      if (iVar6 != 0) {
        iVar6 = EC_POINT_is_on_curve((EC_GROUP *)param_1,param_2,param_5);
        if (iVar6 < 1) {
          uVar5 = 0;
          ERR_put_error(0x10,0xa0,0x6b,DAT_000fa3a4,0x187);
        }
        else {
          uVar5 = 1;
        }
        goto LAB_000fa298;
      }
    }
    else {
      iVar6 = 0x169;
LAB_000fa288:
      ERR_put_error(0x10,0xa0,0x66,DAT_000fa3a4,iVar6);
    }
  }
LAB_000fa296:
  uVar5 = 0;
LAB_000fa298:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
    return uVar5;
  }
  return uVar5;
}



uint ec_GFp_simple_point2oct
               (EC_GROUP *param_1,EC_POINT *param_2,uint param_3,char *param_4,uint param_5,
               BN_CTX *param_6)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  BIGNUM *a;
  BIGNUM *a_00;
  char *__s;
  uint uVar5;
  uint __n;
  BN_CTX *c;
  uint uVar6;
  
  if (param_3 != 4 && (param_3 & 0xfffffffb) != 2) {
    ERR_put_error(0x10,0x68,0x68,"crypto/ec/ecp_oct.c",0xa7);
LAB_0011e2e2:
    c = (BN_CTX *)0x0;
    goto LAB_0011e2e6;
  }
  iVar3 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar3 != 0) {
    if (param_4 == (char *)0x0) {
      return 1;
    }
    if (param_5 == 0) {
      ERR_put_error(0x10,0x68,100,"crypto/ec/ecp_oct.c",0xaf);
      return 0;
    }
    *param_4 = '\0';
    return 1;
  }
  iVar4 = BN_num_bits(*(BIGNUM **)(param_1 + 0x28));
  iVar3 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar3 = iVar4 + 0xe;
  }
  uVar1 = iVar3 >> 3;
  uVar6 = uVar1;
  if (param_3 != 2) {
    uVar6 = uVar1 * 2;
  }
  uVar6 = uVar6 + 1;
  if (param_4 == (char *)0x0) {
    c = (BN_CTX *)0x0;
    goto LAB_0011e408;
  }
  if (param_5 < uVar6) {
    ERR_put_error(0x10,0x68,100,"crypto/ec/ecp_oct.c",0xc0);
    goto LAB_0011e2e2;
  }
  c = (BN_CTX *)0x0;
  if ((param_6 == (BN_CTX *)0x0) && (c = BN_CTX_new(), param_6 = c, c == (BN_CTX *)0x0)) {
    return 0;
  }
  BN_CTX_start(param_6);
  a = BN_CTX_get(param_6);
  a_00 = BN_CTX_get(param_6);
  if ((a_00 != (BIGNUM *)0x0) &&
     (iVar3 = EC_POINT_get_affine_coordinates(param_1,param_2,a,a_00,param_6), iVar3 != 0)) {
    if ((param_3 & 0xfffffffb) == 2) {
      iVar3 = BN_is_odd(a_00);
      cVar2 = (char)param_3 + '\x01';
      if (iVar3 == 0) goto LAB_0011e37e;
    }
    else {
LAB_0011e37e:
      cVar2 = (char)param_3;
    }
    *param_4 = cVar2;
    iVar4 = BN_num_bits(a);
    iVar3 = iVar4 + 0xe;
    if (-1 < iVar4 + 7) {
      iVar3 = iVar4 + 7;
    }
    uVar5 = uVar1 - (iVar3 >> 3);
    if (uVar1 < uVar5) {
      iVar3 = 0xde;
    }
    else {
      iVar3 = 1;
      if (uVar5 != 0) {
        iVar3 = uVar5 + 1;
        memset(param_4 + 1,0,uVar5);
      }
      iVar4 = BN_bn2bin(a,(uchar *)(param_4 + iVar3));
      uVar5 = iVar3 + iVar4;
      if (uVar5 == uVar1 + 1) {
        if ((param_3 & 0xfffffffd) == 4) {
          iVar4 = BN_num_bits(a_00);
          iVar3 = iVar4 + 0xe;
          if (-1 < iVar4 + 7) {
            iVar3 = iVar4 + 7;
          }
          __n = uVar1 - (iVar3 >> 3);
          if (uVar1 < __n) {
            iVar3 = 0xf0;
            goto LAB_0011e3c0;
          }
          if (__n != 0) {
            __s = param_4 + uVar5;
            uVar5 = uVar5 + __n;
            memset(__s,0,__n);
          }
          iVar3 = BN_bn2bin(a_00,(uchar *)(param_4 + uVar5));
          uVar5 = uVar5 + iVar3;
        }
        if (uVar5 == uVar6) {
          BN_CTX_end(param_6);
LAB_0011e408:
          BN_CTX_free(c);
          return uVar6;
        }
        iVar3 = 0xfc;
      }
      else {
        iVar3 = 0xe8;
      }
    }
LAB_0011e3c0:
    ERR_put_error(0x10,0x68,0x44,"crypto/ec/ecp_oct.c",iVar3);
  }
  BN_CTX_end(param_6);
LAB_0011e2e6:
  BN_CTX_free(c);
  return 0;
}


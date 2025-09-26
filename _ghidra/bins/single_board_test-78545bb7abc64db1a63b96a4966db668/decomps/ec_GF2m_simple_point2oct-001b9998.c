
uint ec_GF2m_simple_point2oct
               (EC_GROUP *param_1,EC_POINT *param_2,uint param_3,char *param_4,uint param_5,
               BN_CTX *param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *pBVar4;
  char *__s;
  uint uVar5;
  uint __n;
  BN_CTX *c;
  uint uVar6;
  
  if ((param_3 & 0xfffffffb) == 2 || param_3 == 4) {
    iVar2 = EC_POINT_is_at_infinity(param_1,param_2);
    if (iVar2 != 0) {
      if (param_4 == (char *)0x0) {
        return 1;
      }
      if (param_5 == 0) {
        ERR_put_error(0x10,0xa1,100,"crypto/ec/ec2_oct.c",0x86);
        return 0;
      }
      *param_4 = '\0';
      return 1;
    }
    iVar3 = EC_GROUP_get_degree(param_1);
    iVar2 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar2 = iVar3 + 0xe;
    }
    uVar1 = iVar2 >> 3;
    uVar6 = uVar1;
    if (param_3 != 2) {
      uVar6 = uVar1 * 2;
    }
    uVar6 = uVar6 + 1;
    if (param_4 == (char *)0x0) {
      c = (BN_CTX *)0x0;
      goto LAB_001b9af4;
    }
    if (uVar6 <= param_5) {
      c = (BN_CTX *)0x0;
      if ((param_6 == (BN_CTX *)0x0) && (c = BN_CTX_new(), param_6 = c, c == (BN_CTX *)0x0)) {
        return 0;
      }
      BN_CTX_start(param_6);
      a = BN_CTX_get(param_6);
      a_00 = BN_CTX_get(param_6);
      pBVar4 = BN_CTX_get(param_6);
      if ((pBVar4 != (BIGNUM *)0x0) &&
         (iVar2 = EC_POINT_get_affine_coordinates(param_1,param_2,a,a_00,param_6), iVar2 != 0)) {
        *param_4 = (char)param_3;
        if ((param_3 != 4) && (iVar2 = BN_is_zero(a), iVar2 == 0)) {
          iVar2 = (**(code **)(*(int *)param_1 + 0x90))(param_1,pBVar4,a_00,a,param_6);
          if (iVar2 == 0) goto LAB_001b9ab8;
          iVar2 = BN_is_odd(pBVar4);
          if (iVar2 != 0) {
            *param_4 = *param_4 + '\x01';
          }
        }
        iVar3 = BN_num_bits(a);
        iVar2 = iVar3 + 0xe;
        if (-1 < iVar3 + 7) {
          iVar2 = iVar3 + 7;
        }
        uVar5 = uVar1 - (iVar2 >> 3);
        if (uVar1 < uVar5) {
          iVar2 = 0xb8;
        }
        else {
          iVar2 = 1;
          if (uVar5 != 0) {
            iVar2 = uVar5 + 1;
            memset(param_4 + 1,0,uVar5);
          }
          iVar3 = BN_bn2bin(a,(uchar *)(param_4 + iVar2));
          uVar5 = iVar2 + iVar3;
          if (uVar5 == uVar1 + 1) {
            if ((param_3 & 0xfffffffd) == 4) {
              iVar3 = BN_num_bits(a_00);
              iVar2 = iVar3 + 0xe;
              if (-1 < iVar3 + 7) {
                iVar2 = iVar3 + 7;
              }
              __n = uVar1 - (iVar2 >> 3);
              if (uVar1 < __n) {
                iVar2 = 0xca;
                goto LAB_001b9aac;
              }
              if (__n != 0) {
                __s = param_4 + uVar5;
                uVar5 = uVar5 + __n;
                memset(__s,0,__n);
              }
              iVar2 = BN_bn2bin(a_00,(uchar *)(param_4 + uVar5));
              uVar5 = uVar5 + iVar2;
            }
            if (uVar5 == uVar6) {
              BN_CTX_end(param_6);
LAB_001b9af4:
              BN_CTX_free(c);
              return uVar6;
            }
            iVar2 = 0xd6;
          }
          else {
            iVar2 = 0xc2;
          }
        }
LAB_001b9aac:
        ERR_put_error(0x10,0xa1,0x44,"crypto/ec/ec2_oct.c",iVar2);
      }
LAB_001b9ab8:
      BN_CTX_end(param_6);
      goto LAB_001b99c8;
    }
    ERR_put_error(0x10,0xa1,100,"crypto/ec/ec2_oct.c",0x97);
  }
  else {
    ERR_put_error(0x10,0xa1,0x68,"crypto/ec/ec2_oct.c",0x7e);
  }
  c = (BN_CTX *)0x0;
LAB_001b99c8:
  BN_CTX_free(c);
  return 0;
}


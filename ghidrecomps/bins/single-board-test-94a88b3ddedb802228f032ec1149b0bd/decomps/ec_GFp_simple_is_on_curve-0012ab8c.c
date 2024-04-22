
int ec_GFp_simple_is_on_curve(int *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  int iVar1;
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *a;
  BIGNUM *pBVar2;
  uint uVar3;
  code *pcVar4;
  BIGNUM *m;
  EC_POINT *pEVar5;
  code *pcVar6;
  BN_CTX *local_3c;
  
  iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (iVar1 != 0) {
    return 1;
  }
  pcVar4 = *(code **)(*param_1 + 0x84);
  pcVar6 = *(code **)(*param_1 + 0x88);
  if (param_3 == (BN_CTX *)0x0) {
    param_3 = BN_CTX_new();
    local_3c = param_3;
    if (param_3 == (BN_CTX *)0x0) {
      return -1;
    }
  }
  else {
    local_3c = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_3);
  r = BN_CTX_get(param_3);
  b = BN_CTX_get(param_3);
  a = BN_CTX_get(param_3);
  pBVar2 = BN_CTX_get(param_3);
  if (pBVar2 != (BIGNUM *)0x0) {
    pEVar5 = param_2 + 4;
    iVar1 = (*pcVar6)(param_1,r,pEVar5,param_3);
    if (iVar1 != 0) {
      m = (BIGNUM *)(param_1 + 0x12);
      if (*(int *)(param_2 + 0x40) == 0) {
        iVar1 = (*pcVar6)(param_1,b,param_2 + 0x2c,param_3);
        if (((iVar1 != 0) && (iVar1 = (*pcVar6)(param_1,a,b,param_3), iVar1 != 0)) &&
           (iVar1 = (*pcVar4)(param_1,pBVar2,a,b,param_3), iVar1 != 0)) {
          if (param_1[0x27] == 0) {
            iVar1 = (*pcVar4)(param_1,b,a,param_1 + 0x1d,param_3);
            if (iVar1 != 0) {
              iVar1 = BN_mod_add_quick(r,r,b,m);
              goto joined_r0x0012ad3c;
            }
          }
          else {
            iVar1 = BN_mod_lshift1_quick(b,a,m);
            if ((iVar1 != 0) && (iVar1 = BN_mod_add_quick(b,b,a,m), iVar1 != 0)) {
              iVar1 = BN_mod_sub_quick(r,r,b,m);
joined_r0x0012ad3c:
              if (((iVar1 != 0) && (iVar1 = (*pcVar4)(param_1,r,r,pEVar5,param_3), iVar1 != 0)) &&
                 (iVar1 = (*pcVar4)(param_1,b,param_1 + 0x22,pBVar2,param_3), iVar1 != 0)) {
                iVar1 = BN_mod_add_quick(r,r,b,m);
                goto joined_r0x0012acf2;
              }
            }
          }
        }
      }
      else {
        iVar1 = BN_mod_add_quick(r,r,(BIGNUM *)(param_1 + 0x1d),m);
        if ((iVar1 != 0) && (iVar1 = (*pcVar4)(param_1,r,r,pEVar5,param_3), iVar1 != 0)) {
          iVar1 = BN_mod_add_quick(r,r,(BIGNUM *)(param_1 + 0x22),m);
joined_r0x0012acf2:
          if ((iVar1 != 0) && (iVar1 = (*pcVar6)(param_1,b,param_2 + 0x18,param_3), iVar1 != 0)) {
            uVar3 = BN_ucmp(b,r);
            iVar1 = 1 - uVar3;
            if (1 < uVar3) {
              iVar1 = 0;
            }
            goto LAB_0012ac08;
          }
        }
      }
    }
  }
  iVar1 = -1;
LAB_0012ac08:
  BN_CTX_end(param_3);
  if (local_3c != (BN_CTX *)0x0) {
    BN_CTX_free(local_3c);
  }
  return iVar1;
}


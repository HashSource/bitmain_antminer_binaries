
uint ec_GFp_simple_is_on_curve(EC_GROUP *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  int iVar1;
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *a;
  BIGNUM *pBVar2;
  BIGNUM *m;
  code *pcVar3;
  uint uVar4;
  code *pcVar5;
  BN_CTX *local_38;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 != 0) {
    return 1;
  }
  m = *(BIGNUM **)(param_1 + 0x28);
  pcVar5 = *(code **)(*(int *)param_1 + 0x8c);
  pcVar3 = *(code **)(*(int *)param_1 + 0x88);
  if (param_3 == (BN_CTX *)0x0) {
    param_3 = BN_CTX_new();
    local_38 = param_3;
    if (param_3 == (BN_CTX *)0x0) {
      return 0xffffffff;
    }
  }
  else {
    local_38 = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_3);
  r = BN_CTX_get(param_3);
  b = BN_CTX_get(param_3);
  a = BN_CTX_get(param_3);
  pBVar2 = BN_CTX_get(param_3);
  if ((pBVar2 != (BIGNUM *)0x0) &&
     (iVar1 = (*pcVar5)(param_1,r,*(undefined4 *)(param_2 + 8),param_3), iVar1 != 0)) {
    if (*(int *)(param_2 + 0x14) == 0) {
      iVar1 = (*pcVar5)(param_1,b,*(undefined4 *)(param_2 + 0x10),param_3);
      if (((iVar1 != 0) && (iVar1 = (*pcVar5)(param_1,a,b,param_3), iVar1 != 0)) &&
         (iVar1 = (*pcVar3)(param_1,pBVar2,a,b,param_3), iVar1 != 0)) {
        if (*(int *)(param_1 + 0x4c) == 0) {
          iVar1 = (*pcVar3)(param_1,b,a,*(undefined4 *)(param_1 + 0x44),param_3);
          if (iVar1 != 0) {
            iVar1 = BN_mod_add_quick(r,r,b,m);
            goto joined_r0x0012de3e;
          }
        }
        else {
          iVar1 = BN_mod_lshift1_quick(b,a,m);
          if ((iVar1 != 0) && (iVar1 = BN_mod_add_quick(b,b,a,m), iVar1 != 0)) {
            iVar1 = BN_mod_sub_quick(r,r,b,m);
joined_r0x0012de3e:
            if (((iVar1 != 0) &&
                (iVar1 = (*pcVar3)(param_1,r,r,*(undefined4 *)(param_2 + 8),param_3), iVar1 != 0))
               && (iVar1 = (*pcVar3)(param_1,b,*(undefined4 *)(param_1 + 0x48),pBVar2,param_3),
                  iVar1 != 0)) {
              iVar1 = BN_mod_add_quick(r,r,b,m);
              goto joined_r0x0012ddfc;
            }
          }
        }
      }
    }
    else {
      iVar1 = BN_mod_add_quick(r,r,*(BIGNUM **)(param_1 + 0x44),m);
      if ((iVar1 != 0) &&
         (iVar1 = (*pcVar3)(param_1,r,r,*(undefined4 *)(param_2 + 8),param_3), iVar1 != 0)) {
        iVar1 = BN_mod_add_quick(r,r,*(BIGNUM **)(param_1 + 0x48),m);
joined_r0x0012ddfc:
        if ((iVar1 != 0) &&
           (iVar1 = (*pcVar5)(param_1,b,*(undefined4 *)(param_2 + 0xc),param_3), iVar1 != 0)) {
          iVar1 = BN_ucmp(b,r);
          uVar4 = (uint)(iVar1 == 0);
          goto LAB_0012dd18;
        }
      }
    }
  }
  uVar4 = 0xffffffff;
LAB_0012dd18:
  BN_CTX_end(param_3);
  BN_CTX_free(local_38);
  return uVar4;
}


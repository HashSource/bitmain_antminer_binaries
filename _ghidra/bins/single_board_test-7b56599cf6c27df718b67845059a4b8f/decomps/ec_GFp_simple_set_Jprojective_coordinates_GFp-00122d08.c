
undefined4
ec_GFp_simple_set_Jprojective_coordinates_GFp
          (int *param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5,BN_CTX *param_6)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  BN_CTX *c;
  code *pcVar5;
  
  c = (BN_CTX *)0x0;
  if ((param_6 == (BN_CTX *)0x0) && (param_6 = BN_CTX_new(), c = param_6, param_6 == (BN_CTX *)0x0))
  {
    return 0;
  }
  if (((param_3 == (BIGNUM *)0x0) ||
      ((iVar1 = BN_nnmod(*(BIGNUM **)(param_2 + 8),param_3,(BIGNUM *)param_1[10],param_6),
       iVar1 != 0 &&
       ((*(code **)(*param_1 + 0x98) == (code *)0x0 ||
        (iVar1 = (**(code **)(*param_1 + 0x98))
                           (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 8),
                            param_6), iVar1 != 0)))))) &&
     ((param_4 == (BIGNUM *)0x0 ||
      ((iVar1 = BN_nnmod(*(BIGNUM **)(param_2 + 0xc),param_4,(BIGNUM *)param_1[10],param_6),
       iVar1 != 0 &&
       ((*(code **)(*param_1 + 0x98) == (code *)0x0 ||
        (iVar1 = (**(code **)(*param_1 + 0x98))
                           (param_1,*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0xc),
                            param_6), iVar1 != 0)))))))) {
    if (param_5 != (BIGNUM *)0x0) {
      iVar1 = BN_nnmod(*(BIGNUM **)(param_2 + 0x10),param_5,(BIGNUM *)param_1[10],param_6);
      if (iVar1 == 0) goto LAB_00122d2c;
      iVar1 = BN_is_one(*(undefined4 *)(param_2 + 0x10));
      pcVar5 = *(code **)(*param_1 + 0x98);
      if (pcVar5 != (code *)0x0) {
        if ((iVar1 == 0) || (pcVar3 = *(code **)(*param_1 + 0xa0), pcVar3 == (code *)0x0)) {
          iVar2 = (*pcVar5)(param_1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x10),
                            param_6);
        }
        else {
          iVar2 = (*pcVar3)(param_1,*(undefined4 *)(param_2 + 0x10),param_6);
        }
        if (iVar2 == 0) goto LAB_00122d2c;
      }
      *(int *)(param_2 + 0x14) = iVar1;
    }
    uVar4 = 1;
  }
  else {
LAB_00122d2c:
    uVar4 = 0;
  }
  BN_CTX_free(c);
  return uVar4;
}


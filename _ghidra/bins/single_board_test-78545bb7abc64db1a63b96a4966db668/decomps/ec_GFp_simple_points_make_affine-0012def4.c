
undefined4 ec_GFp_simple_points_make_affine(int *param_1,int param_2,int *param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int *ptr;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  BN_CTX *local_38;
  
  if (param_2 == 0) {
    return 1;
  }
  if (param_4 == (BN_CTX *)0x0) {
    param_4 = BN_CTX_new();
    local_38 = param_4;
    if (param_4 == (BN_CTX *)0x0) {
      return 0;
    }
  }
  else {
    local_38 = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_4);
  pBVar1 = BN_CTX_get(param_4);
  pBVar2 = BN_CTX_get(param_4);
  if ((pBVar2 == (BIGNUM *)0x0) ||
     (ptr = (int *)CRYPTO_malloc(param_2 * 4,"crypto/ec/ecp_smpl.c",0x4c8), ptr == (int *)0x0)) {
    BN_CTX_end(param_4);
    BN_CTX_free(local_38);
    return 0;
  }
  piVar7 = ptr + -1;
  iVar5 = 0;
  do {
    pBVar3 = BN_new();
    iVar5 = iVar5 + 1;
    piVar7 = piVar7 + 1;
    *piVar7 = (int)pBVar3;
    if (pBVar3 == (BIGNUM *)0x0) goto LAB_0012df58;
  } while (param_2 != iVar5);
  iVar5 = BN_is_zero(*(undefined4 *)(*param_3 + 0x10));
  if (iVar5 == 0) {
    pBVar3 = BN_copy((BIGNUM *)*ptr,*(BIGNUM **)(*param_3 + 0x10));
  }
  else if (*(code **)(*param_1 + 0xa0) == (code *)0x0) {
    pBVar3 = (BIGNUM *)BN_set_word((BIGNUM *)*ptr,1);
  }
  else {
    pBVar3 = (BIGNUM *)(**(code **)(*param_1 + 0xa0))(param_1,*ptr,param_4);
  }
  if (pBVar3 != (BIGNUM *)0x0) {
    if (param_2 != 1) {
      piVar6 = param_3 + 1;
      piVar7 = ptr;
      do {
        iVar5 = BN_is_zero(*(undefined4 *)(*piVar6 + 0x10));
        if (iVar5 == 0) {
          pBVar3 = (BIGNUM *)
                   (**(code **)(*param_1 + 0x88))
                             (param_1,piVar7[1],*piVar7,*(undefined4 *)(*piVar6 + 0x10),param_4);
        }
        else {
          pBVar3 = BN_copy((BIGNUM *)piVar7[1],(BIGNUM *)*piVar7);
        }
        if (pBVar3 == (BIGNUM *)0x0) goto LAB_0012df58;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      } while (piVar6 != param_3 + param_2);
    }
    iVar5 = (**(code **)(*param_1 + 0x94))(param_1,pBVar1,ptr[param_2 + -1],param_4);
    if (iVar5 == 0) {
      ERR_put_error(0x10,0x89,3,"crypto/ec/ecp_smpl.c",0x4f5);
      uVar9 = 0;
      goto LAB_0012df5c;
    }
    if ((*(code **)(*param_1 + 0x98) == (code *)0x0) ||
       ((iVar5 = (**(code **)(*param_1 + 0x98))(param_1,pBVar1,pBVar1,param_4), iVar5 != 0 &&
        (iVar5 = (**(code **)(*param_1 + 0x98))(param_1,pBVar1,pBVar1,param_4), iVar5 != 0)))) {
      iVar5 = param_2 + -1;
      if (iVar5 != 0) {
        piVar6 = ptr + param_2 + -2;
        piVar7 = param_3 + param_2;
        do {
          iVar4 = BN_is_zero(*(undefined4 *)(piVar7[-1] + 0x10));
          if ((iVar4 == 0) &&
             (((iVar4 = (**(code **)(*param_1 + 0x88))(param_1,pBVar2,*piVar6,pBVar1,param_4),
               iVar4 == 0 ||
               (iVar4 = (**(code **)(*param_1 + 0x88))
                                  (param_1,pBVar1,pBVar1,*(undefined4 *)(piVar7[-1] + 0x10),param_4)
               , iVar4 == 0)) ||
              (pBVar3 = BN_copy(*(BIGNUM **)(piVar7[-1] + 0x10),pBVar2), pBVar3 == (BIGNUM *)0x0))))
          goto LAB_0012df58;
          iVar5 = iVar5 + -1;
          piVar7 = piVar7 + -1;
          piVar6 = piVar6 + -1;
        } while (iVar5 != 0);
      }
      iVar5 = BN_is_zero(*(undefined4 *)(*param_3 + 0x10));
      if ((iVar5 != 0) ||
         (pBVar2 = BN_copy(*(BIGNUM **)(*param_3 + 0x10),pBVar1), pBVar2 != (BIGNUM *)0x0)) {
        iVar5 = 0;
        param_3 = param_3 + -1;
        do {
          param_3 = param_3 + 1;
          iVar8 = *param_3;
          iVar4 = BN_is_zero(*(undefined4 *)(iVar8 + 0x10));
          if (iVar4 == 0) {
            iVar4 = (**(code **)(*param_1 + 0x8c))
                              (param_1,pBVar1,*(undefined4 *)(iVar8 + 0x10),param_4);
            if (((iVar4 == 0) ||
                (iVar4 = (**(code **)(*param_1 + 0x88))
                                   (param_1,*(undefined4 *)(iVar8 + 8),*(undefined4 *)(iVar8 + 8),
                                    pBVar1,param_4), iVar4 == 0)) ||
               ((iVar4 = (**(code **)(*param_1 + 0x88))
                                   (param_1,pBVar1,pBVar1,*(undefined4 *)(iVar8 + 0x10),param_4),
                iVar4 == 0 ||
                (iVar4 = (**(code **)(*param_1 + 0x88))
                                   (param_1,*(undefined4 *)(iVar8 + 0xc),
                                    *(undefined4 *)(iVar8 + 0xc),pBVar1,param_4), iVar4 == 0))))
            goto LAB_0012df58;
            if (*(code **)(*param_1 + 0xa0) == (code *)0x0) {
              iVar4 = BN_set_word(*(BIGNUM **)(iVar8 + 0x10),1);
            }
            else {
              iVar4 = (**(code **)(*param_1 + 0xa0))(param_1,*(undefined4 *)(iVar8 + 0x10),param_4);
            }
            if (iVar4 == 0) goto LAB_0012df58;
            *(undefined4 *)(iVar8 + 0x14) = 1;
          }
          iVar5 = iVar5 + 1;
        } while (param_2 != iVar5);
        uVar9 = 1;
        goto LAB_0012df5c;
      }
    }
  }
LAB_0012df58:
  uVar9 = 0;
LAB_0012df5c:
  BN_CTX_end(param_4);
  BN_CTX_free(local_38);
  pBVar1 = (BIGNUM *)*ptr;
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar5 = 0;
    piVar7 = ptr;
    do {
      iVar5 = iVar5 + 1;
      BN_clear_free(pBVar1);
      if (param_2 == iVar5) break;
      piVar7 = piVar7 + 1;
      pBVar1 = (BIGNUM *)*piVar7;
    } while (pBVar1 != (BIGNUM *)0x0);
  }
  CRYPTO_free(ptr);
  return uVar9;
}


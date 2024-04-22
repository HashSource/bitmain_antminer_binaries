
BIGNUM * ec_GFp_simple_points_make_affine(int *param_1,int param_2,int *param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  BIGNUM **ptr;
  int iVar5;
  BIGNUM **ppBVar6;
  int *piVar7;
  BIGNUM *pBVar8;
  BIGNUM **ppBVar9;
  BN_CTX *local_38;
  
  if (param_2 == 0) {
    return (BIGNUM *)0x1;
  }
  if (param_4 == (BN_CTX *)0x0) {
    param_4 = BN_CTX_new();
    local_38 = param_4;
    if (param_4 == (BN_CTX *)0x0) {
      return (BIGNUM *)0x0;
    }
  }
  else {
    local_38 = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_4);
  pBVar1 = BN_CTX_get(param_4);
  pBVar2 = BN_CTX_get(param_4);
  if (pBVar1 != (BIGNUM *)0x0 && pBVar2 != (BIGNUM *)0x0) {
    iVar5 = 0;
    ptr = (BIGNUM **)CRYPTO_malloc(param_2 * 4,DAT_0012a8bc,0x4f9);
    if (ptr != (BIGNUM **)0x0) {
      ppBVar6 = ptr + -1;
      do {
        pBVar8 = BN_new();
        iVar5 = iVar5 + 1;
        ppBVar6 = ppBVar6 + 1;
        *ppBVar6 = pBVar8;
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_0012a5fe;
      } while (iVar5 != param_2);
      if (*(int *)(*param_3 + 0x30) == 0) {
        if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
          pBVar8 = (BIGNUM *)BN_set_word(*ptr,1);
        }
        else {
          pBVar8 = (BIGNUM *)(**(code **)(*param_1 + 0x98))(param_1,*ptr,param_4);
        }
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_0012a5fe;
      }
      else {
        pBVar8 = BN_copy(*ptr,(BIGNUM *)(*param_3 + 0x2c));
        if (pBVar8 == (BIGNUM *)0x0) {
          pBVar8 = (BIGNUM *)0x0;
          goto LAB_0012a5fe;
        }
      }
      if (param_2 != 1) {
        iVar5 = 1;
        ppBVar9 = ptr;
        piVar7 = param_3;
        ppBVar6 = ptr;
        do {
          piVar7 = piVar7 + 1;
          iVar5 = iVar5 + 1;
          if (*(int *)(*piVar7 + 0x30) == 0) {
            pBVar8 = BN_copy(ppBVar9[1],*ppBVar6);
          }
          else {
            pBVar8 = (BIGNUM *)
                     (**(code **)(*param_1 + 0x84))
                               (param_1,ppBVar9[1],*ppBVar6,*piVar7 + 0x2c,param_4);
          }
          if (pBVar8 == (BIGNUM *)0x0) {
            pBVar8 = (BIGNUM *)0x0;
            goto LAB_0012a5fe;
          }
          ppBVar9 = ppBVar9 + 1;
          ppBVar6 = ppBVar6 + 1;
        } while (iVar5 != param_2);
      }
      iVar5 = param_2 + -1;
      pBVar8 = BN_mod_inverse(pBVar1,ptr[iVar5],(BIGNUM *)(param_1 + 0x12),param_4);
      if (pBVar8 == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0x89,3,DAT_0012a910,0x525);
        pBVar8 = (BIGNUM *)0x0;
      }
      else if ((*(code **)(*param_1 + 0x90) == (code *)0x0) ||
              ((pBVar8 = (BIGNUM *)(**(code **)(*param_1 + 0x90))(param_1,pBVar1,pBVar1,param_4),
               pBVar8 != (BIGNUM *)0x0 &&
               (pBVar8 = (BIGNUM *)(**(code **)(*param_1 + 0x90))(param_1,pBVar1,pBVar1,param_4),
               pBVar8 != (BIGNUM *)0x0)))) {
        if (iVar5 != 0) {
          ppBVar6 = ptr + param_2;
          piVar7 = param_3 + param_2;
          do {
            if (*(int *)(piVar7[-1] + 0x30) != 0) {
              iVar3 = (**(code **)(*param_1 + 0x84))(param_1,pBVar2,ppBVar6[-2],pBVar1,param_4);
              if (iVar3 == 0) {
                pBVar8 = (BIGNUM *)0x0;
                goto LAB_0012a5fe;
              }
              pBVar8 = (BIGNUM *)
                       (**(code **)(*param_1 + 0x84))
                                 (param_1,pBVar1,pBVar1,piVar7[-1] + 0x2c,param_4);
              if ((pBVar8 == (BIGNUM *)0x0) ||
                 (pBVar8 = BN_copy((BIGNUM *)(piVar7[-1] + 0x2c),pBVar2), pBVar8 == (BIGNUM *)0x0))
              goto LAB_0012a5fe;
            }
            iVar5 = iVar5 + -1;
            piVar7 = piVar7 + -1;
            ppBVar6 = ppBVar6 + -1;
          } while (iVar5 != 0);
        }
        if ((*(int *)(*param_3 + 0x30) == 0) ||
           (pBVar2 = BN_copy((BIGNUM *)(*param_3 + 0x2c),pBVar1), pBVar2 != (BIGNUM *)0x0)) {
          iVar5 = 0;
          param_3 = param_3 + -1;
          do {
            param_3 = param_3 + 1;
            iVar3 = *param_3;
            if (*(int *)(iVar3 + 0x30) != 0) {
              pBVar2 = (BIGNUM *)(iVar3 + 0x2c);
              pBVar8 = (BIGNUM *)(**(code **)(*param_1 + 0x88))(param_1,pBVar1,pBVar2,param_4);
              if (pBVar8 == (BIGNUM *)0x0) goto LAB_0012a5fe;
              iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar3 + 4,iVar3 + 4,pBVar1,param_4);
              if (iVar4 == 0) {
                pBVar8 = (BIGNUM *)0x0;
                goto LAB_0012a5fe;
              }
              pBVar8 = (BIGNUM *)
                       (**(code **)(*param_1 + 0x84))(param_1,pBVar1,pBVar1,pBVar2,param_4);
              if (pBVar8 == (BIGNUM *)0x0) goto LAB_0012a5fe;
              iVar4 = (**(code **)(*param_1 + 0x84))
                                (param_1,iVar3 + 0x18,iVar3 + 0x18,pBVar1,param_4);
              if (iVar4 == 0) {
                pBVar8 = (BIGNUM *)0x0;
                goto LAB_0012a5fe;
              }
              if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
                iVar4 = BN_set_word(pBVar2,1);
              }
              else {
                iVar4 = (**(code **)(*param_1 + 0x98))(param_1,pBVar2,param_4);
              }
              if (iVar4 == 0) {
                pBVar8 = (BIGNUM *)0x0;
                goto LAB_0012a5fe;
              }
              *(undefined4 *)(iVar3 + 0x40) = 1;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 != param_2);
          pBVar8 = (BIGNUM *)0x1;
        }
        else {
          pBVar8 = (BIGNUM *)0x0;
        }
      }
      goto LAB_0012a5fe;
    }
  }
  pBVar8 = (BIGNUM *)0x0;
  ptr = (BIGNUM **)0x0;
LAB_0012a5fe:
  BN_CTX_end(param_4);
  if (local_38 != (BN_CTX *)0x0) {
    BN_CTX_free(local_38);
  }
  if (ptr != (BIGNUM **)0x0) {
    pBVar1 = *ptr;
    if (pBVar1 != (BIGNUM *)0x0) {
      iVar5 = 0;
      ppBVar6 = ptr;
      do {
        iVar5 = iVar5 + 1;
        BN_clear_free(pBVar1);
        if (iVar5 == param_2) break;
        ppBVar6 = ppBVar6 + 1;
        pBVar1 = *ppBVar6;
      } while (pBVar1 != (BIGNUM *)0x0);
    }
    CRYPTO_free(ptr);
  }
  return pBVar8;
}


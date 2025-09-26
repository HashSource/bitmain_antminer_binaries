
BIGNUM * ec_GFp_simple_points_make_affine(int *param_1,int param_2,int *param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  int *ptr;
  int iVar5;
  int *piVar6;
  BIGNUM *pBVar7;
  int *piVar8;
  int *piVar9;
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
    ptr = (int *)CRYPTO_malloc(param_2 * 4,"ecp_smpl.c",0x4f9);
    if (ptr != (int *)0x0) {
      piVar6 = ptr + -1;
      do {
        pBVar7 = BN_new();
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 1;
        *piVar6 = (int)pBVar7;
        if (pBVar7 == (BIGNUM *)0x0) goto LAB_001c1906;
      } while (iVar5 != param_2);
      if (*(int *)(*param_3 + 0x30) == 0) {
        if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
          pBVar7 = (BIGNUM *)BN_set_word((BIGNUM *)*ptr,1);
        }
        else {
          pBVar7 = (BIGNUM *)(**(code **)(*param_1 + 0x98))(param_1,*ptr,param_4);
        }
        if (pBVar7 == (BIGNUM *)0x0) goto LAB_001c1906;
      }
      else {
        pBVar7 = BN_copy((BIGNUM *)*ptr,(BIGNUM *)(*param_3 + 0x2c));
        if (pBVar7 == (BIGNUM *)0x0) {
          pBVar7 = (BIGNUM *)0x0;
          goto LAB_001c1906;
        }
      }
      if (param_2 != 1) {
        iVar5 = 1;
        piVar8 = ptr;
        piVar6 = param_3;
        piVar9 = ptr;
        do {
          piVar6 = piVar6 + 1;
          iVar5 = iVar5 + 1;
          if (*(int *)(*piVar6 + 0x30) == 0) {
            pBVar7 = BN_copy((BIGNUM *)piVar8[1],(BIGNUM *)*piVar9);
          }
          else {
            pBVar7 = (BIGNUM *)
                     (**(code **)(*param_1 + 0x84))
                               (param_1,piVar8[1],*piVar9,*piVar6 + 0x2c,param_4);
          }
          if (pBVar7 == (BIGNUM *)0x0) {
            pBVar7 = (BIGNUM *)0x0;
            goto LAB_001c1906;
          }
          piVar8 = piVar8 + 1;
          piVar9 = piVar9 + 1;
        } while (iVar5 != param_2);
      }
      iVar5 = param_2 + -1;
      pBVar7 = BN_mod_inverse(pBVar1,(BIGNUM *)ptr[iVar5],(BIGNUM *)(param_1 + 0x12),param_4);
      if (pBVar7 == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0x89,3,"ecp_smpl.c",0x525);
        pBVar7 = (BIGNUM *)0x0;
      }
      else if ((*(code **)(*param_1 + 0x90) == (code *)0x0) ||
              ((pBVar7 = (BIGNUM *)(**(code **)(*param_1 + 0x90))(param_1,pBVar1,pBVar1,param_4),
               pBVar7 != (BIGNUM *)0x0 &&
               (pBVar7 = (BIGNUM *)(**(code **)(*param_1 + 0x90))(param_1,pBVar1,pBVar1,param_4),
               pBVar7 != (BIGNUM *)0x0)))) {
        if (iVar5 != 0) {
          piVar9 = ptr + param_2;
          piVar6 = param_3 + param_2;
          do {
            if (*(int *)(piVar6[-1] + 0x30) != 0) {
              iVar3 = (**(code **)(*param_1 + 0x84))(param_1,pBVar2,piVar9[-2],pBVar1,param_4);
              if (iVar3 == 0) {
                pBVar7 = (BIGNUM *)0x0;
                goto LAB_001c1906;
              }
              pBVar7 = (BIGNUM *)
                       (**(code **)(*param_1 + 0x84))
                                 (param_1,pBVar1,pBVar1,piVar6[-1] + 0x2c,param_4);
              if ((pBVar7 == (BIGNUM *)0x0) ||
                 (pBVar7 = BN_copy((BIGNUM *)(piVar6[-1] + 0x2c),pBVar2), pBVar7 == (BIGNUM *)0x0))
              goto LAB_001c1906;
            }
            iVar5 = iVar5 + -1;
            piVar6 = piVar6 + -1;
            piVar9 = piVar9 + -1;
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
              pBVar7 = (BIGNUM *)(**(code **)(*param_1 + 0x88))(param_1,pBVar1,pBVar2,param_4);
              if (pBVar7 == (BIGNUM *)0x0) goto LAB_001c1906;
              iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar3 + 4,iVar3 + 4,pBVar1,param_4);
              if (iVar4 == 0) {
                pBVar7 = (BIGNUM *)0x0;
                goto LAB_001c1906;
              }
              pBVar7 = (BIGNUM *)
                       (**(code **)(*param_1 + 0x84))(param_1,pBVar1,pBVar1,pBVar2,param_4);
              if (pBVar7 == (BIGNUM *)0x0) goto LAB_001c1906;
              iVar4 = (**(code **)(*param_1 + 0x84))
                                (param_1,iVar3 + 0x18,iVar3 + 0x18,pBVar1,param_4);
              if (iVar4 == 0) {
                pBVar7 = (BIGNUM *)0x0;
                goto LAB_001c1906;
              }
              if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
                iVar4 = BN_set_word(pBVar2,1);
              }
              else {
                iVar4 = (**(code **)(*param_1 + 0x98))(param_1,pBVar2,param_4);
              }
              if (iVar4 == 0) {
                pBVar7 = (BIGNUM *)0x0;
                goto LAB_001c1906;
              }
              *(undefined4 *)(iVar3 + 0x40) = 1;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 != param_2);
          pBVar7 = (BIGNUM *)0x1;
        }
        else {
          pBVar7 = (BIGNUM *)0x0;
        }
      }
      goto LAB_001c1906;
    }
  }
  pBVar7 = (BIGNUM *)0x0;
  ptr = (int *)0x0;
LAB_001c1906:
  BN_CTX_end(param_4);
  if (local_38 != (BN_CTX *)0x0) {
    BN_CTX_free(local_38);
  }
  if (ptr != (int *)0x0) {
    pBVar1 = (BIGNUM *)*ptr;
    if (pBVar1 != (BIGNUM *)0x0) {
      iVar5 = 0;
      piVar6 = ptr;
      do {
        iVar5 = iVar5 + 1;
        BN_clear_free(pBVar1);
        if (iVar5 == param_2) break;
        piVar6 = piVar6 + 1;
        pBVar1 = (BIGNUM *)*piVar6;
      } while (pBVar1 != (BIGNUM *)0x0);
    }
    CRYPTO_free(ptr);
  }
  return pBVar7;
}


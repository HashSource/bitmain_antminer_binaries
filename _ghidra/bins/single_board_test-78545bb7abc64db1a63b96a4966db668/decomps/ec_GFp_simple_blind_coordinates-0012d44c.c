
int ec_GFp_simple_blind_coordinates(int *param_1,int param_2,BN_CTX *param_3)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  
  BN_CTX_start(param_3);
  pBVar1 = BN_CTX_get(param_3);
  pBVar2 = BN_CTX_get(param_3);
  if (pBVar2 == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0x11f,0x41,"crypto/ec/ecp_smpl.c",0x59a);
    iVar4 = 0;
  }
  else {
    do {
      ERR_set_mark();
      iVar4 = BN_priv_rand_range(pBVar1,param_1[10]);
      ERR_pop_to_mark();
      if (iVar4 == 0) {
        iVar4 = 1;
        goto LAB_0012d492;
      }
      iVar3 = BN_is_zero(pBVar1);
    } while (iVar3 != 0);
    iVar3 = *param_1;
    if (*(code **)(iVar3 + 0x98) != (code *)0x0) {
      iVar3 = (**(code **)(iVar3 + 0x98))(param_1,pBVar1,pBVar1,param_3);
      if (iVar3 == 0) goto LAB_0012d492;
      iVar3 = *param_1;
    }
    iVar3 = (**(code **)(iVar3 + 0x88))
                      (param_1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x10),
                       pBVar1,param_3);
    if ((((iVar3 != 0) &&
         (iVar3 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar2,pBVar1,param_3), iVar3 != 0)) &&
        (iVar3 = (**(code **)(*param_1 + 0x88))
                           (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 8),pBVar2
                            ,param_3), iVar3 != 0)) &&
       ((iVar3 = (**(code **)(*param_1 + 0x88))(param_1,pBVar2,pBVar2,pBVar1,param_3), iVar3 != 0 &&
        (iVar3 = (**(code **)(*param_1 + 0x88))
                           (param_1,*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0xc),
                            pBVar2,param_3), iVar3 != 0)))) {
      iVar4 = 1;
      *(undefined4 *)(param_2 + 0x14) = 0;
    }
  }
LAB_0012d492:
  BN_CTX_end(param_3);
  return iVar4;
}



int ec_GFp_simple_field_inv(int *param_1,BIGNUM *param_2,undefined4 param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  BN_CTX *c;
  
  c = (BN_CTX *)0x0;
  if ((param_4 == (BN_CTX *)0x0) &&
     (param_4 = (BN_CTX *)BN_CTX_secure_new(), c = param_4, param_4 == (BN_CTX *)0x0)) {
    return 0;
  }
  BN_CTX_start(param_4);
  pBVar1 = BN_CTX_get(param_4);
  if (pBVar1 != (BIGNUM *)0x0) {
    do {
      iVar3 = BN_priv_rand_range(pBVar1,param_1[10]);
      if (iVar3 == 0) goto LAB_001237f0;
      iVar3 = BN_is_zero(pBVar1);
    } while (iVar3 != 0);
    iVar3 = (**(code **)(*param_1 + 0x88))(param_1,param_2,param_3,pBVar1,param_4);
    if (iVar3 != 0) {
      pBVar2 = BN_mod_inverse(param_2,param_2,(BIGNUM *)param_1[10],param_4);
      if (pBVar2 == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0x12a,0xa5,"crypto/ec/ecp_smpl.c",0x579);
        iVar3 = 0;
      }
      else {
        iVar3 = (**(code **)(*param_1 + 0x88))(param_1,param_2,param_2,pBVar1,param_4);
        if (iVar3 != 0) {
          iVar3 = 1;
        }
      }
      goto LAB_001237f2;
    }
  }
LAB_001237f0:
  iVar3 = 0;
LAB_001237f2:
  BN_CTX_end(param_4);
  BN_CTX_free(c);
  return iVar3;
}


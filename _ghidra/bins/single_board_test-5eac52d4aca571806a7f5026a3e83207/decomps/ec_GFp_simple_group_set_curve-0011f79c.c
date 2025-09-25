
undefined4
ec_GFp_simple_group_set_curve
          (int *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *r;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  BN_CTX *c;
  
  iVar1 = BN_num_bits(param_2);
  if ((iVar1 < 3) || (iVar1 = BN_is_odd(param_2), iVar1 == 0)) {
    ERR_put_error(0x10,0xa6,0x67,"crypto/ec/ecp_smpl.c",0x90);
    return 0;
  }
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (c = BN_CTX_new(), param_5 = c, c == (BN_CTX *)0x0)) {
    return 0;
  }
  BN_CTX_start(param_5);
  r = BN_CTX_get(param_5);
  if ((r != (BIGNUM *)0x0) &&
     (pBVar2 = BN_copy((BIGNUM *)param_1[10],param_2), pBVar2 != (BIGNUM *)0x0)) {
    BN_set_negative((BIGNUM *)param_1[10],0);
    iVar1 = BN_nnmod(r,param_3,param_2,param_5);
    if (iVar1 != 0) {
      if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
        pBVar2 = BN_copy((BIGNUM *)param_1[0x11],r);
      }
      else {
        pBVar2 = (BIGNUM *)(**(code **)(*param_1 + 0x98))(param_1,param_1[0x11],r,param_5);
      }
      if ((((pBVar2 != (BIGNUM *)0x0) &&
           (iVar1 = BN_nnmod((BIGNUM *)param_1[0x12],param_4,param_2,param_5), iVar1 != 0)) &&
          ((*(code **)(*param_1 + 0x98) == (code *)0x0 ||
           (iVar1 = (**(code **)(*param_1 + 0x98))(param_1,param_1[0x12],param_1[0x12],param_5),
           iVar1 != 0)))) && (iVar1 = BN_add_word(r,3), iVar1 != 0)) {
        iVar1 = BN_cmp(r,(BIGNUM *)param_1[10]);
        uVar3 = 1;
        param_1[0x13] = (uint)(iVar1 == 0);
        goto LAB_0011f87e;
      }
    }
  }
  uVar3 = 0;
LAB_0011f87e:
  BN_CTX_end(param_5);
  BN_CTX_free(c);
  return uVar3;
}



undefined4
ec_GFp_nist_group_set_curve
          (int param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  int iVar2;
  undefined4 uVar3;
  BN_CTX *c;
  
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_5);
  pBVar1 = BN_CTX_get(param_5);
  if (pBVar1 == (BIGNUM *)0x0) {
    uVar3 = 0;
  }
  else {
    pBVar1 = BN_get0_nist_prime_192();
    iVar2 = BN_ucmp(pBVar1,param_2);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0xa8) = DAT_001247dc;
    }
    else {
      pBVar1 = BN_get0_nist_prime_224();
      iVar2 = BN_ucmp(pBVar1,param_2);
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0xa8) = DAT_001247e0;
      }
      else {
        pBVar1 = BN_get0_nist_prime_256();
        iVar2 = BN_ucmp(pBVar1,param_2);
        if (iVar2 == 0) {
          *(undefined4 *)(param_1 + 0xa8) = DAT_001247e4;
        }
        else {
          pBVar1 = BN_get0_nist_prime_384();
          iVar2 = BN_ucmp(pBVar1,param_2);
          if (iVar2 == 0) {
            *(undefined4 *)(param_1 + 0xa8) = DAT_001247e8;
          }
          else {
            pBVar1 = BN_get0_nist_prime_521();
            iVar2 = BN_ucmp(pBVar1,param_2);
            if (iVar2 != 0) {
              ERR_put_error(0x10,0xca,0x87,DAT_001247f0,0x9d);
              uVar3 = 0;
              goto LAB_0012474e;
            }
            *(undefined4 *)(param_1 + 0xa8) = DAT_001247ec;
          }
        }
      }
    }
    uVar3 = ec_GFp_simple_group_set_curve(param_1,param_2,param_3,param_4,param_5);
  }
LAB_0012474e:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return uVar3;
}


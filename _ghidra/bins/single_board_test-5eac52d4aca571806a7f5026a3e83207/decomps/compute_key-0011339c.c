
undefined4 compute_key(undefined4 param_1,BIGNUM *param_2,DH *param_3)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *pBVar2;
  int iVar3;
  undefined4 uVar4;
  BN_MONT_CTX *pBVar5;
  int local_24 [2];
  
  iVar1 = BN_num_bits(param_3->p);
  if (10000 < iVar1) {
    uVar4 = 0xffffffff;
    ERR_put_error(5,0x66,0x67,"crypto/dh/dh_key.c",0xce);
    ctx = (BN_CTX *)0x0;
    goto LAB_00113432;
  }
  ctx = BN_CTX_new();
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    if (pBVar2 != (BIGNUM *)0x0) {
      if (param_3->priv_key == (BIGNUM *)0x0) {
        uVar4 = 0xffffffff;
        ERR_put_error(5,0x66,100,"crypto/dh/dh_key.c",0xdb);
        goto LAB_00113432;
      }
      pBVar5 = (BN_MONT_CTX *)(param_3->flags & 1);
      if (pBVar5 != (BN_MONT_CTX *)0x0) {
        pBVar5 = BN_MONT_CTX_set_locked(&param_3->method_mont_p,(int)param_3->engine,param_3->p,ctx)
        ;
        BN_set_flags(param_3->priv_key,4);
        if (pBVar5 == (BN_MONT_CTX *)0x0) goto LAB_00113462;
      }
      iVar1 = DH_check_pub_key(param_3,param_2,local_24);
      if ((iVar1 == 0) || (local_24[0] != 0)) {
        uVar4 = 0xffffffff;
        ERR_put_error(5,0x66,0x66,"crypto/dh/dh_key.c",0xe8);
      }
      else {
        iVar1 = (**(code **)((param_3->ex_data).dummy + 0xc))
                          (param_3,pBVar2,param_2,param_3->priv_key,param_3->p,ctx,pBVar5);
        if (iVar1 == 0) {
          uVar4 = 0xffffffff;
          ERR_put_error(5,0x66,3,"crypto/dh/dh_key.c",0xee);
        }
        else {
          iVar3 = BN_num_bits(param_3->p);
          iVar1 = iVar3 + 0xe;
          if (-1 < iVar3 + 7) {
            iVar1 = iVar3 + 7;
          }
          uVar4 = BN_bn2binpad(pBVar2,param_1,iVar1 >> 3);
        }
      }
      goto LAB_00113432;
    }
  }
LAB_00113462:
  uVar4 = 0xffffffff;
LAB_00113432:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return uVar4;
}


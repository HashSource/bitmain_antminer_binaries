
uint dsa_do_verify(uchar *param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *r;
  BN_CTX *ctx;
  BIGNUM *pBVar3;
  BN_MONT_CTX *m_ctx;
  code *pcVar4;
  BIGNUM *local_30;
  BIGNUM *local_2c [2];
  
  if (((*(int *)(param_4 + 8) == 0) || (*(BIGNUM **)(param_4 + 0xc) == (BIGNUM *)0x0)) ||
     (*(int *)(param_4 + 0x10) == 0)) {
    ERR_put_error(10,0x71,0x65,"crypto/dsa/dsa_ossl.c",0x134);
    return 0xffffffff;
  }
  uVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0xc));
  if ((uVar1 & 0xffffffbf) != 0xa0 && uVar1 != 0x100) {
    ERR_put_error(10,0x71,0x66,"crypto/dsa/dsa_ossl.c",0x13b);
    return 0xffffffff;
  }
  iVar2 = BN_num_bits(*(BIGNUM **)(param_4 + 8));
  if (10000 < iVar2) {
    ERR_put_error(10,0x71,0x67,"crypto/dsa/dsa_ossl.c",0x140);
    return 0xffffffff;
  }
  ret = BN_new();
  ret_00 = BN_new();
  r = BN_new();
  ctx = BN_CTX_new();
  if ((ret_00 != (BIGNUM *)0x0 && ret != (BIGNUM *)0x0) &&
     (ctx != (BN_CTX *)0x0 && r != (BIGNUM *)0x0)) {
    DSA_SIG_get0(param_3,&local_30,local_2c);
    iVar2 = BN_is_zero(local_30);
    if ((((iVar2 != 0) ||
         ((iVar2 = BN_is_negative(local_30), iVar2 != 0 ||
          (iVar2 = BN_ucmp(local_30,*(BIGNUM **)(param_4 + 0xc)), -1 < iVar2)))) ||
        (iVar2 = BN_is_zero(local_2c[0]), iVar2 != 0)) ||
       ((iVar2 = BN_is_negative(local_2c[0]), iVar2 != 0 ||
        (iVar2 = BN_ucmp(local_2c[0],*(BIGNUM **)(param_4 + 0xc)), -1 < iVar2)))) {
      uVar1 = 0;
      goto LAB_00122898;
    }
    pBVar3 = BN_mod_inverse(ret_00,local_2c[0],*(BIGNUM **)(param_4 + 0xc),ctx);
    if (pBVar3 != (BIGNUM *)0x0) {
      iVar2 = (int)uVar1 >> 3;
      if (param_2 <= (int)uVar1 >> 3) {
        iVar2 = param_2;
      }
      pBVar3 = BN_bin2bn(param_1,iVar2,ret);
      if (((pBVar3 != (BIGNUM *)0x0) &&
          (iVar2 = BN_mod_mul(ret,ret,ret_00,*(BIGNUM **)(param_4 + 0xc),ctx), iVar2 != 0)) &&
         (iVar2 = BN_mod_mul(ret_00,local_30,ret_00,*(BIGNUM **)(param_4 + 0xc),ctx), iVar2 != 0)) {
        if ((*(uint *)(param_4 + 0x1c) & 1) == 0) {
          m_ctx = (BN_MONT_CTX *)0x0;
        }
        else {
          m_ctx = BN_MONT_CTX_set_locked
                            ((BN_MONT_CTX **)(param_4 + 0x20),*(int *)(param_4 + 0x34),
                             *(BIGNUM **)(param_4 + 8),ctx);
          if (m_ctx == (BN_MONT_CTX *)0x0) goto LAB_00122880;
        }
        pcVar4 = *(code **)(*(int *)(param_4 + 0x2c) + 0x10);
        if (pcVar4 == (code *)0x0) {
          iVar2 = BN_mod_exp2_mont(r,*(BIGNUM **)(param_4 + 0x10),ret,*(BIGNUM **)(param_4 + 0x14),
                                   ret_00,*(BIGNUM **)(param_4 + 8),ctx,m_ctx);
        }
        else {
          iVar2 = (*pcVar4)(param_4,r,*(undefined4 *)(param_4 + 0x10),ret,
                            *(undefined4 *)(param_4 + 0x14),ret_00,*(undefined4 *)(param_4 + 8),ctx,
                            m_ctx);
        }
        if ((iVar2 != 0) &&
           (iVar2 = BN_div((BIGNUM *)0x0,ret,r,*(BIGNUM **)(param_4 + 0xc),ctx), iVar2 != 0)) {
          iVar2 = BN_ucmp(ret,local_30);
          uVar1 = (uint)(iVar2 == 0);
          goto LAB_00122898;
        }
      }
    }
  }
LAB_00122880:
  uVar1 = 0xffffffff;
  ERR_put_error(10,0x71,3,"crypto/dsa/dsa_ossl.c",0x18c);
LAB_00122898:
  BN_CTX_free(ctx);
  BN_free(ret);
  BN_free(ret_00);
  BN_free(r);
  return uVar1;
}


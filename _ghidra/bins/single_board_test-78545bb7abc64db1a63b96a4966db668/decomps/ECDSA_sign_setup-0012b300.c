
int ECDSA_sign_setup(EC_KEY *eckey,BN_CTX *ctx,BIGNUM **kinv,BIGNUM **rp)

{
  int iVar1;
  
  if (*(code **)(*(int *)eckey + 0x2c) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0012b312. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)eckey + 0x2c))();
    return iVar1;
  }
  ERR_put_error(0x10,0xf8,0x98,"crypto/ec/ecdsa_sign.c",0x32);
  return 0;
}


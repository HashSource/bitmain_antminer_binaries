
int ECDSA_sign_setup(EC_KEY *eckey,BN_CTX *ctx,BIGNUM **kinv,BIGNUM **rp)

{
  int iVar1;
  
  iVar1 = ecdsa_check();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*(int *)(iVar1 + 0xc) + 8))(eckey,ctx,kinv,rp);
  }
  return iVar1;
}


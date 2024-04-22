
int DSA_sign_setup(DSA *dsa,BN_CTX *ctx_in,BIGNUM **kinvp,BIGNUM **rp)

{
  int iVar1;
  
  iVar1 = (*dsa->meth->dsa_sign_setup)(dsa,ctx_in,kinvp,rp);
  return iVar1;
}


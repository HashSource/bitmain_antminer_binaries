
int BN_BLINDING_invert_ex(BIGNUM *n,BIGNUM *r,BN_BLINDING *b,BN_CTX *param_4)

{
  int iVar1;
  
  if ((r == (BIGNUM *)0x0) && (r = *(BIGNUM **)(b + 4), r == (BIGNUM *)0x0)) {
    ERR_put_error(3,0x65,0x6b,DAT_000f2650,0x10f);
    iVar1 = 0;
  }
  else {
    iVar1 = BN_mod_mul(n,n,r,*(BIGNUM **)(b + 0xc),param_4);
  }
  return iVar1;
}


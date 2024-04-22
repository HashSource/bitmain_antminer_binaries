
int BN_BLINDING_invert(BIGNUM *n,BN_BLINDING *b,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(BIGNUM **)(b + 4) == (BIGNUM *)0x0) {
    ERR_put_error(3,0x65,0x6b,DAT_000f2614,0x10f);
    iVar1 = 0;
  }
  else {
    iVar1 = BN_mod_mul(n,n,*(BIGNUM **)(b + 4),*(BIGNUM **)(b + 0xc),ctx);
  }
  return iVar1;
}


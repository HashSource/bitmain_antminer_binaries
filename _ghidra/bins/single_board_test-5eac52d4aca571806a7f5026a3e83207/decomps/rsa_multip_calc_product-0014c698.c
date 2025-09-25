
BIGNUM * rsa_multip_calc_product(int param_1)

{
  int iVar1;
  BN_CTX *ctx;
  undefined4 *puVar2;
  BIGNUM *r;
  int iVar3;
  BIGNUM *b;
  BIGNUM *a;
  
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x30));
  if ((iVar1 < 1) || (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
    BN_CTX_free((BN_CTX *)0x0);
    return (BIGNUM *)0x0;
  }
  a = *(BIGNUM **)(param_1 + 0x1c);
  iVar3 = 0;
  b = *(BIGNUM **)(param_1 + 0x20);
  while( true ) {
    puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar3);
    r = (BIGNUM *)puVar2[3];
    iVar3 = iVar3 + 1;
    if (r == (BIGNUM *)0x0) {
      r = (BIGNUM *)BN_secure_new();
      puVar2[3] = r;
      if (r == (BIGNUM *)0x0) break;
    }
    r = (BIGNUM *)BN_mul(r,a,b,ctx);
    if (r == (BIGNUM *)0x0) break;
    a = (BIGNUM *)puVar2[3];
    b = (BIGNUM *)*puVar2;
    if (iVar3 == iVar1) {
      BN_CTX_free(ctx);
      return (BIGNUM *)0x1;
    }
  }
  BN_CTX_free(ctx);
  return r;
}


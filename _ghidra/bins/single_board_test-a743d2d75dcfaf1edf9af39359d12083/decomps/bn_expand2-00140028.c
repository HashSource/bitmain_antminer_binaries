
BIGNUM * bn_expand2(BIGNUM *a,int words)

{
  ulong *puVar1;
  
  if (a->dmax < words) {
    puVar1 = (ulong *)bn_expand_internal();
    if (puVar1 != (ulong *)0x0) {
      if (a->d != (ulong *)0x0) {
        CRYPTO_free(a->d);
      }
      a->d = puVar1;
      a->dmax = words;
      return a;
    }
    a = (BIGNUM *)0x0;
  }
  return a;
}


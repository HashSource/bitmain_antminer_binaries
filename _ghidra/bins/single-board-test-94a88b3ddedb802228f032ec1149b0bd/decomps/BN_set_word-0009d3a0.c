
int BN_set_word(BIGNUM *a,ulong w)

{
  ulong *puVar1;
  ulong uVar2;
  
  if (a->dmax < 1) {
    puVar1 = (ulong *)bn_expand_internal(a,1);
    if (puVar1 == (ulong *)0x0) {
      return 0;
    }
    if (a->d != (ulong *)0x0) {
      CRYPTO_free(a->d);
    }
    a->d = puVar1;
    a->dmax = 1;
  }
  a->neg = 0;
  uVar2 = w;
  if (w != 0) {
    uVar2 = 1;
  }
  *a->d = w;
  a->top = uVar2;
  return 1;
}



void BN_CTX_free(BN_CTX *c)

{
  BIGNUM *a;
  
  if (c == (BN_CTX *)0x0) {
    return;
  }
  if (*(int *)(c + 0x1c) != 0) {
    CRYPTO_free(*(void **)(c + 0x14));
  }
  a = *(BIGNUM **)c;
  while (a != (BIGNUM *)0x0) {
    if (a->d != (ulong *)0x0) {
      BN_clear_free(a);
    }
    if (a[1].d != (ulong *)0x0) {
      BN_clear_free(a + 1);
    }
    if (a[2].d != (ulong *)0x0) {
      BN_clear_free(a + 2);
    }
    if (a[3].d != (ulong *)0x0) {
      BN_clear_free(a + 3);
    }
    if (a[4].d != (ulong *)0x0) {
      BN_clear_free(a + 4);
    }
    if (a[5].d != (ulong *)0x0) {
      BN_clear_free(a + 5);
    }
    if (a[6].d != (ulong *)0x0) {
      BN_clear_free(a + 6);
    }
    if (a[7].d != (ulong *)0x0) {
      BN_clear_free(a + 7);
    }
    if (a[8].d != (ulong *)0x0) {
      BN_clear_free(a + 8);
    }
    if (a[9].d != (ulong *)0x0) {
      BN_clear_free(a + 9);
    }
    if (a[10].d != (ulong *)0x0) {
      BN_clear_free(a + 10);
    }
    if (a[0xb].d != (ulong *)0x0) {
      BN_clear_free(a + 0xb);
    }
    if (a[0xc].d != (ulong *)0x0) {
      BN_clear_free(a + 0xc);
    }
    if (a[0xd].d != (ulong *)0x0) {
      BN_clear_free(a + 0xd);
    }
    if (a[0xe].d != (ulong *)0x0) {
      BN_clear_free(a + 0xe);
    }
    if (a[0xf].d != (ulong *)0x0) {
      BN_clear_free(a + 0xf);
    }
    *(undefined4 *)(c + 4) = *(undefined4 *)((int)*(void **)c + 0x144);
    CRYPTO_free(*(void **)c);
    a = *(BIGNUM **)(c + 4);
    *(BIGNUM **)c = a;
  }
  CRYPTO_free(c);
  return;
}


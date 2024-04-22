
void BN_CTX_init(BN_CTX *c)

{
  BIGNUM *a;
  
  a = *(BIGNUM **)c;
  if (a != (BIGNUM *)0x0) {
    do {
      if (a->d != (ulong *)0x0) {
        BN_clear(a);
      }
      if (a[1].d != (ulong *)0x0) {
        BN_clear(a + 1);
      }
      if (a[2].d != (ulong *)0x0) {
        BN_clear(a + 2);
      }
      if (a[3].d != (ulong *)0x0) {
        BN_clear(a + 3);
      }
      if (a[4].d != (ulong *)0x0) {
        BN_clear(a + 4);
      }
      if (a[5].d != (ulong *)0x0) {
        BN_clear(a + 5);
      }
      if (a[6].d != (ulong *)0x0) {
        BN_clear(a + 6);
      }
      if (a[7].d != (ulong *)0x0) {
        BN_clear(a + 7);
      }
      if (a[8].d != (ulong *)0x0) {
        BN_clear(a + 8);
      }
      if (a[9].d != (ulong *)0x0) {
        BN_clear(a + 9);
      }
      if (a[10].d != (ulong *)0x0) {
        BN_clear(a + 10);
      }
      if (a[0xb].d != (ulong *)0x0) {
        BN_clear(a + 0xb);
      }
      if (a[0xc].d != (ulong *)0x0) {
        BN_clear(a + 0xc);
      }
      if (a[0xd].d != (ulong *)0x0) {
        BN_clear(a + 0xd);
      }
      if (a[0xe].d != (ulong *)0x0) {
        BN_clear(a + 0xe);
      }
      if (a[0xf].d != (ulong *)0x0) {
        BN_clear(a + 0xf);
      }
      a = (BIGNUM *)a[0x10].top;
    } while (a != (BIGNUM *)0x0);
    a = *(BIGNUM **)c;
  }
  *(BIGNUM **)(c + 4) = a;
  *(undefined4 *)(c + 0xc) = 0;
  *(undefined4 *)(c + 0x18) = 0;
  *(undefined4 *)(c + 0x20) = 0;
  *(undefined4 *)(c + 0x24) = 0;
  *(undefined4 *)(c + 0x28) = 0;
  return;
}


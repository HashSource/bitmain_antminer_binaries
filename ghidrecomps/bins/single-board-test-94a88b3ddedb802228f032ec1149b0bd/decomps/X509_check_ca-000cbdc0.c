
int X509_check_ca(X509 *x)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = x->ex_flags;
  if (-1 < (int)(uVar3 << 0x17)) {
    CRYPTO_lock(9,3,DAT_000cbe3c,0x244);
    if (-1 < (int)(x->ex_flags << 0x17)) {
      x509v3_cache_extensions_part_7(x);
    }
    CRYPTO_lock(10,3,DAT_000cbe3c,0x246);
    uVar3 = x->ex_flags;
  }
  if (((uVar3 & 2) == 0) || (uVar1 = x->ex_kusage & 4, uVar1 != 0)) {
    if ((int)(uVar3 << 0x1f) < 0) {
      return (uVar3 << 0x1b) >> 0x1f;
    }
    if ((uVar3 & 0x2040) == 0x2040) {
      return 3;
    }
    if ((uVar3 & 2) != 0) {
      return 4;
    }
    if ((int)(uVar3 << 0x1c) < 0) {
      if ((x->ex_nscert & 7) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = 5;
      }
      return iVar2;
    }
    uVar1 = 0;
  }
  return uVar1;
}


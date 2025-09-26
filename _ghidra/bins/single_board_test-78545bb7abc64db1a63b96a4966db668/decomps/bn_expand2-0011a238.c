
BIGNUM * bn_expand2(BIGNUM *a,int words)

{
  int iVar1;
  ulong *__dest;
  
  if (words <= a->dmax) {
    return a;
  }
  if (words < 0x800000) {
    iVar1 = BN_get_flags(a,2);
    if (iVar1 == 0) {
      iVar1 = BN_get_flags(a,8);
      if (iVar1 == 0) {
        __dest = (ulong *)CRYPTO_zalloc(words << 2,"crypto/bn/bn_lib.c",0x118);
      }
      else {
        __dest = (ulong *)CRYPTO_secure_zalloc(words << 2,"crypto/bn/bn_lib.c",0x116);
      }
      if (__dest != (ulong *)0x0) {
        if (0 < a->top) {
          memcpy(__dest,a->d,a->top << 2);
        }
        if (a->d != (ulong *)0x0) {
          iVar1 = BN_get_flags(a,8);
          if (iVar1 == 0) {
            CRYPTO_clear_free(a->d,a->dmax << 2,"crypto/bn/bn_lib.c",0xce);
          }
          else {
            CRYPTO_secure_clear_free(a->d,a->dmax << 2,"crypto/bn/bn_lib.c",0xcc);
          }
        }
        a->d = __dest;
        a->dmax = words;
        return a;
      }
      ERR_put_error(3,0x78,0x41,"crypto/bn/bn_lib.c",0x11a);
    }
    else {
      ERR_put_error(3,0x78,0x69,"crypto/bn/bn_lib.c",0x112);
    }
  }
  else {
    ERR_put_error(3,0x78,0x72,"crypto/bn/bn_lib.c",0x10e);
  }
  return (BIGNUM *)0x0;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_TRUST_cleanup(void)

{
  int iVar1;
  _STACK **pp_Var2;
  
  iVar1 = DAT_000c536c;
  if (*(int *)(DAT_000c536c + 8) << 0x1f < 0) {
    if (*(int *)(DAT_000c536c + 8) << 0x1e < 0) {
      CRYPTO_free(*(void **)(DAT_000c536c + 0x10));
    }
    CRYPTO_free(DAT_000c5370);
  }
  if (*(int *)(iVar1 + 0x20) << 0x1f < 0) {
    if (*(int *)(iVar1 + 0x20) << 0x1e < 0) {
      CRYPTO_free(*(void **)(DAT_000c536c + 0x28));
    }
    CRYPTO_free(DAT_000c5374);
  }
  if (*(int *)(iVar1 + 0x38) << 0x1f < 0) {
    if (*(int *)(iVar1 + 0x38) << 0x1e < 0) {
      CRYPTO_free(*(void **)(DAT_000c536c + 0x40));
    }
    CRYPTO_free(DAT_000c5378);
  }
  if (*(int *)(iVar1 + 0x50) << 0x1f < 0) {
    if (*(int *)(iVar1 + 0x50) << 0x1e < 0) {
      CRYPTO_free(*(void **)(DAT_000c536c + 0x58));
    }
    CRYPTO_free(DAT_000c537c);
  }
  if (*(int *)(iVar1 + 0x68) << 0x1f < 0) {
    if (*(int *)(iVar1 + 0x68) << 0x1e < 0) {
      CRYPTO_free(*(void **)(DAT_000c536c + 0x70));
    }
    CRYPTO_free(DAT_000c5380);
  }
  if (*(int *)(iVar1 + 0x80) << 0x1f < 0) {
    if (*(int *)(iVar1 + 0x80) << 0x1e < 0) {
      CRYPTO_free(*(void **)(DAT_000c536c + 0x88));
    }
    CRYPTO_free(DAT_000c5384);
  }
  if (*(int *)(iVar1 + 0x98) << 0x1f < 0) {
    if (*(int *)(iVar1 + 0x98) << 0x1e < 0) {
      CRYPTO_free(*(void **)(DAT_000c536c + 0xa0));
    }
    CRYPTO_free(DAT_000c5388);
  }
  if (*(int *)(iVar1 + 0xb0) << 0x1f < 0) {
    if (*(int *)(iVar1 + 0xb0) << 0x1e < 0) {
      CRYPTO_free(*(void **)(DAT_000c536c + 0xb8));
    }
    CRYPTO_free(DAT_000c538c);
  }
  pp_Var2 = DAT_000c5390;
  sk_pop_free(*DAT_000c5390,DAT_000c5394);
  *pp_Var2 = (_STACK *)0x0;
  return;
}



ulong BN_get_word(BIGNUM *a)

{
  if (1 < a->top) {
    return 0xffffffff;
  }
  if (a->top != 1) {
    return 0;
  }
  return *a->d;
}


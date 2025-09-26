
ulong BN_mod_word(BIGNUM *a,ulong w)

{
  BIGNUM *a_00;
  ulong uVar1;
  
  if (w == 0) {
    return 0xffffffff;
  }
  a_00 = BN_dup(a);
  if (a_00 != (BIGNUM *)0x0) {
    uVar1 = BN_div_word(a_00,w);
    BN_free(a_00);
    return uVar1;
  }
  return 0xffffffff;
}


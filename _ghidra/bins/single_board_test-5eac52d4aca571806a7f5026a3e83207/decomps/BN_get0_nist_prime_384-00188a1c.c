
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIGNUM * BN_get0_nist_prime_384(void)

{
  return (BIGNUM *)_bignum_nist_p_384;
}


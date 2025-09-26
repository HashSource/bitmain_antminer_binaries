
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RAND_METHOD * RAND_SSLeay(void)

{
  return (RAND_METHOD *)&rand_ssleay_meth;
}


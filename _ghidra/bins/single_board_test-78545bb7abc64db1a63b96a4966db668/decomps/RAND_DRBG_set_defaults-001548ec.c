
undefined4 RAND_DRBG_set_defaults(int param_1,uint param_2)

{
  if (2 < param_1 - 0x388U) {
    ERR_put_error(0x24,0x79,0x78,"crypto/rand/drbg_lib.c",0x9f);
    return 0;
  }
  if ((param_2 & 0xfffffffe) == 0) {
    rand_drbg_type = param_1;
    rand_drbg_flags = param_2;
    return 1;
  }
  ERR_put_error(0x24,0x79,0x84,"crypto/rand/drbg_lib.c",0xa8);
  return 0;
}


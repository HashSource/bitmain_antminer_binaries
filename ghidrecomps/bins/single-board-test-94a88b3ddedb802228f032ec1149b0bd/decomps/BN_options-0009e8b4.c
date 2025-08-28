
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * BN_options(void)

{
  if (init_8408 == 0) {
    init_8408 = 1;
    BIO_snprintf(data_8409,0x10,"bn(%d,%d)",0x40,0x20);
  }
  return data_8409;
}


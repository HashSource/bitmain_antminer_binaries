
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * BN_options(void)

{
  if (init_9465 == 0) {
    init_9465 = 1;
    BIO_snprintf(data_9466,0x10,"bn(%zu,%zu)",0x20,0x20);
  }
  return data_9466;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * BN_options(void)

{
  int *buf;
  
  if (*DAT_0009e8d8 == 0) {
    buf = DAT_0009e8d8 + 1;
    *DAT_0009e8d8 = 1;
    BIO_snprintf((char *)buf,0x10,DAT_0009e8dc,0x40,0x20);
  }
  return DAT_0009e8e0;
}


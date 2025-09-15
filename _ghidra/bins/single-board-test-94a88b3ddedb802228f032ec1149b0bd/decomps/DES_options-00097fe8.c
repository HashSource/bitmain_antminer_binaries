
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * DES_options(void)

{
  if (init_8794 != 0) {
    BIO_snprintf(&buf_8795,0x20,"des(%s,%s,%s,%s)",&DAT_0015785c,&DAT_00157860,"16","long");
    init_8794 = 0;
  }
  return &buf_8795;
}


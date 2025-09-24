
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIO_METHOD * BIO_f_buffer(void)

{
  return (BIO_METHOD *)&methods_buffer;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIO_METHOD * BIO_s_null(void)

{
  return (BIO_METHOD *)&null_method;
}


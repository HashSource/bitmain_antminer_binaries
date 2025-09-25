
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIO_METHOD * BIO_f_base64(void)

{
  return (BIO_METHOD *)&methods_b64;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIO_METHOD * BIO_f_cipher(void)

{
  return (BIO_METHOD *)&methods_enc;
}


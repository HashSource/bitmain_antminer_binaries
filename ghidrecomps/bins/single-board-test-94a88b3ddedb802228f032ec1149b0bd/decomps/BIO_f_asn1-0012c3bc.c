
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIO_METHOD * BIO_f_asn1(void)

{
  return (BIO_METHOD *)&methods_asn1;
}


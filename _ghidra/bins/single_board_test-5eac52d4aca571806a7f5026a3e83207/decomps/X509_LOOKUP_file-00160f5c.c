
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_LOOKUP_METHOD * X509_LOOKUP_file(void)

{
  return (X509_LOOKUP_METHOD *)&x509_file_lookup;
}


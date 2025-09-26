
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_LOOKUP_METHOD * X509_LOOKUP_hash_dir(void)

{
  return (X509_LOOKUP_METHOD *)&x509_dir_lookup;
}


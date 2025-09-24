
X509_EXTENSION * OCSP_archive_cutoff_new(char *tim)

{
  ASN1_GENERALIZEDTIME *s;
  int iVar1;
  X509_EXTENSION *pXVar2;
  
  s = ASN1_GENERALIZEDTIME_new();
  if ((s != (ASN1_GENERALIZEDTIME *)0x0) &&
     (iVar1 = ASN1_GENERALIZEDTIME_set_string(s,tim), iVar1 != 0)) {
    pXVar2 = X509V3_EXT_i2d(0x172,0,s);
    ASN1_GENERALIZEDTIME_free(s);
    return pXVar2;
  }
  ASN1_GENERALIZEDTIME_free(s);
  return (X509_EXTENSION *)0x0;
}


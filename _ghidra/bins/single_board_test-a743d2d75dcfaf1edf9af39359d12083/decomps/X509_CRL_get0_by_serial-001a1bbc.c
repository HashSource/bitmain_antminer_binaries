
int X509_CRL_get0_by_serial(X509_CRL *crl,X509_REVOKED **ret,ASN1_INTEGER *serial)

{
  int iVar1;
  
  if (*(code **)(crl->meth + 0xc) != (code *)0x0) {
    iVar1 = (**(code **)(crl->meth + 0xc))();
    return iVar1;
  }
  return 0;
}


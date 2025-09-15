
int EVP_PKEY_asn1_get0_info
              (int *ppkey_id,int *pkey_base_id,int *ppkey_flags,char **pinfo,char **ppem_str,
              EVP_PKEY_ASN1_METHOD *ameth)

{
  int iVar1;
  
  if (ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
    iVar1 = 0;
  }
  else {
    if (ppkey_id != (int *)0x0) {
      *ppkey_id = *(int *)ameth;
    }
    if (pkey_base_id != (int *)0x0) {
      *pkey_base_id = *(int *)(ameth + 4);
    }
    if (ppkey_flags != (int *)0x0) {
      *ppkey_flags = *(int *)(ameth + 8);
    }
    if (pinfo != (char **)0x0) {
      *pinfo = *(char **)(ameth + 0x10);
    }
    if (ppem_str == (char **)0x0) {
      iVar1 = 1;
    }
    else {
      iVar1 = 1;
      *ppem_str = *(char **)(ameth + 0xc);
    }
  }
  return iVar1;
}


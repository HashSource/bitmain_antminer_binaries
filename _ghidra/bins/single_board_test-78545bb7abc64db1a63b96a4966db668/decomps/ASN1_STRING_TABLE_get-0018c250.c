
ASN1_STRING_TABLE * ASN1_STRING_TABLE_get(int nid)

{
  int iVar1;
  ASN1_STRING_TABLE *pAVar2;
  int local_24 [6];
  
  local_24[0] = nid;
  if ((stable != 0) && (iVar1 = OPENSSL_sk_find(stable,local_24), -1 < iVar1)) {
    pAVar2 = (ASN1_STRING_TABLE *)OPENSSL_sk_value(stable);
    return pAVar2;
  }
  pAVar2 = (ASN1_STRING_TABLE *)OBJ_bsearch_(local_24,&tbl_standard,0x1b,0x14,(cmp *)0x18c181);
  return pAVar2;
}


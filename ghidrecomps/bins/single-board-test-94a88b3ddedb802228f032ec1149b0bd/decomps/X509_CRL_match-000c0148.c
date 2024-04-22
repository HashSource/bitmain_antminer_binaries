
int X509_CRL_match(X509_CRL *a,X509_CRL *b)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_00194160)(a->sha1_hash,b->sha1_hash,0x14);
  return iVar1;
}


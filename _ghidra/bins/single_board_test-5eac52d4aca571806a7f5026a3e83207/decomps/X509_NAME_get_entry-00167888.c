
X509_NAME_ENTRY * X509_NAME_get_entry(X509_NAME *name,int loc)

{
  int iVar1;
  X509_NAME_ENTRY *pXVar2;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  if (name == (X509_NAME *)0x0) {
    return (X509_NAME_ENTRY *)0x0;
  }
  iVar1 = OPENSSL_sk_num(name->entries);
  if (iVar1 <= loc || loc < 0) {
    return (X509_NAME_ENTRY *)0x0;
  }
  pXVar2 = (X509_NAME_ENTRY *)OPENSSL_sk_value(name->entries,loc,extraout_r2,in_r3);
  return pXVar2;
}


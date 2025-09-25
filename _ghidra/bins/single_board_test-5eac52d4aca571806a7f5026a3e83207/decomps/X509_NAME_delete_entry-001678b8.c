
X509_NAME_ENTRY * X509_NAME_delete_entry(X509_NAME *name,int loc)

{
  int iVar1;
  X509_NAME_ENTRY *pXVar2;
  int iVar3;
  stack_st_X509_NAME_ENTRY *psVar4;
  int iVar5;
  
  if ((name != (X509_NAME *)0x0) && (iVar1 = OPENSSL_sk_num(name->entries), loc < iVar1 && -1 < loc)
     ) {
    psVar4 = name->entries;
    pXVar2 = (X509_NAME_ENTRY *)OPENSSL_sk_delete(psVar4,loc);
    iVar1 = OPENSSL_sk_num(psVar4);
    name->modified = 1;
    if (iVar1 != loc) {
      if (loc == 0) {
        iVar5 = pXVar2->set + -1;
      }
      else {
        iVar5 = OPENSSL_sk_value(psVar4,loc + -1);
        iVar5 = *(int *)(iVar5 + 8);
      }
      iVar3 = OPENSSL_sk_value(psVar4,loc);
      if ((iVar5 + 1 < *(int *)(iVar3 + 8)) && (loc < iVar1)) {
        do {
          iVar5 = OPENSSL_sk_value(psVar4,loc);
          loc = loc + 1;
          *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + -1;
        } while (iVar1 != loc);
      }
    }
    return pXVar2;
  }
  return (X509_NAME_ENTRY *)0x0;
}


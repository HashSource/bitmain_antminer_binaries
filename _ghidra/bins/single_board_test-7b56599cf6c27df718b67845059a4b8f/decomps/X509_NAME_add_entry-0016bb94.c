
int X509_NAME_add_entry(X509_NAME *name,X509_NAME_ENTRY *ne,int loc,int set)

{
  bool bVar1;
  int iVar2;
  X509_NAME_ENTRY *a;
  int iVar3;
  int iVar4;
  stack_st_X509_NAME_ENTRY *psVar5;
  
  if (name == (X509_NAME *)0x0) {
    return 0;
  }
  psVar5 = name->entries;
  bVar1 = set == 0;
  iVar2 = OPENSSL_sk_num(psVar5);
  name->modified = 1;
  if (iVar2 < loc || loc < 0) {
    loc = iVar2;
    if (set == -1) goto LAB_0016bc30;
LAB_0016bc00:
    iVar2 = loc;
    if (loc != 0) {
      iVar2 = OPENSSL_sk_value(psVar5,loc + -1);
      iVar2 = *(int *)(iVar2 + 8) + 1;
    }
  }
  else {
    if (set != -1) {
      if (loc < iVar2) {
        iVar2 = OPENSSL_sk_value(psVar5,loc);
        iVar2 = *(int *)(iVar2 + 8);
        a = X509_NAME_ENTRY_dup(ne);
        goto joined_r0x0016bc10;
      }
      goto LAB_0016bc00;
    }
LAB_0016bc30:
    if (loc == 0) {
      bVar1 = true;
      iVar2 = 0;
    }
    else {
      iVar2 = OPENSSL_sk_value(psVar5,loc + -1);
      iVar2 = *(int *)(iVar2 + 8);
    }
  }
  a = X509_NAME_ENTRY_dup(ne);
joined_r0x0016bc10:
  if (a == (X509_NAME_ENTRY *)0x0) {
    X509_NAME_ENTRY_free((X509_NAME_ENTRY *)0x0);
  }
  else {
    a->set = iVar2;
    iVar2 = OPENSSL_sk_insert(psVar5,a,loc);
    if (iVar2 != 0) {
      if (bVar1) {
        iVar4 = loc + 1;
        iVar2 = OPENSSL_sk_num(psVar5);
        if (iVar4 < iVar2) {
          do {
            iVar3 = OPENSSL_sk_value(psVar5,iVar4);
            iVar4 = iVar4 + 1;
            *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
          } while (iVar2 != iVar4);
        }
      }
      return 1;
    }
    ERR_put_error(0xb,0x71,0x41,"crypto/x509/x509name.c",0xe3);
    X509_NAME_ENTRY_free(a);
  }
  return 0;
}


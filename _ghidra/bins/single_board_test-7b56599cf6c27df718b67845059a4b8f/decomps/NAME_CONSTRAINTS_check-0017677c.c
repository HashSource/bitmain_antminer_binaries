
int NAME_CONSTRAINTS_check(X509 *x,NAME_CONSTRAINTS *nc)

{
  X509_NAME *name;
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  X509_NAME_ENTRY *ne;
  undefined4 uVar5;
  undefined4 local_28;
  X509_NAME *local_24;
  
  name = X509_get_subject_name(x);
  uVar1 = X509_NAME_entry_count(name);
  iVar2 = OPENSSL_sk_num(x[1].ex_xkusage);
  uVar1 = uVar1 & ~((int)uVar1 >> 0x1f);
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (0x7fffffff - iVar2 < (int)uVar1) {
    return 1;
  }
  uVar3 = OPENSSL_sk_num(nc->permittedSubtrees);
  iVar4 = OPENSSL_sk_num(nc->excludedSubtrees);
  uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  else if (0x7fffffff - iVar4 < (int)uVar3) {
    return 1;
  }
  if ((uVar1 + iVar2 != 0) && (iVar2 = __aeabi_idiv(0x100000), iVar2 < (int)(uVar3 + iVar4))) {
    return 1;
  }
  iVar2 = X509_NAME_entry_count(name);
  if (0 < iVar2) {
    local_28 = 4;
    local_24 = name;
    iVar2 = nc_match(&local_28,nc);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = -1;
    local_28 = 1;
    while (iVar2 = X509_NAME_get_index_by_NID(name,0x30,iVar2), iVar2 != -1) {
      ne = X509_NAME_get_entry(name,iVar2);
      local_24 = (X509_NAME *)X509_NAME_ENTRY_get_data(ne);
      if (local_24->modified != 0x16) {
        return 0x35;
      }
      iVar4 = nc_match(&local_28,nc);
      if (iVar4 != 0) {
        return iVar4;
      }
    }
  }
  iVar2 = 0;
  do {
    iVar4 = OPENSSL_sk_num(x[1].ex_xkusage);
    if (iVar4 <= iVar2) {
      return 0;
    }
    uVar5 = OPENSSL_sk_value(x[1].ex_xkusage,iVar2);
    iVar4 = nc_match(uVar5,nc);
    iVar2 = iVar2 + 1;
  } while (iVar4 == 0);
  return iVar4;
}


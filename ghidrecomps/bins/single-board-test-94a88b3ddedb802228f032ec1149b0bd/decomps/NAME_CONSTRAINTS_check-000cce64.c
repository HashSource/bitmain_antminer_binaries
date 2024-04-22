
int NAME_CONSTRAINTS_check(X509 *x,NAME_CONSTRAINTS *nc)

{
  X509_NAME *name;
  int iVar1;
  X509_NAME_ENTRY *ne;
  void *pvVar2;
  int iVar3;
  undefined4 local_20;
  X509_NAME *local_1c;
  
  name = X509_get_subject_name(x);
  iVar1 = X509_NAME_entry_count(name);
  if (iVar1 < 1) {
LAB_000ccec8:
    iVar3 = 0;
    do {
      iVar1 = sk_num(&x->altname->stack);
      if (iVar1 <= iVar3) {
        return 0;
      }
      pvVar2 = sk_value(&x->altname->stack,iVar3);
      iVar1 = nc_match(pvVar2,nc);
      iVar3 = iVar3 + 1;
    } while (iVar1 == 0);
  }
  else {
    local_20 = 4;
    local_1c = name;
    iVar1 = nc_match(&local_20,nc);
    if (iVar1 == 0) {
      iVar3 = -1;
      local_20 = 1;
      do {
        iVar3 = X509_NAME_get_index_by_NID(name,0x30,iVar3);
        if (iVar3 == -1) goto LAB_000ccec8;
        ne = X509_NAME_get_entry(name,iVar3);
        local_1c = (X509_NAME *)X509_NAME_ENTRY_get_data(ne);
        if (local_1c->modified != 0x16) {
          return 0x35;
        }
        iVar1 = nc_match(&local_20,nc);
      } while (iVar1 == 0);
    }
  }
  return iVar1;
}



int X509V3_NAME_from_section(X509_NAME *nm,stack_st_CONF_VALUE *dn_sk,ulong chtype)

{
  byte bVar1;
  int iVar2;
  byte *field;
  uint set;
  byte *pbVar3;
  int iVar4;
  
  if (nm == (X509_NAME *)0x0) {
    return 0;
  }
  iVar4 = 0;
  iVar2 = OPENSSL_sk_num(dn_sk);
  if (0 < iVar2) {
    do {
      iVar2 = OPENSSL_sk_value(dn_sk,iVar4);
      field = *(byte **)(iVar2 + 4);
      set = (uint)*field;
      if (set != 0) {
        pbVar3 = field;
        if (set != 0x3a && (set & 0xfd) != 0x2c) {
          do {
            pbVar3 = pbVar3 + 1;
            bVar1 = *pbVar3;
            if (bVar1 == 0) goto LAB_00176cf6;
          } while (bVar1 != 0x3a && (bVar1 & 0xfd) != 0x2c);
        }
        if (pbVar3[1] != 0) {
          field = pbVar3 + 1;
          set = (uint)pbVar3[1];
        }
LAB_00176cf6:
        if (set == 0x2b) {
          field = field + 1;
          set = 0xffffffff;
        }
        else {
          set = 0;
        }
      }
      iVar2 = X509_NAME_add_entry_by_txt(nm,(char *)field,chtype,*(uchar **)(iVar2 + 8),-1,-1,set);
      if (iVar2 == 0) {
        return 0;
      }
      iVar4 = iVar4 + 1;
      iVar2 = OPENSSL_sk_num(dn_sk);
    } while (iVar4 < iVar2);
  }
  return 1;
}


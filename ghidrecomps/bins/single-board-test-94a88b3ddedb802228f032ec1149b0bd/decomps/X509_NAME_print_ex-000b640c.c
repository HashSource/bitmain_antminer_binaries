
int X509_NAME_print_ex(BIO *out,X509_NAME *nm,int indent,ulong flags)

{
  int iVar1;
  int iVar2;
  X509_NAME_ENTRY *ne;
  ASN1_OBJECT *o;
  ASN1_STRING *pAVar3;
  size_t sVar4;
  int iVar5;
  char *__s;
  uint uVar6;
  void *data;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  size_t len;
  size_t sVar12;
  int iVar13;
  int local_b0;
  int local_ac;
  int local_94;
  int local_84;
  void *local_80;
  void *local_7c;
  char acStack_78 [84];
  
  if (flags == 0) {
    iVar1 = X509_NAME_print(out,nm,indent);
    return iVar1;
  }
  uVar8 = indent & ~(indent >> 0x1f);
  if ((uVar8 != 0) && (out != (BIO *)0x0)) {
    uVar9 = 0;
    do {
      iVar1 = BIO_write(out,DAT_000b6690,1);
      if (iVar1 != 1) {
        return -1;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 != uVar8);
  }
  uVar9 = flags & 0xf0000;
  if (uVar9 == 0x20000) {
    local_84 = 3;
    uVar9 = 0;
    local_94 = 2;
    local_7c = DAT_000b669c;
    local_80 = DAT_000b66a0;
  }
  else if (uVar9 < 0x20001) {
    if (uVar9 != 0x10000) {
      return -1;
    }
    local_84 = 1;
    local_7c = DAT_000b6694;
    local_80 = DAT_000b6698;
    local_94 = 1;
    uVar9 = 0;
  }
  else if (uVar9 == 0x30000) {
    local_84 = 3;
    uVar9 = 0;
    local_94 = 2;
    local_7c = DAT_000b66f0;
    local_80 = DAT_000b66f8;
  }
  else {
    if (uVar9 != 0x40000) {
      return -1;
    }
    local_7c = DAT_000b66f0;
    local_84 = 3;
    local_80 = DAT_000b66f4;
    local_94 = 1;
    uVar9 = uVar8;
  }
  if ((flags & 0x800000) == 0) {
    iVar1 = 1;
    data = DAT_000b66a4;
  }
  else {
    iVar1 = 3;
    data = DAT_000b66a8;
  }
  uVar6 = flags & 0x600000;
  iVar2 = X509_NAME_entry_count(nm);
  if (iVar2 < 1) {
    return uVar8;
  }
  iVar2 = iVar2 + -1;
  local_ac = -1;
  local_b0 = 0;
  if ((flags & 0x100000) == 0) goto LAB_000b661a;
  do {
    ne = X509_NAME_get_entry(nm,iVar2);
    iVar7 = ne->set;
    while( true ) {
      if (local_ac != -1) {
        if (local_ac == iVar7) {
          if (out != (BIO *)0x0) {
            iVar7 = BIO_write(out,local_7c,local_84);
            if (local_84 != iVar7) {
              return -1;
            }
            local_ac = ne->set;
          }
          uVar8 = uVar8 + local_84;
          iVar7 = local_ac;
        }
        else {
          if (out != (BIO *)0x0) {
            iVar7 = BIO_write(out,local_80,local_94);
            if (local_94 != iVar7) {
              return -1;
            }
            uVar10 = 0;
            if (uVar9 != 0) {
              do {
                iVar7 = BIO_write(out,DAT_000b6690,1);
                if (iVar7 != 1) {
                  return -1;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 != uVar9);
            }
            iVar7 = ne->set;
          }
          uVar8 = uVar8 + local_94 + uVar9;
        }
      }
      local_ac = iVar7;
      o = X509_NAME_ENTRY_get_object(ne);
      pAVar3 = X509_NAME_ENTRY_get_data(ne);
      iVar7 = OBJ_obj2nid(o);
      if (uVar6 != 0x600000) {
        if (uVar6 == 0x400000 || iVar7 == 0) {
          OBJ_obj2txt(acStack_78,0x50,o,1);
          len = strlen(acStack_78);
          __s = acStack_78;
          sVar12 = 0;
        }
        else {
          len = 0;
          if (uVar6 == 0) {
            __s = OBJ_nid2sn(iVar7);
            len = strlen(__s);
            sVar12 = 10;
          }
          else {
            __s = DAT_000b66ac;
            sVar12 = len;
            if (uVar6 == 0x200000) {
              __s = OBJ_nid2ln(iVar7);
              len = strlen(__s);
              sVar12 = 0x19;
            }
          }
        }
        if ((out != (BIO *)0x0) && (sVar4 = BIO_write(out,__s,len), len != sVar4)) {
          return -1;
        }
        if (((int)len < (int)sVar12) && ((flags & 0x2000000) != 0)) {
          iVar13 = sVar12 - len;
          if ((0 < iVar13) && (out != (BIO *)0x0)) {
            iVar11 = 0;
            do {
              iVar5 = BIO_write(out,DAT_000b6690,1);
              if (iVar5 != 1) {
                return -1;
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 != iVar13);
          }
          uVar8 = uVar8 + iVar13;
        }
        if ((out != (BIO *)0x0) && (iVar13 = BIO_write(out,data,iVar1), iVar1 != iVar13)) {
          return -1;
        }
        uVar8 = uVar8 + len + iVar1;
      }
      uVar10 = 0;
      if (iVar7 == 0) {
        if ((flags & 0x1000000) == 0) {
          uVar10 = 0;
        }
        else {
          uVar10 = 0x80;
        }
      }
      iVar7 = do_print_ex_constprop_2(out,uVar10 | flags,pAVar3);
      if (iVar7 < 0) {
        return -1;
      }
      iVar2 = iVar2 + -1;
      uVar8 = uVar8 + iVar7;
      local_b0 = local_b0 + 1;
      if (iVar2 == -1) {
        return uVar8;
      }
      if ((flags & 0x100000) != 0) break;
LAB_000b661a:
      ne = X509_NAME_get_entry(nm,local_b0);
      iVar7 = ne->set;
    }
  } while( true );
}


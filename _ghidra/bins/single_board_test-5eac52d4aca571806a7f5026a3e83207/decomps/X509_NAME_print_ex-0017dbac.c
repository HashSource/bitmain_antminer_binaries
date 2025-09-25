
int X509_NAME_print_ex(BIO *out,X509_NAME *nm,int indent,ulong flags)

{
  int iVar1;
  X509_NAME_ENTRY *ne;
  int iVar2;
  ASN1_OBJECT *o;
  ASN1_STRING *pAVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  char *buf;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_c4;
  size_t local_c0;
  int local_ac;
  int local_a0;
  undefined *local_9c;
  char *local_94;
  int local_90;
  undefined *local_80;
  char acStack_78 [84];
  
  if (flags == 0) {
    iVar10 = X509_NAME_print(out,nm,indent);
    return iVar10;
  }
  if (indent < 0) {
    indent = 0;
  }
  else if ((indent != 0) && (out != (BIO *)0x0)) {
    iVar10 = 0;
    do {
      iVar1 = BIO_write(out,&DAT_00236398,1);
      if (iVar1 != 1) {
        return -1;
      }
      iVar10 = iVar10 + 1;
    } while (indent != iVar10);
  }
  if ((flags & 0xf0000) == 0x20000) {
    local_80 = &DAT_0021ef7c;
    local_90 = 3;
    local_94 = ", ";
    local_a0 = 2;
    iVar10 = 0;
  }
  else {
    uVar7 = flags & 0xf0000;
    if (uVar7 < 0x20001) {
      if (uVar7 != 0x10000) {
        return -1;
      }
      local_90 = 1;
      iVar10 = 0;
      local_a0 = 1;
      local_80 = &DAT_0021ef80;
      local_94 = ",";
    }
    else if (uVar7 == 0x30000) {
      iVar10 = 0;
      local_90 = 3;
      local_a0 = 2;
      local_80 = &DAT_0021ef7c;
      local_94 = "; ";
    }
    else {
      if (uVar7 != 0x40000) {
        return -1;
      }
      local_90 = 3;
      local_a0 = 1;
      local_80 = &DAT_0021ef7c;
      local_94 = "\n";
      iVar10 = indent;
    }
  }
  if ((int)(flags << 8) < 0) {
    local_ac = 3;
    local_9c = &DAT_0021ef88;
  }
  else {
    local_9c = &DAT_0020a4b4;
    local_ac = 1;
  }
  uVar7 = flags & 0x600000;
  iVar1 = X509_NAME_entry_count(nm);
  if (0 < iVar1) {
    iVar1 = iVar1 + -1;
    iVar11 = -1;
    local_c4 = 0;
    do {
      if ((flags & 0x100000) == 0) {
        ne = X509_NAME_get_entry(nm,local_c4);
      }
      else {
        ne = X509_NAME_get_entry(nm,iVar1);
      }
      if (iVar11 != -1) {
        iVar2 = X509_NAME_ENTRY_set(ne);
        if (iVar2 == iVar11) {
          if ((out != (BIO *)0x0) && (iVar11 = BIO_write(out,local_80,local_90), local_90 != iVar11)
             ) {
            return -1;
          }
          indent = indent + local_90;
        }
        else {
          if (out != (BIO *)0x0) {
            iVar11 = BIO_write(out,local_94,local_a0);
            if (local_a0 != iVar11) {
              return -1;
            }
            iVar11 = 0;
            if (iVar10 != 0) {
              do {
                iVar2 = BIO_write(out,&DAT_00236398,1);
                if (iVar2 != 1) {
                  return -1;
                }
                iVar11 = iVar11 + 1;
              } while (iVar10 != iVar11);
            }
          }
          indent = indent + local_a0 + iVar10;
        }
      }
      iVar11 = X509_NAME_ENTRY_set(ne);
      o = X509_NAME_ENTRY_get_object(ne);
      pAVar3 = X509_NAME_ENTRY_get_data(ne);
      iVar2 = OBJ_obj2nid(o);
      if (uVar7 != 0x600000) {
        if (iVar2 == 0 || uVar7 == 0x400000) {
          buf = acStack_78;
          OBJ_obj2txt(buf,0x50,o,1);
          iVar4 = 0;
          local_c0 = strlen(buf);
LAB_0017de22:
          if (out == (BIO *)0x0) {
            if (((int)local_c0 < iVar4) && ((flags & 0x2000000) != 0)) goto LAB_0017de4a;
          }
          else {
            sVar5 = BIO_write(out,buf,local_c0);
            if (local_c0 != sVar5) {
              return -1;
            }
            if (((int)local_c0 < iVar4) && ((flags & 0x2000000) != 0)) {
LAB_0017de4a:
              iVar4 = iVar4 - local_c0;
              if ((0 < iVar4) && (out != (BIO *)0x0)) {
                iVar9 = 0;
                do {
                  iVar6 = BIO_write(out,&DAT_00236398,1);
                  if (iVar6 != 1) {
                    return -1;
                  }
                  iVar9 = iVar9 + 1;
                } while (iVar4 != iVar9);
              }
              indent = indent + iVar4;
              if (out == (BIO *)0x0) goto LAB_0017dd52;
            }
LAB_0017dd3e:
            iVar4 = BIO_write(out,local_9c,local_ac);
            if (local_ac != iVar4) {
              return -1;
            }
          }
        }
        else {
          if (uVar7 == 0) {
            buf = OBJ_nid2sn(iVar2);
            iVar4 = 10;
            local_c0 = strlen(buf);
            goto LAB_0017de22;
          }
          if (uVar7 == 0x200000) {
            buf = OBJ_nid2ln(iVar2);
            iVar4 = 0x19;
            local_c0 = strlen(buf);
            goto LAB_0017de22;
          }
          if (out != (BIO *)0x0) {
            local_c0 = BIO_write(out,"",0);
            if (local_c0 != 0) {
              return -1;
            }
            goto LAB_0017dd3e;
          }
          local_c0 = 0;
        }
LAB_0017dd52:
        indent = indent + local_c0 + local_ac;
      }
      if (iVar2 == 0) {
        if ((flags & 0x1000000) == 0) {
          uVar8 = 0;
        }
        else {
          uVar8 = 0x80;
        }
      }
      else {
        uVar8 = 0;
      }
      iVar2 = do_print_ex_constprop_2(out,uVar8 | flags,pAVar3);
      if (iVar2 < 0) {
        return -1;
      }
      iVar1 = iVar1 + -1;
      indent = indent + iVar2;
      local_c4 = local_c4 + 1;
    } while (iVar1 != -1);
  }
  return indent;
}


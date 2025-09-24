
int X509_NAME_print_ex_fp(FILE *fp,X509_NAME *nm,int indent,ulong flags)

{
  BIO *bp;
  int iVar1;
  int iVar2;
  X509_NAME_ENTRY *ne;
  int iVar3;
  size_t sVar4;
  ASN1_OBJECT *o;
  ASN1_STRING *pAVar5;
  char *buf;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int local_d0;
  int local_cc;
  size_t local_b8;
  int local_b0;
  size_t local_a8;
  undefined *local_a4;
  char *local_9c;
  size_t local_98;
  int local_94;
  int local_8c;
  size_t local_80;
  undefined *local_7c;
  char acStack_78 [84];
  
  if (flags == 0) {
    bp = BIO_new_fp(fp,0);
    if (bp != (BIO *)0x0) {
      iVar1 = X509_NAME_print(bp,nm,indent);
      BIO_free(bp);
      return iVar1;
    }
LAB_001822b8:
    indent = -1;
  }
  else {
    if (indent < 0) {
      indent = 0;
    }
    else if ((indent != 0) && (fp != (FILE *)0x0)) {
      iVar1 = 0;
      do {
        sVar4 = fwrite(&DAT_0023bac8,1,1,fp);
        if (sVar4 != 1) goto LAB_001822b8;
        iVar1 = iVar1 + 1;
      } while (indent != iVar1);
    }
    uVar7 = flags & 0xf0000;
    if (uVar7 == 0x20000) {
      iVar1 = 0;
      local_7c = &DAT_002246a4;
      local_9c = ", ";
      local_98 = 2;
      local_80 = 3;
      local_94 = 2;
      local_8c = 3;
    }
    else if (uVar7 < 0x20001) {
      if (uVar7 != 0x10000) goto LAB_001822b8;
      local_98 = 1;
      iVar1 = 0;
      local_80 = 1;
      local_8c = 1;
      local_94 = 1;
      local_7c = &DAT_002246a8;
      local_9c = ",";
    }
    else if (uVar7 == 0x30000) {
      local_98 = 2;
      iVar1 = 0;
      local_94 = 2;
      local_80 = 3;
      local_8c = 3;
      local_7c = &DAT_002246a4;
      local_9c = "; ";
    }
    else {
      if (uVar7 != 0x40000) goto LAB_001822b8;
      local_98 = 1;
      local_94 = 1;
      local_80 = 3;
      local_8c = 3;
      local_7c = &DAT_002246a4;
      local_9c = "\n";
      iVar1 = indent;
    }
    if ((int)(flags << 8) < 0) {
      local_a8 = 3;
      local_b0 = 3;
      local_a4 = &DAT_002246b0;
    }
    else {
      local_a4 = &DAT_0020fbdc;
      local_a8 = 1;
      local_b0 = 1;
    }
    uVar7 = flags & 0x600000;
    iVar2 = X509_NAME_entry_count(nm);
    if (0 < iVar2) {
      iVar2 = iVar2 + -1;
      local_d0 = 0;
      local_cc = -1;
      do {
        if ((flags & 0x100000) == 0) {
          ne = X509_NAME_get_entry(nm,local_d0);
        }
        else {
          ne = X509_NAME_get_entry(nm,iVar2);
        }
        if (local_cc != -1) {
          iVar3 = X509_NAME_ENTRY_set(ne);
          if (iVar3 == local_cc) {
            if ((fp != (FILE *)0x0) && (sVar4 = fwrite(local_7c,1,local_80,fp), local_80 != sVar4))
            goto LAB_001822b8;
            indent = indent + local_8c;
          }
          else {
            if (fp != (FILE *)0x0) {
              sVar4 = fwrite(local_9c,1,local_98,fp);
              if (sVar4 != local_98) goto LAB_001822b8;
              iVar3 = 0;
              if (iVar1 != 0) {
                do {
                  sVar4 = fwrite(&DAT_0023bac8,1,1,fp);
                  if (sVar4 != 1) goto LAB_001822b8;
                  iVar3 = iVar3 + 1;
                } while (iVar1 != iVar3);
              }
            }
            indent = indent + local_94 + iVar1;
          }
        }
        local_cc = X509_NAME_ENTRY_set(ne);
        o = X509_NAME_ENTRY_get_object(ne);
        pAVar5 = X509_NAME_ENTRY_get_data(ne);
        iVar3 = OBJ_obj2nid(o);
        if (uVar7 != 0x600000) {
          if (iVar3 == 0 || uVar7 == 0x400000) {
            buf = acStack_78;
            OBJ_obj2txt(buf,0x50,o,1);
            iVar8 = 0;
            local_b8 = strlen(buf);
joined_r0x0018247a:
            if (fp == (FILE *)0x0) {
              if (((int)local_b8 < iVar8) && ((flags & 0x2000000) != 0)) {
LAB_0018242c:
                iVar8 = iVar8 - local_b8;
                if ((0 < iVar8) && (fp != (FILE *)0x0)) {
                  iVar9 = 0;
                  do {
                    sVar4 = fwrite(&DAT_0023bac8,1,1,fp);
                    if (sVar4 != 1) goto LAB_001822b8;
                    iVar9 = iVar9 + 1;
                  } while (iVar9 != iVar8);
                }
                indent = indent + iVar8;
                if (fp != (FILE *)0x0) goto LAB_00182380;
              }
            }
            else {
              sVar4 = fwrite(buf,1,local_b8,fp);
              if (sVar4 != local_b8) goto LAB_001822b8;
              if (((int)local_b8 < iVar8) && ((flags & 0x2000000) != 0)) goto LAB_0018242c;
LAB_00182380:
              sVar4 = fwrite(local_a4,1,local_a8,fp);
              if (local_a8 != sVar4) goto LAB_001822b8;
            }
          }
          else {
            if (uVar7 == 0) {
              buf = OBJ_nid2sn(iVar3);
              iVar8 = 10;
              local_b8 = strlen(buf);
              goto joined_r0x0018247a;
            }
            if (uVar7 == 0x200000) {
              buf = OBJ_nid2ln(iVar3);
              iVar8 = 0x19;
              local_b8 = strlen(buf);
              goto joined_r0x0018247a;
            }
            if (fp != (FILE *)0x0) {
              sVar4 = fwrite("",1,0,fp);
              if (sVar4 == 0) {
                local_b8 = 0;
                goto LAB_00182380;
              }
              goto LAB_001822b8;
            }
            local_b8 = 0;
          }
          indent = indent + local_b8 + local_b0;
        }
        if (iVar3 == 0) {
          if ((flags & 0x1000000) == 0) {
            uVar6 = 0;
          }
          else {
            uVar6 = 0x80;
          }
        }
        else {
          uVar6 = 0;
        }
        iVar3 = do_print_ex_constprop_3(fp,uVar6 | flags,pAVar5);
        if (iVar3 < 0) goto LAB_001822b8;
        iVar2 = iVar2 + -1;
        indent = indent + iVar3;
        local_d0 = local_d0 + 1;
      } while (iVar2 != -1);
    }
  }
  return indent;
}


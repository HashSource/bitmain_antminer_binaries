
int X509_NAME_print_ex_fp(FILE *fp,X509_NAME *nm,int indent,ulong flags)

{
  BIO *bp;
  int iVar1;
  size_t sVar2;
  X509_NAME_ENTRY *ne;
  size_t sVar3;
  ASN1_OBJECT *o;
  ASN1_STRING *pAVar4;
  size_t sVar5;
  size_t sVar6;
  char *__s;
  uint uVar7;
  void *__ptr;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int local_b8;
  int local_b4;
  size_t local_9c;
  void *local_8c;
  size_t local_88;
  void *local_84;
  int local_80;
  int local_7c;
  char acStack_78 [84];
  
  if (flags == 0) {
    bp = BIO_new_fp(fp,0);
    if (bp != (BIO *)0x0) {
      iVar1 = X509_NAME_print(bp,nm,indent);
      BIO_free(bp);
      return iVar1;
    }
LAB_000b6760:
    uVar9 = 0xffffffff;
  }
  else {
    uVar9 = indent & ~(indent >> 0x1f);
    if ((uVar9 != 0) && (fp != (FILE *)0x0)) {
      uVar10 = 0;
      do {
        sVar2 = fwrite(DAT_000b69ac,1,1,fp);
        if (sVar2 != 1) goto LAB_000b6760;
        uVar10 = uVar10 + 1;
      } while (uVar10 != uVar9);
    }
    uVar10 = flags & 0xf0000;
    if (uVar10 == 0x20000) {
      local_9c = 2;
      uVar10 = 0;
      local_7c = 2;
      local_88 = 3;
      local_80 = 3;
      local_84 = DAT_000b69b0;
      local_8c = DAT_000b69b4;
    }
    else if (uVar10 < 0x20001) {
      if (uVar10 != 0x10000) goto LAB_000b6760;
      local_84 = DAT_000b6a30;
      local_8c = DAT_000b6a34;
      local_9c = 1;
      local_88 = 1;
      local_80 = 1;
      local_7c = 1;
      uVar10 = 0;
    }
    else if (uVar10 == 0x30000) {
      local_9c = 2;
      local_7c = 2;
      uVar10 = 0;
      local_88 = 3;
      local_80 = 3;
      local_84 = DAT_000b6a24;
      local_8c = DAT_000b6a2c;
    }
    else {
      if (uVar10 != 0x40000) goto LAB_000b6760;
      local_9c = 1;
      local_7c = 1;
      local_88 = 3;
      local_80 = 3;
      local_84 = DAT_000b6a24;
      local_8c = DAT_000b6a28;
      uVar10 = uVar9;
    }
    if ((flags & 0x800000) == 0) {
      sVar2 = 1;
      __ptr = DAT_000b69b8;
    }
    else {
      sVar2 = 3;
      __ptr = DAT_000b69bc;
    }
    uVar7 = flags & 0x600000;
    iVar1 = X509_NAME_entry_count(nm);
    if (0 < iVar1) {
      iVar1 = iVar1 + -1;
      local_b4 = -1;
      local_b8 = 0;
      if ((flags & 0x100000) == 0) goto LAB_000b6924;
      do {
        ne = X509_NAME_get_entry(nm,iVar1);
        iVar8 = ne->set;
        while( true ) {
          if (local_b4 != -1) {
            if (local_b4 == iVar8) {
              if (fp != (FILE *)0x0) {
                sVar3 = fwrite(local_84,1,local_88,fp);
                if (sVar3 != local_88) goto LAB_000b6760;
                local_b4 = ne->set;
              }
              uVar9 = uVar9 + local_80;
              iVar8 = local_b4;
            }
            else {
              if (fp != (FILE *)0x0) {
                sVar3 = fwrite(local_8c,1,local_9c,fp);
                if (sVar3 != local_9c) goto LAB_000b6760;
                uVar11 = 0;
                if (uVar10 != 0) {
                  do {
                    sVar3 = fwrite(DAT_000b69ac,1,1,fp);
                    if (sVar3 != 1) goto LAB_000b6760;
                    uVar11 = uVar11 + 1;
                  } while (uVar11 != uVar10);
                }
                iVar8 = ne->set;
              }
              uVar9 = uVar9 + local_7c + uVar10;
            }
          }
          local_b4 = iVar8;
          o = X509_NAME_ENTRY_get_object(ne);
          pAVar4 = X509_NAME_ENTRY_get_data(ne);
          iVar8 = OBJ_obj2nid(o);
          if (uVar7 != 0x600000) {
            if (uVar7 == 0x400000 || iVar8 == 0) {
              OBJ_obj2txt(acStack_78,0x50,o,1);
              sVar3 = strlen(acStack_78);
              sVar6 = 0;
              __s = acStack_78;
            }
            else {
              sVar3 = 0;
              if (uVar7 == 0) {
                __s = OBJ_nid2sn(iVar8);
                sVar3 = strlen(__s);
                sVar6 = 10;
              }
              else {
                sVar6 = sVar3;
                __s = DAT_000b69c0;
                if (uVar7 == 0x200000) {
                  __s = OBJ_nid2ln(iVar8);
                  sVar3 = strlen(__s);
                  sVar6 = 0x19;
                }
              }
            }
            if ((fp != (FILE *)0x0) && (sVar5 = fwrite(__s,1,sVar3,fp), sVar5 != sVar3))
            goto LAB_000b6760;
            if (((int)sVar3 < (int)sVar6) && ((flags & 0x2000000) != 0)) {
              iVar13 = sVar6 - sVar3;
              if ((0 < iVar13) && (fp != (FILE *)0x0)) {
                iVar12 = 0;
                do {
                  sVar6 = fwrite(DAT_000b69ac,1,1,fp);
                  if (sVar6 != 1) goto LAB_000b6760;
                  iVar12 = iVar12 + 1;
                } while (iVar12 != iVar13);
              }
              uVar9 = uVar9 + iVar13;
            }
            if ((fp != (FILE *)0x0) && (sVar6 = fwrite(__ptr,1,sVar2,fp), sVar2 != sVar6))
            goto LAB_000b6760;
            uVar9 = uVar9 + sVar3 + sVar2;
          }
          uVar11 = 0;
          if (iVar8 == 0) {
            if ((flags & 0x1000000) == 0) {
              uVar11 = 0;
            }
            else {
              uVar11 = 0x80;
            }
          }
          iVar8 = do_print_ex_constprop_3(fp,uVar11 | flags,pAVar4);
          if (iVar8 < 0) goto LAB_000b6760;
          iVar1 = iVar1 + -1;
          uVar9 = uVar9 + iVar8;
          local_b8 = local_b8 + 1;
          if (iVar1 == -1) {
            return uVar9;
          }
          if ((flags & 0x100000) != 0) break;
LAB_000b6924:
          ne = X509_NAME_get_entry(nm,local_b8);
          iVar8 = ne->set;
        }
      } while( true );
    }
  }
  return uVar9;
}


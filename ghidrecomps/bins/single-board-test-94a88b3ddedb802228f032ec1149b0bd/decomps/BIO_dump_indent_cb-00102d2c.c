
int BIO_dump_indent_cb(cb *cb,void *u,char *s,int len,int indent)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 uVar11;
  int local_204;
  int local_1fc;
  uint local_1ec;
  char acStack_1e4 [20];
  char local_1d0 [132];
  char local_14c [296];
  byte *pbVar10;
  
  iVar4 = len;
  if (len < 1) {
    local_1ec = 0;
  }
  else {
    local_1ec = (byte)s[len + -1] & 0xdf;
    if ((s[len + -1] & 0xdfU) == 0) {
      do {
        iVar4 = len + -1;
        local_1ec = local_1ec + 1;
        if (iVar4 == 0) break;
        iVar5 = len + -2;
        len = iVar4;
      } while ((s[iVar5] & 0xdfU) == 0);
    }
    else {
      local_1ec = 0;
    }
  }
  if (indent < 0) {
    iVar5 = 0x10;
    indent = 0;
  }
  else if (indent == 0) {
    iVar5 = 0x10;
  }
  else {
    if (0x7f < indent) {
      indent = 0x80;
    }
    memset(local_1d0,0x20,indent);
    sVar1 = indent;
    if (5 < indent) {
      sVar1 = 6;
    }
    iVar2 = (indent - sVar1) + 3;
    iVar5 = (indent - sVar1) + 6;
    if (-1 < iVar2) {
      iVar5 = iVar2;
    }
    iVar5 = 0x10 - (iVar5 >> 2);
  }
  local_1d0[indent] = '\0';
  local_1fc = __aeabi_idiv(iVar4,iVar5);
  if (iVar5 * local_1fc < iVar4) {
    local_1fc = local_1fc + 1;
  }
  if (local_1fc < 1) {
    local_204 = 0;
  }
  else {
    iVar2 = 0;
    iVar8 = 0;
    local_204 = 0;
    pbVar7 = (byte *)s;
    do {
      iVar6 = 0;
      local_14c[0] = '\0';
      BUF_strlcpy(local_14c,local_1d0,0x121);
      BIO_snprintf(acStack_1e4,0x14,DAT_00102f30,iVar2);
      BUF_strlcat(local_14c,acStack_1e4,0x121);
      if (iVar5 < 1) {
        BUF_strlcat(local_14c,DAT_00102f3c,0x121);
      }
      else {
        do {
          while (iVar2 + iVar6 < iVar4) {
            if (iVar6 == 7) {
              uVar11 = 0x2d;
            }
            else {
              uVar11 = 0x20;
            }
            pbVar10 = pbVar7 + iVar6;
            iVar6 = iVar6 + 1;
            BIO_snprintf(acStack_1e4,0x14,DAT_00102f34,(uint)*pbVar10,uVar11);
            BUF_strlcat(local_14c,acStack_1e4,0x121);
            if (iVar6 == iVar5) goto LAB_00102e4c;
          }
          iVar6 = iVar6 + 1;
          BUF_strlcat(local_14c,DAT_00102f38,0x121);
        } while (iVar6 != iVar5);
LAB_00102e4c:
        BUF_strlcat(local_14c,DAT_00102f3c,0x121);
        if (iVar2 < iVar4) {
          pbVar10 = pbVar7;
          do {
            pbVar9 = pbVar10 + 1;
            uVar3 = (uint)*pbVar10;
            if (0x5e < uVar3 - 0x20) {
              uVar3 = 0x2e;
            }
            BIO_snprintf(acStack_1e4,0x14,DAT_00102f40,uVar3);
            BUF_strlcat(local_14c,acStack_1e4,0x121);
          } while ((pbVar9 != (byte *)(s + iVar2 + iVar5)) &&
                  (pbVar10 = pbVar9, pbVar9 != (byte *)(s + iVar4)));
        }
      }
      iVar8 = iVar8 + 1;
      BUF_strlcat(local_14c,DAT_00102f44,0x121);
      iVar2 = iVar2 + iVar5;
      sVar1 = strlen(local_14c);
      iVar6 = (*cb)(local_14c,sVar1,u);
      pbVar7 = pbVar7 + iVar5;
      local_204 = local_204 + iVar6;
    } while (iVar8 != local_1fc);
  }
  if (local_1ec != 0) {
    BIO_snprintf(local_14c,0x121,DAT_00102f48,local_1d0,iVar4 + local_1ec);
    sVar1 = strlen(local_14c);
    iVar4 = (*cb)(local_14c,sVar1,u);
    local_204 = local_204 + iVar4;
  }
  return local_204;
}


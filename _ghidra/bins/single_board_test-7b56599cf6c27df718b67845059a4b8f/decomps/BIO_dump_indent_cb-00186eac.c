
int BIO_dump_indent_cb(cb *cb,void *u,char *s,int len,int indent)

{
  byte *pbVar1;
  uint uVar2;
  size_t sVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  size_t sVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int local_178;
  int local_170;
  int local_164;
  byte abStack_14c [296];
  
  if (indent < 0) {
    iVar6 = 0x10;
    indent = 0;
  }
  else {
    if (0x40 < indent) {
      iVar6 = 1;
      indent = 0x40;
      local_164 = len;
      if (len < 1) {
        return 0;
      }
      goto LAB_00186efe;
    }
    if (indent < 7) {
      iVar6 = 0;
    }
    else {
      iVar6 = indent + -6;
    }
    iVar11 = iVar6 + 6;
    if (-1 < iVar6 + 3) {
      iVar11 = iVar6 + 3;
    }
    iVar6 = 0x10 - (iVar11 >> 2);
  }
  local_164 = __aeabi_idiv(len,iVar6);
  if (iVar6 * local_164 < len) {
    local_164 = local_164 + 1;
  }
  if (local_164 < 1) {
    return 0;
  }
LAB_00186efe:
  iVar10 = 0;
  local_170 = 0;
  local_178 = 0;
  iVar11 = len;
  do {
    iVar4 = iVar10;
    sVar3 = BIO_snprintf((char *)abStack_14c,0x121,"%*s%04x - ",indent,"",iVar10);
    if (iVar6 == 0) {
      uVar7 = 0x121 - sVar3;
      sVar8 = sVar3;
      if (2 < uVar7) {
        pbVar1 = abStack_14c + sVar3;
        pbVar1[0] = 0x20;
        pbVar1[1] = 0x20;
        sVar8 = sVar3 + 2;
        abStack_14c[sVar3 + 2] = 0;
        uVar7 = 0x121 - sVar8;
      }
    }
    else {
      iVar9 = 0;
      uVar7 = 0x121 - sVar3;
      do {
        if (3 < uVar7) {
          if (iVar10 + iVar9 < len) {
            if (iVar9 == 7) {
              uVar12 = 0x2d;
            }
            else {
              uVar12 = 0x20;
            }
            BIO_snprintf((char *)(abStack_14c + sVar3),4,"%02x%c",(uint)(byte)s[iVar9],uVar12,iVar4)
            ;
          }
          else {
            *(char **)(abStack_14c + sVar3) = "_SHA256";
          }
          sVar3 = sVar3 + 3;
          uVar7 = 0x121 - sVar3;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 != iVar6);
      sVar8 = sVar3;
      if (2 < uVar7) {
        pbVar1 = abStack_14c + sVar3;
        pbVar1[0] = 0x20;
        pbVar1[1] = 0x20;
        sVar8 = sVar3 + 2;
        abStack_14c[sVar3 + 2] = 0;
        uVar7 = 0x121 - sVar8;
      }
      if (iVar10 < len) {
        iVar4 = 0;
        uVar2 = uVar7;
        do {
          uVar7 = uVar2;
          sVar3 = sVar8 + 1;
          if (1 < uVar7) {
            bVar5 = s[iVar4];
            uVar7 = 0x121 - sVar3;
            if (0x5e < bVar5 - 0x20) {
              bVar5 = 0x2e;
            }
            abStack_14c[sVar8] = bVar5;
            abStack_14c[sVar3] = 0;
            sVar8 = sVar3;
          }
          iVar4 = iVar4 + 1;
        } while ((iVar4 < iVar6) && (uVar2 = 0x121 - sVar8, iVar4 != iVar11));
      }
    }
    sVar3 = sVar8;
    if (1 < uVar7) {
      sVar3 = sVar8 + 1;
      abStack_14c[sVar8] = 10;
      abStack_14c[sVar3] = 0;
    }
    iVar10 = iVar10 + iVar6;
    s = s + iVar6;
    iVar11 = iVar11 - iVar6;
    local_170 = local_170 + 1;
    iVar4 = (*cb)(abStack_14c,sVar3,u);
    local_178 = local_178 + iVar4;
  } while (local_164 != local_170);
  return local_178;
}


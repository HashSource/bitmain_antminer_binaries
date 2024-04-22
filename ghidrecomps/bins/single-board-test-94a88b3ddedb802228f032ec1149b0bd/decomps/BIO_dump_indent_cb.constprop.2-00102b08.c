
int BIO_dump_indent_cb_constprop_2(FILE *param_1,byte *param_2,int param_3,size_t param_4)

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
  int local_200;
  int local_1f8;
  uint local_1ec;
  char acStack_1e4 [20];
  char local_1d0 [132];
  char local_14c [296];
  byte *pbVar10;
  
  iVar4 = param_3;
  if (param_3 < 1) {
    local_1ec = 0;
  }
  else {
    local_1ec = param_2[param_3 + -1] & 0xdf;
    if ((param_2[param_3 + -1] & 0xdf) == 0) {
      do {
        iVar4 = param_3 + -1;
        local_1ec = local_1ec + 1;
        if (iVar4 == 0) break;
        iVar5 = param_3 + -2;
        param_3 = iVar4;
      } while ((param_2[iVar5] & 0xdf) == 0);
    }
    else {
      local_1ec = 0;
    }
  }
  if ((int)param_4 < 0) {
    iVar5 = 0x10;
    param_4 = 0;
  }
  else if (param_4 == 0) {
    iVar5 = 0x10;
  }
  else {
    if (0x7f < (int)param_4) {
      param_4 = 0x80;
    }
    memset(local_1d0,0x20,param_4);
    sVar1 = param_4;
    if (5 < (int)param_4) {
      sVar1 = 6;
    }
    iVar2 = (param_4 - sVar1) + 3;
    iVar5 = (param_4 - sVar1) + 6;
    if (-1 < iVar2) {
      iVar5 = iVar2;
    }
    iVar5 = 0x10 - (iVar5 >> 2);
  }
  local_1d0[param_4] = '\0';
  local_1f8 = __aeabi_idiv(iVar4,iVar5);
  if (iVar5 * local_1f8 < iVar4) {
    local_1f8 = local_1f8 + 1;
  }
  if (local_1f8 < 1) {
    local_200 = 0;
  }
  else {
    iVar2 = 0;
    iVar8 = 0;
    local_200 = 0;
    pbVar7 = param_2;
    do {
      iVar6 = 0;
      local_14c[0] = '\0';
      BUF_strlcpy(local_14c,local_1d0,0x121);
      BIO_snprintf(acStack_1e4,0x14,DAT_00102d0c,iVar2);
      BUF_strlcat(local_14c,acStack_1e4,0x121);
      if (iVar5 < 1) {
        BUF_strlcat(local_14c,DAT_00102d18,0x121);
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
            BIO_snprintf(acStack_1e4,0x14,DAT_00102d10,(uint)*pbVar10,uVar11);
            BUF_strlcat(local_14c,acStack_1e4,0x121);
            if (iVar6 == iVar5) goto LAB_00102c24;
          }
          iVar6 = iVar6 + 1;
          BUF_strlcat(local_14c,DAT_00102d14,0x121);
        } while (iVar6 != iVar5);
LAB_00102c24:
        BUF_strlcat(local_14c,DAT_00102d18,0x121);
        if (iVar2 < iVar4) {
          pbVar10 = pbVar7;
          do {
            pbVar9 = pbVar10 + 1;
            uVar3 = (uint)*pbVar10;
            if (0x5e < uVar3 - 0x20) {
              uVar3 = 0x2e;
            }
            BIO_snprintf(acStack_1e4,0x14,DAT_00102d1c,uVar3);
            BUF_strlcat(local_14c,acStack_1e4,0x121);
          } while ((pbVar9 != param_2 + iVar2 + iVar5) &&
                  (pbVar10 = pbVar9, pbVar9 != param_2 + iVar4));
        }
      }
      iVar8 = iVar8 + 1;
      BUF_strlcat(local_14c,DAT_00102d20,0x121);
      iVar2 = iVar2 + iVar5;
      sVar1 = strlen(local_14c);
      sVar1 = fwrite(local_14c,sVar1,1,param_1);
      pbVar7 = pbVar7 + iVar5;
      local_200 = local_200 + sVar1;
    } while (iVar8 != local_1f8);
  }
  if (local_1ec != 0) {
    BIO_snprintf(local_14c,0x121,DAT_00102d24,local_1d0,local_1ec + iVar4);
    sVar1 = strlen(local_14c);
    sVar1 = fwrite(local_14c,sVar1,1,param_1);
    local_200 = local_200 + sVar1;
  }
  return local_200;
}


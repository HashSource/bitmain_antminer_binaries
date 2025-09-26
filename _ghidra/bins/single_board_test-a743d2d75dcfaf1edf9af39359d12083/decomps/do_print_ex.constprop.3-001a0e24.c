
int do_print_ex_constprop_3(FILE *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  size_t sVar2;
  char *__s;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char local_28 [8];
  
  uVar6 = param_2 & 0x40;
  iVar4 = param_3[1];
  local_28[0] = '\0';
  if (uVar6 != 0) {
    __s = ASN1_tag2str(iVar4);
    sVar2 = strlen(__s);
    if (param_1 != (FILE *)0x0) {
      sVar3 = fwrite(__s,1,sVar2,param_1);
      if (sVar2 != sVar3) {
        return -1;
      }
      sVar3 = fwrite(":",1,1,param_1);
      if (sVar3 != 1) {
        return -1;
      }
    }
    uVar6 = sVar2 + 1;
  }
  if ((int)(param_2 << 0x18) < 0) {
LAB_001a0e48:
    iVar4 = do_dump(param_2,0x1a075d,param_1,param_3);
    if (iVar4 < 0) {
      return -1;
    }
    return iVar4 + uVar6;
  }
  if ((int)(param_2 << 0x1a) < 0) {
LAB_001a0e62:
    if ((int)(param_2 << 0x1b) < 0) {
      uVar5 = 1;
LAB_001a0f0c:
      uVar5 = uVar5 | 8;
      goto LAB_001a0e68;
    }
  }
  else {
    if ((0x1d < iVar4 - 1U) || (uVar5 = (uint)(char)tag2nbyte[iVar4], uVar5 == 0xffffffff)) {
      if ((int)(param_2 << 0x17) < 0) goto LAB_001a0e48;
      goto LAB_001a0e62;
    }
    if (-1 < (int)(param_2 << 0x1b)) goto LAB_001a0e68;
    if (uVar5 != 0) goto LAB_001a0f0c;
  }
  uVar5 = 1;
LAB_001a0e68:
  iVar4 = do_buf_constprop_4(param_3[2],*param_3,uVar5,param_2 & 0xf,local_28,0);
  if (-1 < iVar4) {
    iVar4 = uVar6 + iVar4;
    if (local_28[0] == '\0') {
      if (param_1 == (FILE *)0x0) {
        return iVar4;
      }
    }
    else {
      iVar4 = iVar4 + 2;
      if (param_1 == (FILE *)0x0) {
        return iVar4;
      }
      sVar2 = fwrite(&DAT_0022f7b4,1,1,param_1);
      if (sVar2 != 1) {
        return -1;
      }
    }
    iVar1 = do_buf_constprop_4(param_3[2],*param_3,uVar5,param_2 & 0xf,0,param_1);
    if (-1 < iVar1) {
      if (local_28[0] == '\0') {
        return iVar4;
      }
      sVar2 = fwrite(&DAT_0022f7b4,1,1,param_1);
      if (sVar2 != 1) {
        return -1;
      }
      return iVar4;
    }
  }
  return -1;
}


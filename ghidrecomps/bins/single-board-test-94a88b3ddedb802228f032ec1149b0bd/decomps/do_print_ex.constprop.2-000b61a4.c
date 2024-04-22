
int do_print_ex_constprop_2(BIO *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  char *__s;
  size_t len;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char local_28 [8];
  
  uVar5 = param_2 & 0x40;
  iVar3 = param_3[1];
  local_28[0] = '\0';
  if (uVar5 != 0) {
    __s = ASN1_tag2str(iVar3);
    len = strlen(__s);
    if (param_1 != (BIO *)0x0) {
      sVar2 = BIO_write(param_1,__s,len);
      if (len != sVar2) {
        return -1;
      }
      iVar1 = BIO_write(param_1,DAT_000b62d0,1);
      if (iVar1 != 1) {
        return -1;
      }
    }
    uVar5 = len + 1;
  }
  if ((int)(param_2 << 0x18) < 0) {
LAB_000b61c8:
    iVar3 = do_dump(param_2,DAT_000b62c4,param_1,param_3);
    if (iVar3 < 0) {
      return -1;
    }
    return iVar3 + uVar5;
  }
  if ((int)(param_2 << 0x1a) < 0) {
LAB_000b61e2:
    if ((int)(param_2 << 0x1b) < 0) {
      uVar4 = 1;
LAB_000b6288:
      uVar4 = uVar4 | 8;
      goto LAB_000b61e8;
    }
  }
  else {
    if ((0x1d < iVar3 - 1U) ||
       (uVar4 = (uint)*(char *)(DAT_000b62cc + iVar3 + 0x94), uVar4 == 0xffffffff)) {
      if ((int)(param_2 << 0x17) < 0) goto LAB_000b61c8;
      goto LAB_000b61e2;
    }
    if (-1 < (int)(param_2 << 0x1b)) goto LAB_000b61e8;
    if (uVar4 != 0) goto LAB_000b6288;
  }
  uVar4 = 1;
LAB_000b61e8:
  iVar3 = do_buf_constprop_5(param_3[2],*param_3,uVar4,param_2 & 0xf,local_28,0);
  if (-1 < iVar3) {
    iVar3 = uVar5 + iVar3;
    if (local_28[0] == '\0') {
      if (param_1 == (BIO *)0x0) {
        return iVar3;
      }
    }
    else {
      iVar3 = iVar3 + 2;
      if (param_1 == (BIO *)0x0) {
        return iVar3;
      }
      iVar1 = BIO_write(param_1,DAT_000b62c8,1);
      if (iVar1 != 1) {
        return -1;
      }
    }
    iVar1 = do_buf_constprop_5(param_3[2],*param_3,uVar4,param_2 & 0xf,0,param_1);
    if (-1 < iVar1) {
      if (local_28[0] == '\0') {
        return iVar3;
      }
      iVar1 = BIO_write(param_1,DAT_000b62c8,1);
      if (iVar1 != 1) {
        return -1;
      }
      return iVar3;
    }
  }
  return -1;
}


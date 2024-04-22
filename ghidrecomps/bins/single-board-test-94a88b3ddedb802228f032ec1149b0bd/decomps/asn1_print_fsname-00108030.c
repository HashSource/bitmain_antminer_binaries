
bool asn1_print_fsname(BIO *param_1,int param_2,char *param_3,char *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  
  while (0x14 < param_2) {
    param_2 = param_2 + -0x14;
    iVar1 = BIO_write(param_1,DAT_001080c8,0x14);
    if (iVar1 != 0x14) {
      return false;
    }
  }
  iVar1 = BIO_write(param_1,DAT_001080c8,param_2);
  if (iVar1 != param_2) {
    return false;
  }
  uVar2 = *param_5;
  if ((int)(uVar2 << 0x17) < 0) {
    if ((uVar2 & 0x40) != 0) {
      return true;
    }
    param_4 = (char *)0x0;
LAB_00108070:
    if (param_4 == (char *)0x0 && param_3 == (char *)0x0) {
      return true;
    }
    if (param_3 == (char *)0x0) {
      if (param_4 == (char *)0x0) goto LAB_00108096;
      goto LAB_001080ae;
    }
    iVar1 = BIO_puts(param_1,param_3);
    if (iVar1 < 1) {
      return false;
    }
    if (param_4 == (char *)0x0) goto LAB_00108096;
    iVar1 = BIO_printf(param_1,DAT_001080cc,param_4);
  }
  else {
    if (-1 < (int)(uVar2 << 0x19)) goto LAB_00108070;
    if (param_4 == (char *)0x0) {
      return true;
    }
LAB_001080ae:
    iVar1 = BIO_puts(param_1,param_4);
  }
  if (iVar1 < 1) {
    return false;
  }
LAB_00108096:
  iVar1 = BIO_write(param_1,DAT_001080d0,2);
  return iVar1 == 2;
}


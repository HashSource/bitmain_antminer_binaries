
bool asn1_print_fsname_isra_0(BIO *param_1,int param_2,char *param_3,char *param_4,uint *param_5)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  
  if (0x14 < param_2) {
    do {
      param_2 = param_2 + -0x14;
      iVar1 = BIO_write(param_1,"                    ",0x14);
      if (iVar1 != 0x14) {
        return false;
      }
    } while (0x14 < param_2);
  }
  iVar1 = BIO_write(param_1,"                    ",param_2);
  if (iVar1 != param_2) {
    return false;
  }
  uVar3 = *param_5;
  if ((int)(uVar3 << 0x17) < 0) {
    if ((uVar3 & 0x40) != 0) {
      return true;
    }
    bVar2 = true;
    param_4 = (char *)0x0;
LAB_001815e2:
    if (param_3 != (char *)0x0) {
      bVar2 = false;
    }
    if (bVar2) {
      return true;
    }
    if (param_3 == (char *)0x0) {
      if (param_4 == (char *)0x0) goto LAB_00181614;
      goto LAB_001815ca;
    }
    iVar1 = BIO_puts(param_1,param_3);
    if (iVar1 < 1) {
      return false;
    }
    if (param_4 == (char *)0x0) goto LAB_00181614;
    iVar1 = BIO_printf(param_1," (%s)",param_4);
  }
  else {
    if (-1 < (int)(uVar3 << 0x19)) {
      bVar2 = param_4 == (char *)0x0;
      goto LAB_001815e2;
    }
    if (param_4 == (char *)0x0) {
      return true;
    }
LAB_001815ca:
    iVar1 = BIO_puts(param_1,param_4);
  }
  if (iVar1 < 1) {
    return false;
  }
LAB_00181614:
  iVar1 = BIO_write(param_1,": ",2);
  return iVar1 == 2;
}


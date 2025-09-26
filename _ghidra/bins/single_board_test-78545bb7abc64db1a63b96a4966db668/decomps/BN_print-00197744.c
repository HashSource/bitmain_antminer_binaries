
int BN_print(void *fp,BIGNUM *a)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if ((a->neg != 0) && (iVar1 = BIO_write((BIO *)fp,&DAT_0022aea4,1), iVar1 != 1)) {
    return 0;
  }
  iVar1 = BN_is_zero(a);
  if ((iVar1 != 0) && (iVar1 = BIO_write((BIO *)fp,"0",1), iVar1 != 1)) {
    return 0;
  }
  iVar1 = a->top + -1;
  if (-1 < iVar1) {
    iVar6 = iVar1 * 4;
    uVar2 = 0;
    do {
      if (uVar2 == 0) {
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar2 = uVar5 >> 0x1c;
        uVar4 = uVar2;
        if (uVar2 != 0) goto LAB_00197874;
LAB_0019779a:
        uVar4 = (uVar5 << 4) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_00197890;
LAB_001977a2:
        uVar4 = (uVar5 << 8) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_001978b0;
LAB_001977ae:
        uVar4 = (uVar5 << 0xc) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_001978d4;
LAB_001977ba:
        uVar4 = (uVar5 << 0x10) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_001978f8;
LAB_001977c6:
        uVar4 = (uVar5 << 0x14) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_0019791c;
LAB_001977d2:
        uVar4 = (uVar5 << 0x18) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_00197940;
LAB_001977de:
        uVar5 = uVar5 & 0xf;
        uVar2 = uVar2 | uVar5;
      }
      else {
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF",1);
        if (iVar3 != 1) {
          return 0;
        }
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF",1);
        if (iVar3 != 1) {
          return 0;
        }
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF",1);
        if (iVar3 != 1) {
          return 0;
        }
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF",1);
        if (iVar3 != 1) {
          return 0;
        }
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF",1);
        if (iVar3 != 1) {
          return 0;
        }
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF",1);
        if (iVar3 != 1) {
          return 0;
        }
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF",1);
        if (iVar3 != 1) {
          return 0;
        }
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF",1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = uVar5 >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_0019779a;
LAB_00197874:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 4) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_001977a2;
LAB_00197890:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 8) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_001977ae;
LAB_001978b0:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0xc) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_001977ba;
LAB_001978d4:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x10) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_001977c6;
LAB_001978f8:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x14) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_001977d2;
LAB_0019791c:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x18) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_001977de;
LAB_00197940:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6) & 0xf;
        uVar2 = uVar5 | 1;
      }
      if ((uVar2 != 0) && (uVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar5,1), uVar2 != 1)) {
        return 0;
      }
      iVar1 = iVar1 + -1;
      iVar6 = iVar6 + -4;
    } while (iVar1 != -1);
  }
  return 1;
}


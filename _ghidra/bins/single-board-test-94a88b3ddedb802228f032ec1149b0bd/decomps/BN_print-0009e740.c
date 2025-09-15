
int BN_print(void *fp,BIGNUM *a)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if ((a->neg != 0) && (iVar6 = BIO_write((BIO *)fp,"-",1), iVar6 != 1)) {
    return 0;
  }
  iVar6 = a->top;
  if (iVar6 == 0) {
    iVar6 = BIO_write((BIO *)fp,"0",1);
    if (iVar6 != 1) {
      return 0;
    }
    iVar6 = a->top;
  }
  iVar6 = iVar6 + -1;
  if (-1 < iVar6) {
    iVar5 = iVar6 * 4;
    uVar1 = 0;
    do {
      uVar4 = *(uint *)((int)a->d + iVar5);
      if (uVar1 == 0 && uVar4 >> 0x1c == 0) {
        uVar1 = (uVar4 << 4) >> 0x1c;
        uVar3 = uVar1;
        if (uVar1 == 0) goto LAB_0009e770;
LAB_0009e7cc:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0009e7e6;
LAB_0009e778:
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0009e780;
LAB_0009e800:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0009e81a;
LAB_0009e788:
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0009e790;
LAB_0009e834:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0009e84e;
LAB_0009e798:
        uVar4 = uVar4 & 0xf;
        uVar1 = uVar1 | uVar4;
      }
      else {
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + (uVar4 >> 0x1c),1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 4) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0009e7cc;
LAB_0009e770:
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0009e778;
LAB_0009e7e6:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0009e800;
LAB_0009e780:
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0009e788;
LAB_0009e81a:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0009e834;
LAB_0009e790:
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0009e798;
LAB_0009e84e:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5) & 0xf;
        uVar1 = uVar4 | 1;
      }
      if ((uVar1 != 0) && (uVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1), uVar1 != 1)) {
        return 0;
      }
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + -4;
    } while (iVar6 != -1);
  }
  return 1;
}


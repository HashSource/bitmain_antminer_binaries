
int BN_print(void *fp,BIGNUM *a)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if ((a->neg != 0) && (iVar6 = BIO_write((BIO *)fp,&DAT_002075c8,1), iVar6 != 1)) {
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
        if (uVar1 == 0) goto LAB_001416ac;
LAB_00141708:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_00141722;
LAB_001416b4:
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_001416bc;
LAB_0014173c:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_00141756;
LAB_001416c4:
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_001416cc;
LAB_00141770:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0014178a;
LAB_001416d4:
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
        if (uVar1 != 0) goto LAB_00141708;
LAB_001416ac:
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_001416b4;
LAB_00141722:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0014173c;
LAB_001416bc:
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_001416c4;
LAB_00141756:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_00141770;
LAB_001416cc:
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_001416d4;
LAB_0014178a:
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


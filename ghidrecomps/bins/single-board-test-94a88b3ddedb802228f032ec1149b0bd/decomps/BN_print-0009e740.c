
int BN_print(void *fp,BIGNUM *a)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if ((a->neg != 0) && (iVar7 = BIO_write((BIO *)fp,DAT_0009e8a8,1), iVar7 != 1)) {
    return 0;
  }
  iVar7 = a->top;
  if (iVar7 == 0) {
    iVar7 = BIO_write((BIO *)fp,DAT_0009e8ac,1);
    if (iVar7 != 1) {
      return 0;
    }
    iVar7 = a->top;
  }
  iVar1 = DAT_0009e8b0;
  iVar7 = iVar7 + -1;
  if (-1 < iVar7) {
    iVar6 = iVar7 * 4;
    uVar2 = 0;
    do {
      uVar5 = *(uint *)((int)a->d + iVar6);
      if ((uVar2 | uVar5 >> 0x1c) == 0) {
        uVar2 = (uVar5 << 4) >> 0x1c;
        uVar4 = uVar2;
        if (uVar2 == 0) goto LAB_0009e770;
LAB_0009e7cc:
        iVar3 = BIO_write((BIO *)fp,(void *)(uVar4 + iVar1),1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 8) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 != 0) goto LAB_0009e7e6;
LAB_0009e778:
        uVar4 = (uVar5 << 0xc) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 == 0) goto LAB_0009e780;
LAB_0009e800:
        iVar3 = BIO_write((BIO *)fp,(void *)(uVar4 + iVar1),1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x10) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 != 0) goto LAB_0009e81a;
LAB_0009e788:
        uVar4 = (uVar5 << 0x14) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 == 0) goto LAB_0009e790;
LAB_0009e834:
        iVar3 = BIO_write((BIO *)fp,(void *)(uVar4 + iVar1),1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x18) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 != 0) goto LAB_0009e84e;
LAB_0009e798:
        uVar5 = uVar5 & 0xf;
        uVar2 = uVar2 | uVar5;
      }
      else {
        iVar3 = BIO_write((BIO *)fp,(void *)((uVar5 >> 0x1c) + iVar1),1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 4) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 != 0) goto LAB_0009e7cc;
LAB_0009e770:
        uVar4 = (uVar5 << 8) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 == 0) goto LAB_0009e778;
LAB_0009e7e6:
        iVar3 = BIO_write((BIO *)fp,(void *)(uVar4 + iVar1),1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0xc) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 != 0) goto LAB_0009e800;
LAB_0009e780:
        uVar4 = (uVar5 << 0x10) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 == 0) goto LAB_0009e788;
LAB_0009e81a:
        iVar3 = BIO_write((BIO *)fp,(void *)(uVar4 + iVar1),1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x14) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 != 0) goto LAB_0009e834;
LAB_0009e790:
        uVar4 = (uVar5 << 0x18) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 == 0) goto LAB_0009e798;
LAB_0009e84e:
        iVar3 = BIO_write((BIO *)fp,(void *)(uVar4 + iVar1),1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6) & 0xf;
        uVar2 = uVar5 | 1;
      }
      if ((uVar2 != 0) && (uVar2 = BIO_write((BIO *)fp,(void *)(uVar5 + iVar1),1), uVar2 != 1)) {
        return 0;
      }
      iVar7 = iVar7 + -1;
      iVar6 = iVar6 + -4;
    } while (iVar7 != -1);
  }
  return 1;
}



int BN_print_fp(FILE *fp,BIGNUM *a)

{
  int iVar1;
  BIO_METHOD *type;
  BIO *bp;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  if ((a->neg == 0) || (iVar7 = BIO_write(bp,DAT_0009e734,1), iVar7 == 1)) {
    iVar7 = a->top;
    if (iVar7 == 0) {
      iVar7 = BIO_write(bp,DAT_0009e738,1);
      if (iVar7 != 1) goto LAB_0009e6f6;
      iVar7 = a->top;
    }
    iVar1 = DAT_0009e73c;
    iVar7 = iVar7 + -1;
    if (-1 < iVar7) {
      iVar6 = iVar7 * 4;
      uVar2 = 0;
      do {
        uVar5 = *(uint *)((int)a->d + iVar6);
        if ((uVar2 | uVar5 >> 0x1c) == 0) {
          uVar2 = (uVar5 << 4) >> 0x1c;
          uVar4 = uVar2;
          if (uVar2 == 0) goto LAB_0009e5ee;
LAB_0009e64c:
          iVar3 = BIO_write(bp,(void *)(uVar4 + iVar1),1);
          if (iVar3 != 1) goto LAB_0009e6f6;
          uVar5 = *(uint *)((int)a->d + iVar6);
          uVar4 = (uVar5 << 8) >> 0x1c;
          uVar2 = uVar4 | 1;
          if (uVar2 != 0) goto LAB_0009e666;
LAB_0009e5f6:
          uVar4 = (uVar5 << 0xc) >> 0x1c;
          uVar2 = uVar2 | uVar4;
          if (uVar2 == 0) goto LAB_0009e5fe;
LAB_0009e680:
          iVar3 = BIO_write(bp,(void *)(uVar4 + iVar1),1);
          if (iVar3 != 1) goto LAB_0009e6f6;
          uVar5 = *(uint *)((int)a->d + iVar6);
          uVar4 = (uVar5 << 0x10) >> 0x1c;
          uVar2 = uVar4 | 1;
          if (uVar2 != 0) goto LAB_0009e69a;
LAB_0009e606:
          uVar4 = (uVar5 << 0x14) >> 0x1c;
          uVar2 = uVar2 | uVar4;
          if (uVar2 == 0) goto LAB_0009e60e;
LAB_0009e6b4:
          iVar3 = BIO_write(bp,(void *)(uVar4 + iVar1),1);
          if (iVar3 != 1) goto LAB_0009e6f6;
          uVar5 = *(uint *)((int)a->d + iVar6);
          uVar4 = (uVar5 << 0x18) >> 0x1c;
          uVar2 = uVar4 | 1;
          if (uVar2 != 0) goto LAB_0009e6ce;
LAB_0009e616:
          uVar5 = uVar5 & 0xf;
          uVar2 = uVar2 | uVar5;
        }
        else {
          iVar3 = BIO_write(bp,(void *)((uVar5 >> 0x1c) + iVar1),1);
          if (iVar3 != 1) goto LAB_0009e6f6;
          uVar5 = *(uint *)((int)a->d + iVar6);
          uVar4 = (uVar5 << 4) >> 0x1c;
          uVar2 = uVar4 | 1;
          if (uVar2 != 0) goto LAB_0009e64c;
LAB_0009e5ee:
          uVar4 = (uVar5 << 8) >> 0x1c;
          uVar2 = uVar2 | uVar4;
          if (uVar2 == 0) goto LAB_0009e5f6;
LAB_0009e666:
          iVar3 = BIO_write(bp,(void *)(uVar4 + iVar1),1);
          if (iVar3 != 1) goto LAB_0009e6f6;
          uVar5 = *(uint *)((int)a->d + iVar6);
          uVar4 = (uVar5 << 0xc) >> 0x1c;
          uVar2 = uVar4 | 1;
          if (uVar2 != 0) goto LAB_0009e680;
LAB_0009e5fe:
          uVar4 = (uVar5 << 0x10) >> 0x1c;
          uVar2 = uVar2 | uVar4;
          if (uVar2 == 0) goto LAB_0009e606;
LAB_0009e69a:
          iVar3 = BIO_write(bp,(void *)(uVar4 + iVar1),1);
          if (iVar3 != 1) goto LAB_0009e6f6;
          uVar5 = *(uint *)((int)a->d + iVar6);
          uVar4 = (uVar5 << 0x14) >> 0x1c;
          uVar2 = uVar4 | 1;
          if (uVar2 != 0) goto LAB_0009e6b4;
LAB_0009e60e:
          uVar4 = (uVar5 << 0x18) >> 0x1c;
          uVar2 = uVar2 | uVar4;
          if (uVar2 == 0) goto LAB_0009e616;
LAB_0009e6ce:
          iVar3 = BIO_write(bp,(void *)(uVar4 + iVar1),1);
          if (iVar3 != 1) goto LAB_0009e6f6;
          uVar5 = *(uint *)((int)a->d + iVar6) & 0xf;
          uVar2 = uVar5 | 1;
        }
        if ((uVar2 != 0) && (uVar2 = BIO_write(bp,(void *)(uVar5 + iVar1),1), uVar2 != 1))
        goto LAB_0009e6f6;
        iVar7 = iVar7 + -1;
        iVar6 = iVar6 + -4;
      } while (iVar7 != -1);
    }
    iVar7 = 1;
  }
  else {
LAB_0009e6f6:
    iVar7 = 0;
  }
  BIO_free(bp);
  return iVar7;
}


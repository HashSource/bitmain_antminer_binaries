
int BN_print_fp(FILE *fp,BIGNUM *a)

{
  BIO_METHOD *type;
  BIO *bp;
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  if ((a->neg == 0) || (iVar6 = BIO_write(bp,"-",1), iVar6 == 1)) {
    iVar6 = a->top;
    if (iVar6 == 0) {
      iVar6 = BIO_write(bp,"0",1);
      if (iVar6 != 1) goto LAB_0009e6f6;
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
          if (uVar1 == 0) goto LAB_0009e5ee;
LAB_0009e64c:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_0009e6f6;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 8) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_0009e666;
LAB_0009e5f6:
          uVar3 = (uVar4 << 0xc) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_0009e5fe;
LAB_0009e680:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_0009e6f6;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0x10) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_0009e69a;
LAB_0009e606:
          uVar3 = (uVar4 << 0x14) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_0009e60e;
LAB_0009e6b4:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_0009e6f6;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0x18) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_0009e6ce;
LAB_0009e616:
          uVar4 = uVar4 & 0xf;
          uVar1 = uVar1 | uVar4;
        }
        else {
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + (uVar4 >> 0x1c),1);
          if (iVar2 != 1) goto LAB_0009e6f6;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 4) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_0009e64c;
LAB_0009e5ee:
          uVar3 = (uVar4 << 8) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_0009e5f6;
LAB_0009e666:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_0009e6f6;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0xc) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_0009e680;
LAB_0009e5fe:
          uVar3 = (uVar4 << 0x10) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_0009e606;
LAB_0009e69a:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_0009e6f6;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0x14) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_0009e6b4;
LAB_0009e60e:
          uVar3 = (uVar4 << 0x18) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_0009e616;
LAB_0009e6ce:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_0009e6f6;
          uVar4 = *(uint *)((int)a->d + iVar5) & 0xf;
          uVar1 = uVar4 | 1;
        }
        if ((uVar1 != 0) && (uVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar4,1), uVar1 != 1))
        goto LAB_0009e6f6;
        iVar6 = iVar6 + -1;
        iVar5 = iVar5 + -4;
      } while (iVar6 != -1);
    }
    iVar6 = 1;
  }
  else {
LAB_0009e6f6:
    iVar6 = 0;
  }
  BIO_free(bp);
  return iVar6;
}


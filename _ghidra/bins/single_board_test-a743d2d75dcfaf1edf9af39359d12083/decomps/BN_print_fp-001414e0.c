
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
  if ((a->neg == 0) || (iVar6 = BIO_write(bp,&DAT_002075c8,1), iVar6 == 1)) {
    iVar6 = a->top;
    if (iVar6 == 0) {
      iVar6 = BIO_write(bp,"0",1);
      if (iVar6 != 1) goto LAB_00141632;
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
          if (uVar1 == 0) goto LAB_0014152a;
LAB_00141588:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00141632;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 8) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_001415a2;
LAB_00141532:
          uVar3 = (uVar4 << 0xc) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_0014153a;
LAB_001415bc:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00141632;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0x10) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_001415d6;
LAB_00141542:
          uVar3 = (uVar4 << 0x14) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_0014154a;
LAB_001415f0:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00141632;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0x18) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_0014160a;
LAB_00141552:
          uVar4 = uVar4 & 0xf;
          uVar1 = uVar1 | uVar4;
        }
        else {
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + (uVar4 >> 0x1c),1);
          if (iVar2 != 1) goto LAB_00141632;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 4) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_00141588;
LAB_0014152a:
          uVar3 = (uVar4 << 8) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_00141532;
LAB_001415a2:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00141632;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0xc) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_001415bc;
LAB_0014153a:
          uVar3 = (uVar4 << 0x10) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_00141542;
LAB_001415d6:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00141632;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0x14) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_001415f0;
LAB_0014154a:
          uVar3 = (uVar4 << 0x18) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_00141552;
LAB_0014160a:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00141632;
          uVar4 = *(uint *)((int)a->d + iVar5) & 0xf;
          uVar1 = uVar4 | 1;
        }
        if ((uVar1 != 0) && (uVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar4,1), uVar1 != 1))
        goto LAB_00141632;
        iVar6 = iVar6 + -1;
        iVar5 = iVar5 + -4;
      } while (iVar6 != -1);
    }
    iVar6 = 1;
  }
  else {
LAB_00141632:
    iVar6 = 0;
  }
  BIO_free(bp);
  return iVar6;
}


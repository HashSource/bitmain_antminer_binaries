
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
  if ((a->neg == 0) || (iVar6 = BIO_write(bp,&DAT_0020bf10,1), iVar6 == 1)) {
    iVar6 = a->top;
    if (iVar6 == 0) {
      iVar6 = BIO_write(bp,"0",1);
      if (iVar6 != 1) goto LAB_00144172;
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
          if (uVar1 == 0) goto LAB_0014406a;
LAB_001440c8:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00144172;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 8) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_001440e2;
LAB_00144072:
          uVar3 = (uVar4 << 0xc) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_0014407a;
LAB_001440fc:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00144172;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0x10) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_00144116;
LAB_00144082:
          uVar3 = (uVar4 << 0x14) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_0014408a;
LAB_00144130:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00144172;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0x18) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_0014414a;
LAB_00144092:
          uVar4 = uVar4 & 0xf;
          uVar1 = uVar1 | uVar4;
        }
        else {
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + (uVar4 >> 0x1c),1);
          if (iVar2 != 1) goto LAB_00144172;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 4) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_001440c8;
LAB_0014406a:
          uVar3 = (uVar4 << 8) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_00144072;
LAB_001440e2:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00144172;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0xc) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_001440fc;
LAB_0014407a:
          uVar3 = (uVar4 << 0x10) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_00144082;
LAB_00144116:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00144172;
          uVar4 = *(uint *)((int)a->d + iVar5);
          uVar3 = (uVar4 << 0x14) >> 0x1c;
          uVar1 = uVar3 | 1;
          if (uVar1 != 0) goto LAB_00144130;
LAB_0014408a:
          uVar3 = (uVar4 << 0x18) >> 0x1c;
          uVar1 = uVar1 | uVar3;
          if (uVar1 == 0) goto LAB_00144092;
LAB_0014414a:
          iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar2 != 1) goto LAB_00144172;
          uVar4 = *(uint *)((int)a->d + iVar5) & 0xf;
          uVar1 = uVar4 | 1;
        }
        if ((uVar1 != 0) && (uVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar4,1), uVar1 != 1))
        goto LAB_00144172;
        iVar6 = iVar6 + -1;
        iVar5 = iVar5 + -4;
      } while (iVar6 != -1);
    }
    iVar6 = 1;
  }
  else {
LAB_00144172:
    iVar6 = 0;
  }
  BIO_free(bp);
  return iVar6;
}


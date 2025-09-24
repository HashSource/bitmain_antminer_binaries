
int BN_print(void *fp,BIGNUM *a)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if ((a->neg != 0) && (iVar1 = BIO_write((BIO *)fp,&DAT_0021f3c4,1), iVar1 != 1)) {
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
        if (uVar2 != 0) goto LAB_0018dc9c;
LAB_0018dbc2:
        uVar4 = (uVar5 << 4) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_0018dcb8;
LAB_0018dbca:
        uVar4 = (uVar5 << 8) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_0018dcd8;
LAB_0018dbd6:
        uVar4 = (uVar5 << 0xc) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_0018dcfc;
LAB_0018dbe2:
        uVar4 = (uVar5 << 0x10) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_0018dd20;
LAB_0018dbee:
        uVar4 = (uVar5 << 0x14) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_0018dd44;
LAB_0018dbfa:
        uVar4 = (uVar5 << 0x18) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_0018dd68;
LAB_0018dc06:
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
        if (uVar2 == 0) goto LAB_0018dbc2;
LAB_0018dc9c:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 4) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_0018dbca;
LAB_0018dcb8:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 8) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_0018dbd6;
LAB_0018dcd8:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0xc) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_0018dbe2;
LAB_0018dcfc:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x10) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_0018dbee;
LAB_0018dd20:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x14) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_0018dbfa;
LAB_0018dd44:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x18) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_0018dc06;
LAB_0018dd68:
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


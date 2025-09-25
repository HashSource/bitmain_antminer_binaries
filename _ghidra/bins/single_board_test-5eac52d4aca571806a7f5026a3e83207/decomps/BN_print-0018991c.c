
int BN_print(void *fp,BIGNUM *a)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if ((a->neg != 0) && (iVar1 = BIO_write((BIO *)fp,&DAT_00219c9c,1), iVar1 != 1)) {
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
        if (uVar2 != 0) goto LAB_00189a4c;
LAB_00189972:
        uVar4 = (uVar5 << 4) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_00189a68;
LAB_0018997a:
        uVar4 = (uVar5 << 8) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_00189a88;
LAB_00189986:
        uVar4 = (uVar5 << 0xc) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_00189aac;
LAB_00189992:
        uVar4 = (uVar5 << 0x10) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_00189ad0;
LAB_0018999e:
        uVar4 = (uVar5 << 0x14) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_00189af4;
LAB_001899aa:
        uVar4 = (uVar5 << 0x18) >> 0x1c;
        uVar2 = uVar2 | uVar4;
        if (uVar2 != 0) goto LAB_00189b18;
LAB_001899b6:
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
        if (uVar2 == 0) goto LAB_00189972;
LAB_00189a4c:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 4) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_0018997a;
LAB_00189a68:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 8) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_00189986;
LAB_00189a88:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0xc) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_00189992;
LAB_00189aac:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x10) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_0018999e;
LAB_00189ad0:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x14) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_001899aa;
LAB_00189af4:
        iVar3 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1);
        if (iVar3 != 1) {
          return 0;
        }
        uVar5 = *(uint *)((int)a->d + iVar6);
        uVar4 = (uVar5 << 0x18) >> 0x1c;
        uVar2 = uVar4 | 1;
        if (uVar2 == 0) goto LAB_001899b6;
LAB_00189b18:
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


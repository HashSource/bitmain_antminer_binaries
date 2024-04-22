
int ASN1_bn_print(BIO *bp,char *number,BIGNUM *num,uchar *buf,int off)

{
  char cVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  uchar *puVar8;
  char *pcVar9;
  
  pcVar3 = DAT_000b90c0;
  if (num == (BIGNUM *)0x0) {
    return 1;
  }
  pcVar9 = DAT_000b90c0;
  if (num->neg != 0) {
    pcVar9 = DAT_000b90c4;
  }
  iVar4 = BIO_indent(bp,off,0x80);
  if (iVar4 != 0) {
    if (num->top == 0) {
      iVar4 = BIO_printf(bp,DAT_000b90c8,number);
      return (uint)(0 < iVar4);
    }
    iVar4 = BN_num_bits(num);
    pcVar6 = DAT_000b90cc;
    if (iVar4 < 0x21) {
      iVar4 = BIO_printf(bp,DAT_000b90dc,number,pcVar9,*num->d,pcVar9,*num->d);
      return (uint)(0 < iVar4);
    }
    cVar1 = *pcVar9;
    *buf = '\0';
    if (cVar1 != '-') {
      pcVar6 = pcVar3;
    }
    iVar4 = BIO_printf(bp,DAT_000b90d0,number,pcVar6);
    if (0 < iVar4) {
      iVar4 = BN_bn2bin(num,buf + 1);
      puVar8 = buf + 1;
      if ((char)buf[1] < '\0') {
        iVar4 = iVar4 + 1;
        puVar8 = buf;
      }
      if (iVar4 < 1) {
LAB_000b90aa:
        iVar4 = BIO_write(bp,DAT_000b90e0,1);
        return (uint)(0 < iVar4);
      }
      iVar7 = 0;
      do {
        if (iVar7 == (iVar7 / 0xf) * 0xf) {
          iVar5 = BIO_puts(bp,DAT_000b90e0);
          if (iVar5 < 1) {
            return 0;
          }
          iVar5 = BIO_indent(bp,off + 4,0x80);
          if (iVar5 == 0) {
            return 0;
          }
        }
        pbVar2 = puVar8 + iVar7;
        iVar7 = iVar7 + 1;
        if (iVar7 == iVar4) {
          iVar4 = BIO_printf(bp,DAT_000b90d4,(uint)*pbVar2,DAT_000b90c0);
          if (iVar4 < 1) {
            return 0;
          }
          goto LAB_000b90aa;
        }
        iVar5 = BIO_printf(bp,DAT_000b90d4,(uint)*pbVar2,DAT_000b90d8);
      } while (0 < iVar5);
    }
  }
  return 0;
}


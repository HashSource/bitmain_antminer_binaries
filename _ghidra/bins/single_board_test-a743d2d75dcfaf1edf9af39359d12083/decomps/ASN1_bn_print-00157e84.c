
int ASN1_bn_print(BIO *bp,char *number,BIGNUM *num,uchar *buf,int off)

{
  char cVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  char *pcVar7;
  
  if (num == (BIGNUM *)0x0) {
    return 1;
  }
  if (num->neg == 0) {
    pcVar7 = "";
  }
  else {
    pcVar7 = "-";
  }
  iVar3 = BIO_indent(bp,off,0x80);
  if (iVar3 != 0) {
    if (num->top == 0) {
      iVar3 = BIO_printf(bp,"%s 0\n",number);
      return (uint)(0 < iVar3);
    }
    iVar3 = BN_num_bits(num);
    if (iVar3 < 0x21) {
      iVar3 = BIO_printf(bp,"%s %s%lu (%s0x%lx)\n",number,pcVar7,*num->d,pcVar7,*num->d);
      return (uint)(0 < iVar3);
    }
    cVar1 = *pcVar7;
    pcVar7 = " (Negative)";
    *buf = '\0';
    if (cVar1 != '-') {
      pcVar7 = "";
    }
    iVar3 = BIO_printf(bp,"%s%s",number,pcVar7);
    if (0 < iVar3) {
      iVar3 = BN_bn2bin(num,buf + 1);
      puVar6 = buf + 1;
      if ((char)buf[1] < '\0') {
        iVar3 = iVar3 + 1;
        puVar6 = buf;
      }
      if (iVar3 < 1) {
LAB_00157fae:
        iVar3 = BIO_write(bp,"\n",1);
        return (uint)(0 < iVar3);
      }
      iVar5 = 0;
      do {
        if (iVar5 == (iVar5 / 0xf) * 0xf) {
          iVar4 = BIO_puts(bp,"\n");
          if (iVar4 < 1) {
            return 0;
          }
          iVar4 = BIO_indent(bp,off + 4,0x80);
          if (iVar4 == 0) {
            return 0;
          }
        }
        pbVar2 = puVar6 + iVar5;
        iVar5 = iVar5 + 1;
        if (iVar5 == iVar3) {
          iVar3 = BIO_printf(bp,"%02x%s",(uint)*pbVar2,"");
          if (iVar3 < 1) {
            return 0;
          }
          goto LAB_00157fae;
        }
        iVar4 = BIO_printf(bp,"%02x%s",(uint)*pbVar2,":");
      } while (0 < iVar4);
    }
  }
  return 0;
}


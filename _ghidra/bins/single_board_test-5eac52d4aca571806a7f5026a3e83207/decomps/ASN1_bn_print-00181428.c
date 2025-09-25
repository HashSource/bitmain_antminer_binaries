
int ASN1_bn_print(BIO *bp,char *number,BIGNUM *num,uchar *buf,int off)

{
  char cVar1;
  uchar *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uchar *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  if (num == (BIGNUM *)0x0) {
    return 1;
  }
  iVar3 = BN_is_negative(num);
  if (iVar3 == 0) {
    pcVar7 = "";
    iVar3 = BIO_indent(bp,off,0x80);
  }
  else {
    pcVar7 = "-";
    iVar3 = BIO_indent(bp,off,0x80);
  }
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = BN_is_zero(num);
  if (iVar3 != 0) {
    iVar3 = BIO_printf(bp,"%s 0\n",number);
    return (uint)(0 < iVar3);
  }
  iVar3 = BN_num_bits(num);
  if (iVar3 < 0x41) {
    puVar4 = (undefined4 *)bn_get_words();
    uVar8 = *puVar4;
    puVar4 = (undefined4 *)bn_get_words(num);
    iVar3 = BIO_printf(bp,"%s %s%lu (%s0x%lx)\n",number,pcVar7,uVar8,pcVar7,*puVar4);
    return (uint)(0 < iVar3);
  }
  iVar5 = BN_num_bits(num);
  iVar3 = iVar5 + 0xe;
  if (-1 < iVar5 + 7) {
    iVar3 = iVar5 + 7;
  }
  iVar3 = (iVar3 >> 3) + 1;
  puVar6 = (uchar *)CRYPTO_malloc(iVar3,"crypto/asn1/t_pkey.c",0x49);
  if (puVar6 != (uchar *)0x0) {
    cVar1 = *pcVar7;
    *puVar6 = '\0';
    if (cVar1 == '-') {
      pcVar7 = " (Negative)";
    }
    else {
      pcVar7 = "";
    }
    iVar5 = BIO_printf(bp,"%s%s\n",number,pcVar7);
    if (0 < iVar5) {
      iVar5 = BN_bn2bin(num,puVar6 + 1);
      puVar2 = puVar6 + 1;
      if ((char)puVar6[1] < '\0') {
        iVar5 = iVar5 + 1;
        puVar2 = puVar6;
      }
      iVar5 = ASN1_buf_print(bp,puVar2,iVar5,off + 4);
      if (iVar5 != 0) {
        iVar5 = 1;
      }
      goto LAB_0018153c;
    }
  }
  iVar5 = 0;
LAB_0018153c:
  CRYPTO_clear_free(puVar6,iVar3,"crypto/asn1/t_pkey.c",0x5b);
  return iVar5;
}


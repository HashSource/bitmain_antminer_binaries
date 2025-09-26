
int DHparams_print(BIO *bp,DH *x)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  if (x->p == (BIGNUM *)0x0) {
    iVar2 = 0x43;
  }
  else {
    BIO_indent(bp,4,0x80);
    iVar2 = BN_num_bits(x->p);
    iVar2 = BIO_printf(bp,"%s: (%d bit)\n","DH Parameters",iVar2);
    if ((((((0 < iVar2) &&
           (iVar2 = ASN1_bn_print(bp,"private-key:",(BIGNUM *)0x0,(uchar *)0x0,8), iVar2 != 0)) &&
          (iVar2 = ASN1_bn_print(bp,"public-key:",(BIGNUM *)0x0,(uchar *)0x0,8), iVar2 != 0)) &&
         ((iVar2 = ASN1_bn_print(bp,"prime:",x->p,(uchar *)0x0,8), iVar2 != 0 &&
          (iVar2 = ASN1_bn_print(bp,"generator:",x->g,(uchar *)0x0,8), iVar2 != 0)))) &&
        ((x->q == (BIGNUM *)0x0 ||
         (iVar2 = ASN1_bn_print(bp,"subgroup order:",x->q,(uchar *)0x0,8), iVar2 != 0)))) &&
       ((x->j == (BIGNUM *)0x0 ||
        (iVar2 = ASN1_bn_print(bp,"subgroup factor:",x->j,(uchar *)0x0,8), iVar2 != 0)))) {
      if (x->seed == (uchar *)0x0) {
LAB_00120b48:
        if ((x->counter == (BIGNUM *)0x0) ||
           (iVar2 = ASN1_bn_print(bp,"counter:",x->counter,(uchar *)0x0,8), iVar2 != 0)) {
          if (x->length == 0) {
            return 1;
          }
          BIO_indent(bp,8,0x80);
          iVar2 = BIO_printf(bp,"recommended-private-length: %d bits\n",x->length);
          if (0 < iVar2) {
            return 1;
          }
        }
      }
      else {
        BIO_indent(bp,8,0x80);
        iVar2 = 0;
        BIO_puts(bp,"seed:");
        do {
          iVar3 = x->seedlen;
          if (iVar3 <= iVar2) {
            iVar2 = BIO_write(bp,"\n",1);
            if (iVar2 < 1) {
              return 0;
            }
            goto LAB_00120b48;
          }
          if (iVar2 == (iVar2 / 0xf) * 0xf) {
            iVar3 = BIO_puts(bp,"\n");
            if ((iVar3 < 1) || (iVar3 = BIO_indent(bp,0xc,0x80), iVar3 == 0)) break;
            iVar3 = x->seedlen;
          }
          pbVar1 = x->seed + iVar2;
          iVar2 = iVar2 + 1;
          pcVar4 = ":";
          if (iVar3 == iVar2) {
            pcVar4 = "";
          }
          iVar3 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,pcVar4);
        } while (0 < iVar3);
      }
    }
    iVar2 = 7;
  }
  ERR_put_error(5,100,iVar2,"crypto/dh/dh_ameth.c",0x157);
  return 0;
}


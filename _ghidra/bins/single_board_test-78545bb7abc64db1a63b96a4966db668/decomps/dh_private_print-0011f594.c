
undefined4 dh_private_print(BIO *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  BIGNUM *num;
  BIGNUM *num_00;
  int off;
  
  iVar5 = *(int *)(param_2 + 0x18);
  num = *(BIGNUM **)(iVar5 + 0x18);
  num_00 = *(BIGNUM **)(iVar5 + 0x14);
  if (num_00 == (BIGNUM *)0x0 || (num == (BIGNUM *)0x0 || *(int *)(iVar5 + 8) == 0)) {
    iVar5 = 0x43;
  }
  else {
    BIO_indent(param_1,param_3,0x80);
    iVar2 = BN_num_bits(*(BIGNUM **)(iVar5 + 8));
    iVar2 = BIO_printf(param_1,"%s: (%d bit)\n","DH Private-Key",iVar2);
    if (0 < iVar2) {
      off = param_3 + 4;
      iVar2 = ASN1_bn_print(param_1,"private-key:",num,(uchar *)0x0,off);
      if (((((iVar2 != 0) &&
            (iVar2 = ASN1_bn_print(param_1,"public-key:",num_00,(uchar *)0x0,off), iVar2 != 0)) &&
           (iVar2 = ASN1_bn_print(param_1,"prime:",*(BIGNUM **)(iVar5 + 8),(uchar *)0x0,off),
           iVar2 != 0)) &&
          (iVar2 = ASN1_bn_print(param_1,"generator:",*(BIGNUM **)(iVar5 + 0xc),(uchar *)0x0,off),
          iVar2 != 0)) &&
         (((*(BIGNUM **)(iVar5 + 0x24) == (BIGNUM *)0x0 ||
           (iVar2 = ASN1_bn_print(param_1,"subgroup order:",*(BIGNUM **)(iVar5 + 0x24),(uchar *)0x0,
                                  off), iVar2 != 0)) &&
          ((*(BIGNUM **)(iVar5 + 0x28) == (BIGNUM *)0x0 ||
           (iVar2 = ASN1_bn_print(param_1,"subgroup factor:",*(BIGNUM **)(iVar5 + 0x28),(uchar *)0x0
                                  ,off), iVar2 != 0)))))) {
        if (*(int *)(iVar5 + 0x2c) == 0) {
LAB_0011f718:
          if ((*(BIGNUM **)(iVar5 + 0x34) == (BIGNUM *)0x0) ||
             (iVar2 = ASN1_bn_print(param_1,"counter:",*(BIGNUM **)(iVar5 + 0x34),(uchar *)0x0,off),
             iVar2 != 0)) {
            if (*(int *)(iVar5 + 0x10) == 0) {
              return 1;
            }
            BIO_indent(param_1,off,0x80);
            iVar5 = BIO_printf(param_1,"recommended-private-length: %d bits\n",
                               *(undefined4 *)(iVar5 + 0x10));
            if (0 < iVar5) {
              return 1;
            }
          }
        }
        else {
          BIO_indent(param_1,off,0x80);
          iVar2 = 0;
          BIO_puts(param_1,"seed:");
          do {
            iVar3 = *(int *)(iVar5 + 0x30);
            if (iVar3 <= iVar2) {
              iVar2 = BIO_write(param_1,"\n",1);
              if (iVar2 < 1) {
                return 0;
              }
              goto LAB_0011f718;
            }
            if (iVar2 == (iVar2 / 0xf) * 0xf) {
              iVar3 = BIO_puts(param_1,"\n");
              if ((iVar3 < 1) || (iVar3 = BIO_indent(param_1,param_3 + 8,0x80), iVar3 == 0)) break;
              iVar3 = *(int *)(iVar5 + 0x30);
            }
            pbVar1 = (byte *)(*(int *)(iVar5 + 0x2c) + iVar2);
            iVar2 = iVar2 + 1;
            pcVar4 = ":";
            if (iVar2 == iVar3) {
              pcVar4 = "";
            }
            iVar3 = BIO_printf(param_1,"%02x%s",(uint)*pbVar1,pcVar4);
          } while (0 < iVar3);
        }
      }
    }
    iVar5 = 7;
  }
  ERR_put_error(5,100,iVar5,"crypto/dh/dh_ameth.c",0x157);
  return 0;
}



int do_rsa_print(BIO *param_1,int param_2,int param_3,int param_4)

{
  BIGNUM *pBVar1;
  int iVar2;
  uchar *buf;
  int iVar3;
  char *number;
  char *number_00;
  
  pBVar1 = *(BIGNUM **)(param_2 + 0x10);
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar2 = BN_num_bits(pBVar1);
    iVar3 = iVar2 + 0xe;
    if (-1 < iVar2 + 7) {
      iVar3 = iVar2 + 7;
    }
    pBVar1 = (BIGNUM *)(iVar3 >> 3);
  }
  if (*(BIGNUM **)(param_2 + 0x14) != (BIGNUM *)0x0) {
    iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x14));
    iVar3 = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      iVar3 = iVar2 + 0xe;
    }
    if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
      pBVar1 = (BIGNUM *)(iVar3 >> 3);
    }
  }
  if (param_4 != 0) {
    if (*(BIGNUM **)(param_2 + 0x18) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x18));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    if (*(BIGNUM **)(param_2 + 0x1c) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x1c));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    if (*(BIGNUM **)(param_2 + 0x20) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x20));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    if (*(BIGNUM **)(param_2 + 0x24) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x24));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    if (*(BIGNUM **)(param_2 + 0x28) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x28));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    if (*(BIGNUM **)(param_2 + 0x2c) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x2c));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
  }
  buf = (uchar *)CRYPTO_malloc((int)((int)&pBVar1->dmax + 2),"rsa_ameth.c",0xcc);
  if (buf == (uchar *)0x0) {
    ERR_put_error(4,0x92,0x41,"rsa_ameth.c",0xce);
    return 0;
  }
  pBVar1 = *(BIGNUM **)(param_2 + 0x10);
  if (pBVar1 != (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)BN_num_bits(pBVar1);
  }
  iVar3 = BIO_indent(param_1,param_3,0x80);
  if (iVar3 != 0) {
    if ((param_4 == 0) || (*(int *)(param_2 + 0x18) == 0)) {
      iVar3 = BIO_printf(param_1,"Public-Key: (%d bit)\n",pBVar1);
      if (0 < iVar3) {
        number_00 = "Exponent:";
        number = "Modulus:";
        goto LAB_00197d8e;
      }
    }
    else {
      iVar3 = BIO_printf(param_1,"Private-Key: (%d bit)\n",pBVar1);
      if (0 < iVar3) {
        number_00 = "publicExponent:";
        number = "modulus:";
LAB_00197d8e:
        iVar3 = ASN1_bn_print(param_1,number,*(BIGNUM **)(param_2 + 0x10),buf,param_3);
        if ((iVar3 != 0) &&
           (iVar3 = ASN1_bn_print(param_1,number_00,*(BIGNUM **)(param_2 + 0x14),buf,param_3),
           iVar3 != 0)) {
          if (param_4 == 0) {
            iVar3 = 1;
            goto LAB_00197cb2;
          }
          iVar3 = ASN1_bn_print(param_1,"privateExponent:",*(BIGNUM **)(param_2 + 0x18),buf,param_3)
          ;
          if ((((iVar3 != 0) &&
               (iVar3 = ASN1_bn_print(param_1,"prime1:",*(BIGNUM **)(param_2 + 0x1c),buf,param_3),
               iVar3 != 0)) &&
              (iVar3 = ASN1_bn_print(param_1,"prime2:",*(BIGNUM **)(param_2 + 0x20),buf,param_3),
              iVar3 != 0)) &&
             ((iVar3 = ASN1_bn_print(param_1,"exponent1:",*(BIGNUM **)(param_2 + 0x24),buf,param_3),
              iVar3 != 0 &&
              (iVar3 = ASN1_bn_print(param_1,"exponent2:",*(BIGNUM **)(param_2 + 0x28),buf,param_3),
              iVar3 != 0)))) {
            iVar3 = ASN1_bn_print(param_1,"coefficient:",*(BIGNUM **)(param_2 + 0x2c),buf,param_3);
            if (iVar3 != 0) {
              iVar3 = 1;
            }
            goto LAB_00197cb2;
          }
        }
      }
    }
  }
  iVar3 = 0;
LAB_00197cb2:
  CRYPTO_free(buf);
  return iVar3;
}



undefined4 rsa_priv_print(BIO *param_1,int param_2,int param_3)

{
  BIGNUM *a;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *number;
  
  iVar6 = *(int *)(param_2 + 0x18);
  a = *(BIGNUM **)(iVar6 + 0x10);
  if (a != (BIGNUM *)0x0) {
    a = (BIGNUM *)BN_num_bits(a);
  }
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(iVar6 + 0x30));
  iVar2 = BIO_indent(param_1,param_3,0x80);
  if (iVar2 != 0) {
    if (**(int **)(param_2 + 0xc) == 0x390) {
      pcVar5 = "RSA-PSS";
    }
    else {
      pcVar5 = "RSA";
    }
    iVar2 = BIO_printf(param_1,"%s ",pcVar5);
    if (0 < iVar2) {
      if (*(int *)(iVar6 + 0x18) == 0) {
        iVar1 = BIO_printf(param_1,"Public-Key: (%d bit)\n",a);
        if (iVar1 < 1) {
          return 0;
        }
        number = "Exponent:";
        pcVar5 = "Modulus:";
      }
      else {
        if (iVar1 < 1) {
          iVar1 = 2;
        }
        else {
          iVar1 = iVar1 + 2;
        }
        iVar1 = BIO_printf(param_1,"Private-Key: (%d bit, %d primes)\n",a,iVar1);
        if (iVar1 < 1) {
          return 0;
        }
        number = "publicExponent:";
        pcVar5 = "modulus:";
      }
      iVar1 = ASN1_bn_print(param_1,pcVar5,*(BIGNUM **)(iVar6 + 0x10),(uchar *)0x0,param_3);
      if (((((iVar1 != 0) &&
            (iVar1 = ASN1_bn_print(param_1,number,*(BIGNUM **)(iVar6 + 0x14),(uchar *)0x0,param_3),
            iVar1 != 0)) &&
           (iVar1 = ASN1_bn_print(param_1,"privateExponent:",*(BIGNUM **)(iVar6 + 0x18),(uchar *)0x0
                                  ,param_3), iVar1 != 0)) &&
          ((iVar1 = ASN1_bn_print(param_1,"prime1:",*(BIGNUM **)(iVar6 + 0x1c),(uchar *)0x0,param_3)
           , iVar1 != 0 &&
           (iVar1 = ASN1_bn_print(param_1,"prime2:",*(BIGNUM **)(iVar6 + 0x20),(uchar *)0x0,param_3)
           , iVar1 != 0)))) &&
         ((iVar1 = ASN1_bn_print(param_1,"exponent1:",*(BIGNUM **)(iVar6 + 0x24),(uchar *)0x0,
                                 param_3), iVar1 != 0 &&
          ((iVar1 = ASN1_bn_print(param_1,"exponent2:",*(BIGNUM **)(iVar6 + 0x28),(uchar *)0x0,
                                  param_3), iVar1 != 0 &&
           (iVar1 = ASN1_bn_print(param_1,"coefficient:",*(BIGNUM **)(iVar6 + 0x2c),(uchar *)0x0,
                                  param_3), iVar1 != 0)))))) {
        iVar1 = 3;
        do {
          iVar2 = OPENSSL_sk_num(*(undefined4 *)(iVar6 + 0x30));
          if (iVar2 <= iVar1 + -3) {
            if (**(int **)(param_2 + 0xc) != 0x390) {
              return 1;
            }
            iVar6 = rsa_pss_param_print(param_1,1,*(undefined4 *)(iVar6 + 0x34),param_3);
            if (iVar6 != 0) {
              return 1;
            }
            return 0;
          }
          puVar3 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(iVar6 + 0x30),iVar1 + -3);
          iVar2 = 1;
LAB_0014a15e:
          iVar4 = BIO_indent(param_1,param_3,0x80);
          if (iVar4 == 0) {
            return 0;
          }
          if (iVar2 == 2) {
            iVar4 = BIO_printf(param_1,"exponent%d:",iVar1);
            if (iVar4 < 1) {
              return 0;
            }
            iVar4 = ASN1_bn_print(param_1,"",(BIGNUM *)puVar3[1],(uchar *)0x0,param_3);
            if (iVar4 == 0) {
              return 0;
            }
LAB_0014a1aa:
            iVar2 = iVar2 + 1;
            goto LAB_0014a15e;
          }
          if (iVar2 != 3) {
            iVar4 = BIO_printf(param_1,"prime%d:",iVar1);
            if (iVar4 < 1) {
              return 0;
            }
            iVar4 = ASN1_bn_print(param_1,"",(BIGNUM *)*puVar3,(uchar *)0x0,param_3);
            if (iVar4 == 0) {
              return 0;
            }
            if (iVar2 == 3) goto LAB_0014a13e;
            goto LAB_0014a1aa;
          }
          iVar2 = BIO_printf(param_1,"coefficient%d:",iVar1);
          if (iVar2 < 1) {
            return 0;
          }
          iVar2 = ASN1_bn_print(param_1,"",(BIGNUM *)puVar3[2],(uchar *)0x0,param_3);
          if (iVar2 == 0) {
            return 0;
          }
LAB_0014a13e:
          iVar1 = iVar1 + 1;
        } while( true );
      }
    }
  }
  return 0;
}


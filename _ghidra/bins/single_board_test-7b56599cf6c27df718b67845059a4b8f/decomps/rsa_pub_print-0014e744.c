
undefined4 rsa_pub_print(BIO *param_1,int param_2,int param_3)

{
  BIGNUM *a;
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x18);
  a = *(BIGNUM **)(iVar3 + 0x10);
  if (a != (BIGNUM *)0x0) {
    a = (BIGNUM *)BN_num_bits(a);
  }
  OPENSSL_sk_num(*(undefined4 *)(iVar3 + 0x30));
  iVar1 = BIO_indent(param_1,param_3,0x80);
  if (iVar1 != 0) {
    if (**(int **)(param_2 + 0xc) == 0x390) {
      pcVar2 = "RSA-PSS";
    }
    else {
      pcVar2 = "RSA";
    }
    iVar1 = BIO_printf(param_1,"%s ",pcVar2);
    if ((((0 < iVar1) && (iVar1 = BIO_printf(param_1,"Public-Key: (%d bit)\n",a), 0 < iVar1)) &&
        (iVar1 = ASN1_bn_print(param_1,"Modulus:",*(BIGNUM **)(iVar3 + 0x10),(uchar *)0x0,param_3),
        iVar1 != 0)) &&
       (iVar1 = ASN1_bn_print(param_1,"Exponent:",*(BIGNUM **)(iVar3 + 0x14),(uchar *)0x0,param_3),
       iVar1 != 0)) {
      if (**(int **)(param_2 + 0xc) != 0x390) {
        return 1;
      }
      iVar3 = rsa_pss_param_print(param_1,1,*(undefined4 *)(iVar3 + 0x34),param_3);
      if (iVar3 == 0) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}


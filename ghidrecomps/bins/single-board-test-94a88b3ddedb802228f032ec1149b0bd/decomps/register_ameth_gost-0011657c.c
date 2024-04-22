
undefined4
register_ameth_gost(int param_1,EVP_PKEY_ASN1_METHOD **param_2,char *param_3,char *param_4)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  pub_decode *pub_decode;
  pub_encode *pub_encode;
  pub_cmp *pub_cmp;
  pub_print *pub_print;
  
  pEVar1 = EVP_PKEY_asn1_new(param_1,4,param_3,param_4);
  *param_2 = pEVar1;
  if (pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return 0;
  }
  if (param_1 == 0x32c) {
    EVP_PKEY_asn1_set_free(pEVar1,DAT_00116690);
    EVP_PKEY_asn1_set_private(*param_2,DAT_00116650,DAT_00116654,DAT_00116694);
    EVP_PKEY_asn1_set_param
              (*param_2,DAT_001166a4,DAT_001166a8,DAT_001166ac,DAT_00116698,DAT_0011669c,
               DAT_001166a0);
    pEVar1 = *param_2;
    pub_decode = DAT_001166b4;
    pub_encode = DAT_001166b8;
    pub_cmp = DAT_001166bc;
    pub_print = DAT_001166b0;
  }
  else {
    if (param_1 == 0x32f) {
      EVP_PKEY_asn1_set_free(pEVar1,DAT_00116644);
      EVP_PKEY_asn1_set_ctrl(*param_2,DAT_00116648);
      return 1;
    }
    if (param_1 != 0x32b) {
      return 1;
    }
    EVP_PKEY_asn1_set_free(pEVar1,DAT_0011664c);
    EVP_PKEY_asn1_set_private(*param_2,DAT_00116650,DAT_00116654,DAT_00116658);
    EVP_PKEY_asn1_set_param
              (*param_2,DAT_00116668,DAT_0011666c,DAT_00116670,DAT_0011665c,DAT_00116660,
               DAT_00116664);
    pEVar1 = *param_2;
    pub_decode = DAT_00116680;
    pub_encode = DAT_00116684;
    pub_cmp = DAT_00116688;
    pub_print = DAT_00116674;
  }
  EVP_PKEY_asn1_set_public(pEVar1,pub_decode,pub_encode,pub_cmp,pub_print,DAT_00116678,DAT_0011667c)
  ;
  EVP_PKEY_asn1_set_ctrl(*param_2,DAT_0011668c);
  return 1;
}



undefined4 register_ameth_gost(int param_1,undefined4 *param_2,char *param_3,char *param_4)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  code *pub_decode;
  code *pub_encode;
  code *pub_cmp;
  code *pub_print;
  
  pEVar1 = EVP_PKEY_asn1_new(param_1,4,param_3,param_4);
  *param_2 = pEVar1;
  if (pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return 0;
  }
  if (param_1 == 0x32c) {
    EVP_PKEY_asn1_set_free(pEVar1,(pkey_free *)0x115b51);
    EVP_PKEY_asn1_set_private
              ((EVP_PKEY_ASN1_METHOD *)*param_2,(priv_decode *)0x1159f5,(priv_encode *)0x116311,
               (priv_print *)0x115d7d);
    EVP_PKEY_asn1_set_param
              ((EVP_PKEY_ASN1_METHOD *)*param_2,(param_decode *)0x1157a9,(param_encode *)0x115b5d,
               (param_missing *)0x11533d,(param_copy *)0x115935,(param_cmp *)0x115859,
               (param_print *)0x116425);
    pEVar1 = (EVP_PKEY_ASN1_METHOD *)*param_2;
    pub_print = (code *)0x1164d5;
    pub_decode = (code *)0x11587d;
    pub_encode = (code *)0x116245;
    pub_cmp = (code *)0x115819;
  }
  else {
    if (param_1 == 0x32f) {
      EVP_PKEY_asn1_set_free(pEVar1,(pkey_free *)0x115331);
      EVP_PKEY_asn1_set_ctrl((EVP_PKEY_ASN1_METHOD *)*param_2,(pkey_ctrl *)0x11531d);
      return 1;
    }
    if (param_1 != 0x32b) {
      return 1;
    }
    EVP_PKEY_asn1_set_free(pEVar1,(pkey_free *)0x11580d);
    EVP_PKEY_asn1_set_private
              ((EVP_PKEY_ASN1_METHOD *)*param_2,(priv_decode *)0x1159f5,(priv_encode *)0x116311,
               (priv_print *)0x115d75);
    EVP_PKEY_asn1_set_param
              ((EVP_PKEY_ASN1_METHOD *)*param_2,(param_decode *)0x115745,(param_encode *)0x115725,
               (param_missing *)0x115355,(param_copy *)0x115641,(param_cmp *)0x115371,
               (param_print *)0x116499);
    pEVar1 = (EVP_PKEY_ASN1_METHOD *)*param_2;
    pub_print = (code *)0x115d6d;
    pub_decode = (code *)0x1154f9;
    pub_encode = (code *)0x115fa1;
    pub_cmp = (code *)0x115399;
  }
  EVP_PKEY_asn1_set_public
            (pEVar1,pub_decode,pub_encode,pub_cmp,pub_print,(pkey_size *)0x115311,
             (pkey_bits *)0x115315);
  EVP_PKEY_asn1_set_ctrl((EVP_PKEY_ASN1_METHOD *)*param_2,(pkey_ctrl *)0x116155);
  return 1;
}


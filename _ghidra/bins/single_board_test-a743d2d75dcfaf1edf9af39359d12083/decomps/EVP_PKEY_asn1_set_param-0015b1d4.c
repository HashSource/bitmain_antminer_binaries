
void EVP_PKEY_asn1_set_param
               (EVP_PKEY_ASN1_METHOD *ameth,param_decode *param_decode,param_encode *param_encode,
               param_missing *param_missing,param_copy *param_copy,param_cmp *param_cmp,
               param_print *param_print)

{
  *(param_decode **)(ameth + 0x38) = param_decode;
  *(param_encode **)(ameth + 0x3c) = param_encode;
  *(param_missing **)(ameth + 0x40) = param_missing;
  *(param_copy **)(ameth + 0x44) = param_copy;
  *(param_cmp **)(ameth + 0x48) = param_cmp;
  *(param_print **)(ameth + 0x4c) = param_print;
  return;
}


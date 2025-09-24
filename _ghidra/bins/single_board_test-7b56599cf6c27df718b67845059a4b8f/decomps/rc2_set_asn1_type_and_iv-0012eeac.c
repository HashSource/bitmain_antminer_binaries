
int rc2_set_asn1_type_and_iv(EVP_CIPHER_CTX *param_1,ASN1_TYPE *param_2)

{
  int iVar1;
  uchar *data;
  long num;
  int local_1c [2];
  
  if (param_2 == (ASN1_TYPE *)0x0) {
    return 0;
  }
  iVar1 = EVP_CIPHER_CTX_ctrl(param_1,2,0,local_1c);
  if (iVar1 < 1) {
    num = 0;
  }
  else if (local_1c[0] == 0x80) {
    num = 0x3a;
  }
  else if (local_1c[0] == 0x40) {
    num = 0x78;
  }
  else if (local_1c[0] == 0x28) {
    num = 0xa0;
  }
  else {
    num = 0;
  }
  iVar1 = EVP_CIPHER_CTX_iv_length(param_1);
  data = (uchar *)EVP_CIPHER_CTX_original_iv(param_1);
  iVar1 = ASN1_TYPE_set_int_octetstring(param_2,num,data,iVar1);
  return iVar1;
}



int rc2_set_asn1_type_and_iv(EVP_CIPHER_CTX *param_1,ASN1_TYPE *param_2)

{
  int iVar1;
  long num;
  int local_14;
  
  if (param_2 == (ASN1_TYPE *)0x0) {
    iVar1 = 0;
  }
  else {
    EVP_CIPHER_CTX_ctrl(param_1,2,0,&local_14);
    if (local_14 == 0x80) {
      num = 0x3a;
    }
    else if (local_14 == 0x40) {
      num = 0x78;
    }
    else if (local_14 == 0x28) {
      num = 0xa0;
    }
    else {
      num = 0;
    }
    iVar1 = EVP_CIPHER_CTX_iv_length(param_1);
    iVar1 = ASN1_TYPE_set_int_octetstring(param_2,num,param_1->oiv,iVar1);
  }
  return iVar1;
}



uint rc2_get_asn1_type_and_iv(EVP_CIPHER_CTX *param_1,ASN1_TYPE *param_2)

{
  uint max_len;
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long local_2c;
  uchar auStack_28 [16];
  
  local_2c = 0;
  if (param_2 == (ASN1_TYPE *)0x0) {
    return 0;
  }
  max_len = EVP_CIPHER_CTX_iv_length(param_1);
  if (0x10 < max_len) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: l <= sizeof(iv)","crypto/evp/e_rc2.c",0x83);
  }
  uVar1 = ASN1_TYPE_get_int_octetstring(param_2,&local_2c,auStack_28,max_len);
  if (max_len == uVar1) {
    if (local_2c == 0x3a) {
      iVar4 = 0x10;
      iVar3 = 0x80;
    }
    else if (local_2c == 0x78) {
      iVar4 = 8;
      iVar3 = 0x40;
    }
    else {
      if (local_2c != 0xa0) {
        ERR_put_error(6,0x6d,0x6c,"crypto/evp/e_rc2.c",0x74);
        return 0xffffffff;
      }
      iVar4 = 5;
      iVar3 = 0x28;
    }
    if ((((max_len == 0) ||
         (iVar2 = EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,auStack_28,
                                    -1), iVar2 != 0)) &&
        (iVar3 = EVP_CIPHER_CTX_ctrl(param_1,3,iVar3,(void *)0x0), 0 < iVar3)) &&
       (iVar4 = EVP_CIPHER_CTX_set_key_length(param_1,iVar4), 0 < iVar4)) {
      return max_len;
    }
  }
  return 0xffffffff;
}


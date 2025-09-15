
undefined1 * rc2_get_asn1_type_and_iv(EVP_CIPHER_CTX *param_1,ASN1_TYPE *param_2)

{
  undefined1 *max_len;
  undefined1 *puVar1;
  int iVar2;
  int keylen;
  int arg;
  long local_2c;
  uchar auStack_28 [20];
  
  local_2c = 0;
  if (param_2 == (ASN1_TYPE *)0x0) {
    return (undefined1 *)0x0;
  }
  max_len = (undefined1 *)EVP_CIPHER_CTX_iv_length(param_1);
  if (&DAT_00000010 < max_len) {
    OpenSSLDie("e_rc2.c",0xb3,"l <= sizeof(iv)");
  }
  puVar1 = (undefined1 *)ASN1_TYPE_get_int_octetstring(param_2,&local_2c,auStack_28,(int)max_len);
  if (max_len == puVar1) {
    if (local_2c == 0x3a) {
      keylen = 0x10;
      arg = 0x80;
    }
    else if (local_2c == 0x78) {
      keylen = 8;
      arg = 0x40;
    }
    else {
      if (local_2c != 0xa0) {
        ERR_put_error(6,0x6d,0x6c,"e_rc2.c",0xa4);
        return (undefined1 *)0xffffffff;
      }
      keylen = 5;
      arg = 0x28;
    }
    if (((int)max_len < 1) ||
       (iVar2 = EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,auStack_28,-1
                                 ), iVar2 != 0)) {
      EVP_CIPHER_CTX_ctrl(param_1,3,arg,(void *)0x0);
      EVP_CIPHER_CTX_set_key_length(param_1,keylen);
      return max_len;
    }
  }
  return (undefined1 *)0xffffffff;
}


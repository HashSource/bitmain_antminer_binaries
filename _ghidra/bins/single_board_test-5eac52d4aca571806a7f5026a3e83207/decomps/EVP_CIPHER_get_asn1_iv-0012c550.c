
int EVP_CIPHER_get_asn1_iv(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  uint __n;
  uint uVar1;
  
  if (type == (ASN1_TYPE *)0x0) {
    return 0;
  }
  __n = EVP_CIPHER_CTX_iv_length(c);
  if (__n < 0x11) {
    uVar1 = ASN1_TYPE_get_octetstring(type,c->oiv,__n);
    if (__n == uVar1) {
      if (__n != 0) {
        memcpy(c->iv,c->oiv,__n);
      }
    }
    else {
      __n = 0xffffffff;
    }
    return __n;
  }
                    /* WARNING: Subroutine does not return */
  OPENSSL_die("assertion failed: l <= sizeof(c->iv)","crypto/evp/evp_lib.c",0x5e);
}



int EVP_CIPHER_set_asn1_iv(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  uint len;
  int iVar1;
  
  if (type == (ASN1_TYPE *)0x0) {
    return 0;
  }
  len = EVP_CIPHER_CTX_iv_length(c);
  if (len < 0x11) {
    iVar1 = ASN1_TYPE_set_octetstring(type,c->oiv,len);
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  OPENSSL_die("assertion failed: j <= sizeof(c->iv)","crypto/evp/evp_lib.c",0x6f);
}


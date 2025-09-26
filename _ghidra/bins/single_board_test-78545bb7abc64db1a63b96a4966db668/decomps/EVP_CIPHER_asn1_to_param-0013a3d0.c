
int EVP_CIPHER_asn1_to_param(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  uint uVar1;
  EVP_CIPHER *cipher;
  ulong uVar2;
  _func_1235 *p_Var3;
  
  p_Var3 = c->cipher->get_asn1_parameters;
  if (p_Var3 == (_func_1235 *)0x0) {
    if (-1 < (int)(c->cipher->flags << 0x13)) {
      uVar1 = 0xffffffff;
      goto LAB_0013a3f4;
    }
    cipher = EVP_CIPHER_CTX_cipher(c);
    uVar2 = EVP_CIPHER_flags(cipher);
    uVar1 = uVar2 & 0xf0007;
    if (uVar1 == 0x10001) goto LAB_0013a414;
    if (uVar1 < 0x10002) {
      if (uVar1 - 6 < 2) goto LAB_0013a414;
    }
    else {
      if (uVar1 == 0x10002) {
        return 1;
      }
      if (uVar1 == 0x10003) goto LAB_0013a414;
    }
    uVar1 = EVP_CIPHER_get_asn1_iv(c,type);
  }
  else {
    uVar1 = (*p_Var3)(c,type);
  }
  if (0 < (int)uVar1) {
    return uVar1;
  }
  if (uVar1 == 0xfffffffe) {
LAB_0013a414:
    ERR_put_error(6,0xcc,0x6b,"crypto/evp/evp_lib.c",0x51);
    return -1;
  }
LAB_0013a3f4:
  ERR_put_error(6,0xcc,0x7a,"crypto/evp/evp_lib.c",0x51);
  return uVar1 | (int)uVar1 >> 0x1f;
}



int EVP_CIPHER_param_to_asn1(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  uint uVar1;
  EVP_CIPHER *cipher;
  ulong uVar2;
  int iVar3;
  _func_1234 *p_Var4;
  
  p_Var4 = c->cipher->set_asn1_parameters;
  if (p_Var4 == (_func_1234 *)0x0) {
    if (-1 < (int)(c->cipher->flags << 0x13)) {
      uVar1 = 0xffffffff;
      goto LAB_0013a5cc;
    }
    cipher = EVP_CIPHER_CTX_cipher(c);
    uVar2 = EVP_CIPHER_flags(cipher);
    uVar1 = uVar2 & 0xf0007;
    if (uVar1 == 0x10001) goto LAB_0013a5ec;
    if (uVar1 < 0x10002) {
      if (uVar1 - 6 < 2) goto LAB_0013a5ec;
    }
    else {
      if (uVar1 == 0x10002) {
        iVar3 = EVP_CIPHER_CTX_nid(c);
        if (iVar3 == 0xf6) {
          ASN1_TYPE_set(type,5,(void *)0x0);
        }
        return 1;
      }
      if (uVar1 == 0x10003) goto LAB_0013a5ec;
    }
    uVar1 = EVP_CIPHER_set_asn1_iv(c,type);
  }
  else {
    uVar1 = (*p_Var4)(c,type);
  }
  if (0 < (int)uVar1) {
    return uVar1;
  }
  if (uVar1 == 0xfffffffe) {
LAB_0013a5ec:
    ERR_put_error(6,0xcd,0xe4,"crypto/evp/evp_lib.c",0x2e);
    return -1;
  }
LAB_0013a5cc:
  ERR_put_error(6,0xcd,0x7a,"crypto/evp/evp_lib.c",0x2e);
  return uVar1 | (int)uVar1 >> 0x1f;
}


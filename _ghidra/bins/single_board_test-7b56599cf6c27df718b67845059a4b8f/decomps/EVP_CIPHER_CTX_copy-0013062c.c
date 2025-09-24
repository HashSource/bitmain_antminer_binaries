
int EVP_CIPHER_CTX_copy(EVP_CIPHER_CTX *out,EVP_CIPHER_CTX *in)

{
  int iVar1;
  void *__dest;
  ulong uVar2;
  EVP_CIPHER *pEVar3;
  
  if ((in == (EVP_CIPHER_CTX *)0x0) || (in->cipher == (EVP_CIPHER *)0x0)) {
    ERR_put_error(6,0xa3,0x6f,"crypto/evp/evp_enc.c",0x2b0);
    return 0;
  }
  if ((in->engine != (ENGINE *)0x0) && (iVar1 = ENGINE_init(in->engine), iVar1 == 0)) {
    ERR_put_error(6,0xa3,0x26,"crypto/evp/evp_enc.c",0x2b6);
    return 0;
  }
  EVP_CIPHER_CTX_reset(out);
  memcpy(out,in,0x8c);
  if (in->cipher_data != (void *)0x0) {
    pEVar3 = in->cipher;
    if (pEVar3->ctx_size == 0) {
      uVar2 = pEVar3->flags;
      goto joined_r0x001306c8;
    }
    __dest = CRYPTO_malloc(pEVar3->ctx_size,"crypto/evp/evp_enc.c",0x2bf);
    out->cipher_data = __dest;
    if (__dest == (void *)0x0) {
      out->cipher = (EVP_CIPHER *)0x0;
      ERR_put_error(6,0xa3,0x41,"crypto/evp/evp_enc.c",0x2c2);
      return 0;
    }
    memcpy(__dest,in->cipher_data,in->cipher->ctx_size);
  }
  pEVar3 = in->cipher;
  uVar2 = pEVar3->flags;
joined_r0x001306c8:
  if (((int)(uVar2 << 0x15) < 0) && (iVar1 = (*pEVar3->ctrl)(in,8,0,out), iVar1 == 0)) {
    out->cipher = (EVP_CIPHER *)0x0;
    ERR_put_error(6,0xa3,0x86,"crypto/evp/evp_enc.c",0x2cb);
    return 0;
  }
  return 1;
}


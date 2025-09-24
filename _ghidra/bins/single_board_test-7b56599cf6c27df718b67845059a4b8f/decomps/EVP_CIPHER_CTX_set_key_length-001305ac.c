
int EVP_CIPHER_CTX_set_key_length(EVP_CIPHER_CTX *x,int keylen)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = x->cipher->flags;
  if (-1 < (int)(uVar2 << 0x18)) {
    if (keylen == x->key_len) {
      iVar1 = 1;
    }
    else if ((keylen < 1) || (-1 < (int)(uVar2 << 0x1c))) {
      ERR_put_error(6,0x7a,0x82,"crypto/evp/evp_enc.c",0x280);
      iVar1 = 0;
    }
    else {
      x->key_len = keylen;
      iVar1 = 1;
    }
    return iVar1;
  }
  iVar1 = EVP_CIPHER_CTX_ctrl(x,1,keylen,(void *)0x0);
  return iVar1;
}


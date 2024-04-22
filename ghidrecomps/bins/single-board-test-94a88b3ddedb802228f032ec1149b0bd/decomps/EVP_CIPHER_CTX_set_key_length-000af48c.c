
int EVP_CIPHER_CTX_set_key_length(EVP_CIPHER_CTX *x,int keylen)

{
  int iVar1;
  uint uVar2;
  _func_1236 *p_Var3;
  
  uVar2 = x->cipher->flags;
  if ((uVar2 & 0x80) == 0) {
    if (x->key_len == keylen) {
      iVar1 = 1;
    }
    else if ((keylen < 1) || (-1 < (int)(uVar2 << 0x1c))) {
      ERR_put_error(6,0x7a,0x82,DAT_000af508,0x251);
      iVar1 = 0;
    }
    else {
      x->key_len = keylen;
      iVar1 = 1;
    }
  }
  else {
    p_Var3 = x->cipher->ctrl;
    if (p_Var3 == (_func_1236 *)0x0) {
      ERR_put_error(6,0x7c,0x84,DAT_000af508,0x267);
      iVar1 = 0;
    }
    else {
      iVar1 = (*p_Var3)(x,1,keylen,(void *)0x0);
      if (iVar1 == -1) {
        ERR_put_error(6,0x7c,0x85,DAT_000af508,0x26e);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


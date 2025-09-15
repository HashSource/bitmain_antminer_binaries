
bool ssl2_enc(int param_1,int param_2)

{
  EVP_CIPHER_CTX *c;
  int iVar1;
  uint inl;
  
  iVar1 = *(int *)(param_1 + 0x54);
  if (param_2 == 0) {
    c = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    inl = *(uint *)(iVar1 + 0x40);
  }
  else {
    c = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    inl = *(uint *)(iVar1 + 0x48);
  }
  if (c != (EVP_CIPHER_CTX *)0x0) {
    if (c->cipher->block_size == 8) {
      inl = inl + 7 & 0xfffffff8;
    }
    iVar1 = EVP_Cipher(c,*(uchar **)(iVar1 + 0x58),*(uchar **)(iVar1 + 0x58),inl);
    return 0 < iVar1;
  }
  return true;
}


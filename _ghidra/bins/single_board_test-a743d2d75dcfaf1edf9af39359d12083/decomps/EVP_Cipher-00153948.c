
int EVP_Cipher(EVP_CIPHER_CTX *c,uchar *out,uchar *in,uint inl)

{
  int iVar1;
  
  iVar1 = (*c->cipher->do_cipher)(c,out,in,inl);
  return iVar1;
}



int EVP_Cipher(EVP_CIPHER_CTX *c,uchar *out,uchar *in,uint inl)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00130744. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*c->cipher->do_cipher)(c,out,in,inl);
  return iVar1;
}


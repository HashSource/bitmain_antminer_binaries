
int EVP_MD_CTX_copy(EVP_MD_CTX *out,EVP_MD_CTX *in)

{
  int iVar1;
  
  memset(out,0,0x18);
  iVar1 = EVP_MD_CTX_copy_ex(out,in);
  return iVar1;
}


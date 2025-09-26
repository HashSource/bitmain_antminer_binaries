
int EVP_MD_CTX_copy(EVP_MD_CTX *out,EVP_MD_CTX *in)

{
  int iVar1;
  
  EVP_MD_CTX_reset();
  iVar1 = EVP_MD_CTX_copy_ex(out,in);
  return iVar1;
}


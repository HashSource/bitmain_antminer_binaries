
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = SHA_Init(*(SHA_CTX **)(ctx + 0xc));
  return iVar1;
}


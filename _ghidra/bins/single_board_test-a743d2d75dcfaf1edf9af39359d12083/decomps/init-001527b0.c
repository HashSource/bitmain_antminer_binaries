
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = MD5_Init(*(MD5_CTX **)(ctx + 0xc));
  return iVar1;
}


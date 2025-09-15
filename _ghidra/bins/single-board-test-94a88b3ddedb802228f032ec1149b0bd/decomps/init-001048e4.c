
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = MD4_Init(*(MD4_CTX **)(ctx + 0xc));
  return iVar1;
}


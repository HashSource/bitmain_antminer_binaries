
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = WHIRLPOOL_Init(*(WHIRLPOOL_CTX **)(ctx + 0xc));
  return iVar1;
}


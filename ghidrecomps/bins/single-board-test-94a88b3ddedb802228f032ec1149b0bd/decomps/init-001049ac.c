
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = RIPEMD160_Init(*(RIPEMD160_CTX **)(ctx + 0xc));
  return iVar1;
}


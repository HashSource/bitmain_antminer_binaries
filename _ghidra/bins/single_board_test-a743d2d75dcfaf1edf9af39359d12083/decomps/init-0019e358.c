
int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = MDC2_Init(*(undefined4 *)(ctx + 0xc));
  return iVar1;
}



int CRYPTO_THREADID_cmp(CRYPTO_THREADID *a,CRYPTO_THREADID *b)

{
  int iVar1;
  
  iVar1 = memcmp(a,b,8);
  return iVar1;
}


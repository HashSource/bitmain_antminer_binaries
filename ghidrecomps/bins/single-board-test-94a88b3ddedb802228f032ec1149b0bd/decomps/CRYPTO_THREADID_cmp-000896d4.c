
int CRYPTO_THREADID_cmp(CRYPTO_THREADID *a,CRYPTO_THREADID *b)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_00194160)(a,b,8);
  return iVar1;
}


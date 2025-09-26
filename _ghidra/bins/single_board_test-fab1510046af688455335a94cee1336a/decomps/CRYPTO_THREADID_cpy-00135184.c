
void CRYPTO_THREADID_cpy(CRYPTO_THREADID *dest,CRYPTO_THREADID *src)

{
  ulong uVar1;
  
  uVar1 = src->val;
  dest->ptr = src->ptr;
  dest->val = uVar1;
  return;
}


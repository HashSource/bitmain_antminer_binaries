
void RAND_priv_bytes(uchar *param_1,int param_2)

{
  RAND_METHOD *pRVar1;
  RAND_METHOD *pRVar2;
  int iVar3;
  
  pRVar1 = RAND_get_rand_method();
  if ((pRVar1 != (RAND_METHOD *)0x0) && (pRVar2 = (RAND_METHOD *)RAND_OpenSSL(), pRVar1 != pRVar2))
  {
    RAND_bytes(param_1,param_2);
    return;
  }
  iVar3 = RAND_DRBG_get0_private();
  if (iVar3 != 0) {
    RAND_DRBG_bytes(iVar3,param_1,param_2);
    return;
  }
  return;
}


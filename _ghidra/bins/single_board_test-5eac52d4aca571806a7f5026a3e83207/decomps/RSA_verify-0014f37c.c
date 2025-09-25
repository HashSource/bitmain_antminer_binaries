
int RSA_verify(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  int iVar1;
  _func_1769 *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = rsa->meth->rsa_verify;
  if (UNRECOVERED_JUMPTABLE != (_func_1769 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0014f392. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(type,m,m_length,sigbuf,siglen,rsa);
    return iVar1;
  }
  iVar1 = int_rsa_verify();
  return iVar1;
}


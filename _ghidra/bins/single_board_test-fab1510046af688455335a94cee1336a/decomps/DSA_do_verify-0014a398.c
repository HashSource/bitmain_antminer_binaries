
int DSA_do_verify(uchar *dgst,int dgst_len,DSA_SIG *sig,DSA *dsa)

{
  int iVar1;
  
  iVar1 = (*dsa->meth->dsa_do_verify)(dgst,dgst_len,sig,dsa);
  return iVar1;
}


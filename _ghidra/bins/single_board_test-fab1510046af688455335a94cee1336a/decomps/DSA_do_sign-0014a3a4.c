
DSA_SIG * DSA_do_sign(uchar *dgst,int dlen,DSA *dsa)

{
  DSA_SIG *pDVar1;
  
  pDVar1 = (*dsa->meth->dsa_do_sign)(dgst,dlen,dsa);
  return pDVar1;
}


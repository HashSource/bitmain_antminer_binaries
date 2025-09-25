
DSA_SIG * DSA_do_sign(uchar *dgst,int dlen,DSA *dsa)

{
  DSA_SIG *pDVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0011533c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pDVar1 = (DSA_SIG *)(*(code *)(dsa->method_mont_p->RR).d)(dgst);
  return pDVar1;
}


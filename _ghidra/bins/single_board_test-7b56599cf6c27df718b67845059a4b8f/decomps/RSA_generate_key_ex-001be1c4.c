
int RSA_generate_key_ex(RSA *rsa,int bits,BIGNUM *e,BN_GENCB *cb)

{
  int iVar1;
  _func_1770 *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = rsa->meth->rsa_keygen;
  if (UNRECOVERED_JUMPTABLE != (_func_1770 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001be1d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(rsa,bits,e,cb);
    return iVar1;
  }
  iVar1 = RSA_generate_multi_prime_key(rsa,bits,2,e,cb);
  return iVar1;
}


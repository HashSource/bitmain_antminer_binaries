
int DSA_generate_parameters_ex
              (DSA *dsa,int bits,uchar *seed,int seed_len,int *counter_ret,ulong *h_ret,BN_GENCB *cb
              )

{
  int iVar1;
  EVP_MD *pEVar2;
  undefined4 uVar3;
  _func_1882 *p_Var4;
  
  p_Var4 = dsa->meth->dsa_paramgen;
  if (p_Var4 == (_func_1882 *)0x0) {
    if (bits < 0x800) {
      pEVar2 = EVP_sha1();
      uVar3 = 0xa0;
    }
    else {
      pEVar2 = EVP_sha256();
      uVar3 = 0x100;
    }
    iVar1 = dsa_builtin_paramgen(dsa,bits,uVar3,pEVar2,seed,seed_len,0,counter_ret,h_ret,cb);
  }
  else {
    iVar1 = (*p_Var4)(dsa,bits,seed,seed_len,counter_ret,h_ret,cb);
  }
  return iVar1;
}


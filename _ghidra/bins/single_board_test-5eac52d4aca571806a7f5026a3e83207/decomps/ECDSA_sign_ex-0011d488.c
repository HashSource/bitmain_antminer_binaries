
int ECDSA_sign_ex(int type,uchar *dgst,int dgstlen,uchar *sig,uint *siglen,BIGNUM *kinv,BIGNUM *rp,
                 EC_KEY *eckey)

{
  int iVar1;
  
  if (*(code **)(*(int *)eckey + 0x28) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011d49c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)eckey + 0x28))(type);
    return iVar1;
  }
  ERR_put_error(0x10,0xfe,0x98,"crypto/ec/ecdsa_sign.c",0x29);
  return 0;
}


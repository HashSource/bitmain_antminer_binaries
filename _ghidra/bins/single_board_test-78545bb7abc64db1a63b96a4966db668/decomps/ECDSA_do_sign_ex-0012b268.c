
ECDSA_SIG * ECDSA_do_sign_ex(uchar *dgst,int dgstlen,BIGNUM *kinv,BIGNUM *rp,EC_KEY *eckey)

{
  ECDSA_SIG *pEVar1;
  
  if (*(code **)(*(int *)eckey + 0x30) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0012b27c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pEVar1 = (ECDSA_SIG *)(**(code **)(*(int *)eckey + 0x30))(dgst);
    return pEVar1;
  }
  ERR_put_error(0x10,0xfb,0x98,"crypto/ec/ecdsa_sign.c",0x19);
  return (ECDSA_SIG *)0x0;
}


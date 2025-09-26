
ECDSA_SIG * ECDSA_do_sign_ex(uchar *dgst,int dgstlen,BIGNUM *kinv,BIGNUM *rp,EC_KEY *eckey)

{
  ECDSA_SIG *pEVar1;
  
  pEVar1 = (ECDSA_SIG *)ecdsa_check(eckey);
  if (pEVar1 != (ECDSA_SIG *)0x0) {
    pEVar1 = (ECDSA_SIG *)(*(code *)(pEVar1[1].s)->top)(dgst,dgstlen,kinv,rp,eckey);
  }
  return pEVar1;
}


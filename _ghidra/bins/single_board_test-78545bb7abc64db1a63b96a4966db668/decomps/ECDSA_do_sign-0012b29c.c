
ECDSA_SIG * ECDSA_do_sign(uchar *dgst,int dgst_len,EC_KEY *eckey)

{
  ECDSA_SIG *pEVar1;
  
  pEVar1 = ECDSA_do_sign_ex(dgst,dgst_len,(BIGNUM *)0x0,(BIGNUM *)0x0,eckey);
  return pEVar1;
}


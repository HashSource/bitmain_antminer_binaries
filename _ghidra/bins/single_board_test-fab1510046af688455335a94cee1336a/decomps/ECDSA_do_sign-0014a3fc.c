
ECDSA_SIG * ECDSA_do_sign(uchar *dgst,int dgst_len,EC_KEY *eckey)

{
  ECDSA_SIG *pEVar1;
  
  pEVar1 = (ECDSA_SIG *)ecdsa_check(eckey);
  if (pEVar1 != (ECDSA_SIG *)0x0) {
    pEVar1 = (ECDSA_SIG *)(*(code *)(pEVar1[1].s)->top)(dgst,dgst_len,0,0,eckey);
  }
  return pEVar1;
}


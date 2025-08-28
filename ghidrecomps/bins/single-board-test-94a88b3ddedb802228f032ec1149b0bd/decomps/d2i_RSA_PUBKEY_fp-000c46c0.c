
RSA * d2i_RSA_PUBKEY_fp(FILE *fp,RSA **rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_d2i_fp((xnew *)0xa3c65,(undefined1 *)0xb6e35,fp,rsa);
  return pRVar1;
}


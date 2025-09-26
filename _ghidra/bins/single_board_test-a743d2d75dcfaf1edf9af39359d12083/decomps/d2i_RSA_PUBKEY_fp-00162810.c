
RSA * d2i_RSA_PUBKEY_fp(FILE *fp,RSA **rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_d2i_fp((xnew *)0x146ba1,(undefined1 *)0x156bf1,fp,rsa);
  return pRVar1;
}


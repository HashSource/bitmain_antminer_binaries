
RSA * d2i_RSA_PUBKEY_bio(BIO *bp,RSA **rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_d2i_bio((xnew *)0x146ba1,(undefined1 *)0x156bf1,bp,rsa);
  return pRVar1;
}



RSA * d2i_RSA_PUBKEY_bio(BIO *bp,RSA **rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_d2i_bio((xnew *)0xa3c65,(undefined1 *)0xb6e35,bp,rsa);
  return pRVar1;
}


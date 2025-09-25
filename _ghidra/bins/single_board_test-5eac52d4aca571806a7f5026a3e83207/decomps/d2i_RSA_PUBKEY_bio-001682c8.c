
RSA * d2i_RSA_PUBKEY_bio(BIO *bp,RSA **rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_d2i_bio((xnew *)0x14bef1,(undefined1 *)0x169e69,bp,rsa);
  return pRVar1;
}


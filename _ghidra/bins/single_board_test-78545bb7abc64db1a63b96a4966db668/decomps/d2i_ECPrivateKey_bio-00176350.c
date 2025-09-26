
EC_KEY * d2i_ECPrivateKey_bio(BIO *bp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)ASN1_d2i_bio((xnew *)0x126e09,(undefined1 *)0x125db5,bp,eckey);
  return pEVar1;
}


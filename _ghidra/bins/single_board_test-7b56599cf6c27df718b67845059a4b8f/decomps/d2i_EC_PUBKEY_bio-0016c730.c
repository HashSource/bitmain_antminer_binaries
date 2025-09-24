
EC_KEY * d2i_EC_PUBKEY_bio(BIO *bp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)ASN1_d2i_bio((xnew *)0x11d231,(undefined1 *)0x16e1dd,bp,eckey);
  return pEVar1;
}


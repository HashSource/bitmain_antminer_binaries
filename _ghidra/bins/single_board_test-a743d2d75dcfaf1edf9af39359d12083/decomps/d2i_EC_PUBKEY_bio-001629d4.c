
EC_KEY * d2i_EC_PUBKEY_bio(BIO *bp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)ASN1_d2i_bio((xnew *)0x14603d,(undefined1 *)0x156d75,bp,eckey);
  return pEVar1;
}


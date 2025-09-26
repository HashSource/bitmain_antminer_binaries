
EC_KEY * d2i_ECPrivateKey_fp(FILE *fp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)ASN1_d2i_fp((xnew *)0x126e09,(undefined1 *)0x125db5,fp,eckey);
  return pEVar1;
}


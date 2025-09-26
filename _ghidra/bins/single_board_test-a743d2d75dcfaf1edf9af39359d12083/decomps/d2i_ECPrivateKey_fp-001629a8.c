
EC_KEY * d2i_ECPrivateKey_fp(FILE *fp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)ASN1_d2i_fp((xnew *)0x14603d,(undefined1 *)0x18e379,fp,eckey);
  return pEVar1;
}


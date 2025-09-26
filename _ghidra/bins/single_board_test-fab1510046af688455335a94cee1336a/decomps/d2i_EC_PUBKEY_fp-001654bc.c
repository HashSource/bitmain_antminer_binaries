
EC_KEY * d2i_EC_PUBKEY_fp(FILE *fp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)ASN1_d2i_fp((xnew *)0x148b7d,(undefined1 *)0x1598b5,fp,eckey);
  return pEVar1;
}



EC_KEY * o2i_ECPublicKey(EC_KEY **key,uchar **in,long len)

{
  int iVar1;
  EC_KEY *pEVar2;
  
  if (((key == (EC_KEY **)0x0) || (pEVar2 = *key, pEVar2 == (EC_KEY *)0x0)) ||
     (*(int *)(pEVar2 + 0xc) == 0)) {
    pEVar2 = (EC_KEY *)0x0;
    ERR_put_error(0x10,0x98,0x43,"crypto/ec/ec_asn1.c",0x4b5);
  }
  else {
    iVar1 = EC_KEY_oct2key(pEVar2,*in,len,0);
    if (iVar1 == 0) {
      ERR_put_error(0x10,0x98,0x10,"crypto/ec/ec_asn1.c",0x4ba);
      pEVar2 = (EC_KEY *)0x0;
    }
    else {
      *in = *in + len;
    }
  }
  return pEVar2;
}


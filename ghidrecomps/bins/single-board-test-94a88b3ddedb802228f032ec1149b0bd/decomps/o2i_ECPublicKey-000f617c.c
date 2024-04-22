
EC_KEY * o2i_ECPublicKey(EC_KEY **key,uchar **in,long len)

{
  EC_GROUP *group;
  int iVar1;
  byte *pbVar2;
  EC_KEY *pEVar3;
  EC_POINT *p;
  
  if (((key == (EC_KEY **)0x0) || (pEVar3 = *key, pEVar3 == (EC_KEY *)0x0)) ||
     (group = *(EC_GROUP **)(pEVar3 + 4), group == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,0x98,0x43,DAT_000f620c,0x4f3);
    pEVar3 = (EC_KEY *)0x0;
  }
  else {
    p = *(EC_POINT **)(pEVar3 + 8);
    if (p == (EC_POINT *)0x0) {
      p = EC_POINT_new(group);
      *(EC_POINT **)(pEVar3 + 8) = p;
      if (p == (EC_POINT *)0x0) {
        ERR_put_error(0x10,0x98,0x41,DAT_000f620c,0x4f9);
        return (EC_KEY *)0x0;
      }
      group = *(EC_GROUP **)(pEVar3 + 4);
    }
    iVar1 = EC_POINT_oct2point(group,p,*in,len,(BN_CTX *)0x0);
    if (iVar1 == 0) {
      ERR_put_error(0x10,0x98,0x10,DAT_000f620c,0x4fd);
      pEVar3 = (EC_KEY *)0x0;
    }
    else {
      pbVar2 = *in;
      *(uint *)(pEVar3 + 0x14) = *pbVar2 & 0xfffffffe;
      *in = pbVar2 + len;
    }
  }
  return pEVar3;
}


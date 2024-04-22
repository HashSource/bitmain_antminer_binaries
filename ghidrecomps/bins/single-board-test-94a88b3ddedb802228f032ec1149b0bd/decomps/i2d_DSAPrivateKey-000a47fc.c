
int i2d_DSAPrivateKey(DSA *a,uchar **pp)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,pp,DAT_000a4804);
  return iVar1;
}


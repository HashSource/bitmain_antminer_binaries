
int i2d_DHparams(DH *a,uchar **pp)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,pp,(ASN1_ITEM *)&DHparams_it);
  return iVar1;
}


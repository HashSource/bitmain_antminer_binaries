
int i2d_DIRECTORYSTRING(ASN1_STRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbe6c);
  return iVar1;
}


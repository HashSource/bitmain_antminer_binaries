
int i2d_PKCS12_SAFEBAG(PKCS12_SAFEBAG *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d1334);
  return iVar1;
}


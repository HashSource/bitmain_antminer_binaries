
int i2d_RSA_PSS_PARAMS(RSA_PSS_PARAMS *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&RSA_PSS_PARAMS_it);
  return iVar1;
}


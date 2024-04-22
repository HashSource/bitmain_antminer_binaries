
int i2d_PROXY_POLICY(PROXY_POLICY *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&PROXY_POLICY_it);
  return iVar1;
}


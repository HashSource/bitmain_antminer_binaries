
int i2d_PROXY_CERT_INFO_EXTENSION(PROXY_CERT_INFO_EXTENSION *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PROXY_CERT_INFO_EXTENSION_it);
  return iVar1;
}


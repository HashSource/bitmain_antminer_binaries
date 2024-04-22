
int SXNET_add_id_ulong(SXNET **psx,ulong lzone,char *user,int userlen)

{
  ASN1_STRING *a;
  int iVar1;
  
  a = ASN1_STRING_type_new(2);
  if ((a != (ASN1_STRING *)0x0) && (iVar1 = ASN1_INTEGER_set(a,lzone), iVar1 != 0)) {
    iVar1 = SXNET_add_id_INTEGER(psx,a,user,userlen);
    return iVar1;
  }
  ERR_put_error(0x22,0x7f,0x41,DAT_000c9bd0,0xaa);
  ASN1_STRING_free(a);
  return 0;
}


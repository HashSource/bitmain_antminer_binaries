
int SXNET_add_id_ulong(SXNET **psx,ulong lzone,char *user,int userlen)

{
  ASN1_INTEGER *a;
  int iVar1;
  
  a = ASN1_INTEGER_new();
  if ((a != (ASN1_INTEGER *)0x0) && (iVar1 = ASN1_INTEGER_set(a,lzone), iVar1 != 0)) {
    iVar1 = SXNET_add_id_INTEGER(psx,a,user,userlen);
    return iVar1;
  }
  ERR_put_error(0x22,0x7f,0x41,"crypto/x509v3/v3_sxnet.c",0x8a);
  ASN1_INTEGER_free(a);
  return 0;
}


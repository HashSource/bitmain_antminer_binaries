
int SXNET_add_id_INTEGER(SXNET **psx,ASN1_INTEGER *izone,char *user,int userlen)

{
  ASN1_OCTET_STRING *pAVar1;
  SXNETID *a;
  int iVar2;
  SXNET *sx;
  
  if (psx == (SXNET **)0x0 || (user == (char *)0x0 || izone == (ASN1_INTEGER *)0x0)) {
    ERR_put_error(0x22,0x7e,0x6b,"crypto/x509v3/v3_sxnet.c",0x9e);
    return 0;
  }
  if (userlen == -1) {
    userlen = strlen(user);
    if (0x40 < userlen) goto LAB_001790ae;
  }
  else if (0x40 < userlen) {
LAB_001790ae:
    ERR_put_error(0x22,0x7e,0x84,"crypto/x509v3/v3_sxnet.c",0xa4);
    return 0;
  }
  sx = *psx;
  if (sx == (SXNET *)0x0) {
    sx = SXNET_new();
    if (sx == (SXNET *)0x0) {
      a = (SXNETID *)0x0;
      goto LAB_00179062;
    }
    iVar2 = ASN1_INTEGER_set(sx->version,0);
    if (iVar2 == 0) {
      a = (SXNETID *)0x0;
      goto LAB_00179062;
    }
    *psx = sx;
  }
  pAVar1 = SXNET_get_id_INTEGER(sx,izone);
  if (pAVar1 != (ASN1_OCTET_STRING *)0x0) {
    ERR_put_error(0x22,0x7e,0x85,"crypto/x509v3/v3_sxnet.c",0xb0);
    return 0;
  }
  a = SXNETID_new();
  if (a != (SXNETID *)0x0) {
    if (userlen == 0xffffffff) {
      userlen = strlen(user);
    }
    iVar2 = ASN1_OCTET_STRING_set(a->user,user,userlen);
    if ((iVar2 != 0) && (iVar2 = OPENSSL_sk_push(sx->ids,a), iVar2 != 0)) {
      a->zone = izone;
      return 1;
    }
  }
LAB_00179062:
  ERR_put_error(0x22,0x7e,0x41,"crypto/x509v3/v3_sxnet.c",0xc1);
  SXNETID_free(a);
  SXNET_free(sx);
  *psx = (SXNET *)0x0;
  return 0;
}


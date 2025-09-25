
int OCSP_check_nonce(OCSP_REQUEST *req,OCSP_BASICRESP *bs)

{
  uint loc;
  uint loc_00;
  X509_EXTENSION *ne;
  X509_EXTENSION *ne_00;
  ASN1_OCTET_STRING *a;
  ASN1_OCTET_STRING *b;
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  loc = OCSP_REQUEST_get_ext_by_NID(req,0x16e,-1);
  loc_00 = OCSP_BASICRESP_get_ext_by_NID(bs,0x16e,-1);
  uVar2 = loc >> 0x1f;
  uVar3 = loc_00 >> 0x1f;
  if ((int)(loc & loc_00) < 0) {
    return 2;
  }
  if ((int)loc < 0) {
    uVar3 = 0;
  }
  if (uVar3 == 0) {
    if ((int)loc_00 < 0) {
      uVar2 = 0;
    }
    if (uVar2 != 0) {
      return 3;
    }
    ne = OCSP_REQUEST_get_ext(req,loc);
    ne_00 = OCSP_BASICRESP_get_ext(bs,loc_00);
    a = X509_EXTENSION_get_data(ne);
    b = X509_EXTENSION_get_data(ne_00);
    iVar1 = ASN1_OCTET_STRING_cmp(a,b);
    return (uint)(iVar1 == 0);
  }
  return -1;
}


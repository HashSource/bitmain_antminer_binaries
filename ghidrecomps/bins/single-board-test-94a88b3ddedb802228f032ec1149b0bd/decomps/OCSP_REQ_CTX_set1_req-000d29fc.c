
int OCSP_REQ_CTX_set1_req(OCSP_REQ_CTX *rctx,OCSP_REQUEST *req)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)req,(uchar **)0x0,(ASN1_ITEM *)OCSP_REQUEST_it);
  iVar1 = BIO_printf(*(BIO **)(rctx + 0x10),
                     "Content-Type: application/ocsp-request\r\nContent-Length: %d\r\n\r\n",iVar1);
  if ((0 < iVar1) &&
     (iVar1 = ASN1_item_i2d_bio((ASN1_ITEM *)OCSP_REQUEST_it,*(BIO **)(rctx + 0x10),req), 0 < iVar1)
     ) {
    *(undefined4 *)rctx = 0x1005;
    return 1;
  }
  return 0;
}



int OCSP_request_sign(OCSP_REQUEST *req,X509 *signer,EVP_PKEY *key,EVP_MD *dgst,stack_st_X509 *certs
                     ,ulong flags)

{
  X509_NAME *nm;
  int iVar1;
  OCSP_REQINFO *a;
  int iVar2;
  X509 *cert;
  
  nm = X509_get_subject_name(signer);
  iVar1 = OCSP_request_set1_name(req,nm);
  if (iVar1 != 0) {
    a = (OCSP_REQINFO *)OCSP_SIGNATURE_new();
    req[2].tbsRequest = a;
    if (a == (OCSP_REQINFO *)0x0) goto LAB_0014d596;
    if (key != (EVP_PKEY *)0x0) {
      iVar1 = X509_check_private_key(signer,key);
      if (iVar1 == 0) {
        ERR_put_error(0x27,0x6e,0x6e,"crypto/ocsp/ocsp_cl.c",0x71);
        a = req[2].tbsRequest;
        goto LAB_0014d596;
      }
      iVar1 = ASN1_item_sign((ASN1_ITEM *)OCSP_REQINFO_it,(X509_ALGOR *)req[2].tbsRequest,
                             (X509_ALGOR *)0x0,(ASN1_BIT_STRING *)(req[2].tbsRequest)->requestList,
                             req,key,dgst);
      if (iVar1 == 0) goto LAB_0014d5ba;
    }
    if ((flags & 1) != 0) {
      return 1;
    }
    iVar2 = OCSP_request_add1_cert(req,signer);
    iVar1 = 0;
    while (iVar2 != 0) {
      iVar2 = OPENSSL_sk_num(certs);
      if (iVar2 <= iVar1) {
        return 1;
      }
      cert = (X509 *)OPENSSL_sk_value(certs,iVar1);
      iVar2 = OCSP_request_add1_cert(req,cert);
      iVar1 = iVar1 + 1;
    }
  }
LAB_0014d5ba:
  a = req[2].tbsRequest;
LAB_0014d596:
  OCSP_SIGNATURE_free((OCSP_SIGNATURE *)a);
  req[2].tbsRequest = (OCSP_REQINFO *)0x0;
  return 0;
}


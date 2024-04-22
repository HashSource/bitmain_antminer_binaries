
int OCSP_request_verify(OCSP_REQUEST *req,stack_st_X509 *certs,X509_STORE *store,ulong flags)

{
  int iVar1;
  X509 *x;
  char *pcVar2;
  EVP_PKEY *pkey;
  OCSP_SIGNATURE *chain;
  GENERAL_NAME *pGVar3;
  X509_NAME *name;
  bool bVar4;
  X509_STORE_CTX XStack_a8;
  
  if (req->optionalSignature == (OCSP_SIGNATURE *)0x0) {
    ERR_put_error(0x27,0x74,0x80,DAT_000d41c0,0x17b);
    iVar1 = 0;
  }
  else {
    pGVar3 = req->tbsRequest->requestorName;
    if ((pGVar3 == (GENERAL_NAME *)0x0) || (pGVar3->type != 4)) {
      ERR_put_error(0x27,0x74,0x81,DAT_000d41c0,0x181);
      iVar1 = 0;
    }
    else {
      name = (pGVar3->d).directoryName;
      if (((int)(flags << 0x1e) < 0) ||
         (x = X509_find_by_subject(req->optionalSignature->certs,name), x == (X509 *)0x0)) {
        x = X509_find_by_subject(certs,name);
        if (x == (X509 *)0x0) {
          ERR_put_error(0x27,0x74,0x76,DAT_000d41c0,0x188);
          return 0;
        }
        if ((int)(flags << 0x16) < 0) {
          flags = flags | 0x10;
        }
      }
      if ((flags & 4) == 0) {
        pkey = X509_get_pubkey(x);
        iVar1 = ASN1_item_verify(DAT_000d41c8,req->optionalSignature->signatureAlgorithm,
                                 req->optionalSignature->signature,req->tbsRequest,pkey);
        EVP_PKEY_free(pkey);
        if (iVar1 < 1) {
          ERR_put_error(0x27,0x74,0x75,DAT_000d41c0,0x193);
          return 0;
        }
      }
      if ((flags & 0x10) == 0) {
        bVar4 = (int)(flags << 0x1c) < 0;
        chain = (OCSP_SIGNATURE *)0x0;
        if (!bVar4) {
          chain = req->optionalSignature;
        }
        if (bVar4) {
          req = (OCSP_REQUEST *)&XStack_a8;
        }
        if (!bVar4) {
          chain = (OCSP_SIGNATURE *)chain->certs;
          req = (OCSP_REQUEST *)&XStack_a8;
        }
        iVar1 = X509_STORE_CTX_init((X509_STORE_CTX *)req,store,x,(stack_st_X509 *)chain);
        if (iVar1 == 0) {
          ERR_put_error(0x27,0x74,0xb,DAT_000d41c0,0x19f);
          return 0;
        }
        X509_STORE_CTX_set_purpose((X509_STORE_CTX *)req,8);
        X509_STORE_CTX_set_trust((X509_STORE_CTX *)req,7);
        iVar1 = X509_verify_cert((X509_STORE_CTX *)req);
        X509_STORE_CTX_cleanup((X509_STORE_CTX *)req);
        if (iVar1 < 1) {
          iVar1 = X509_STORE_CTX_get_error((X509_STORE_CTX *)req);
          ERR_put_error(0x27,0x74,0x65,DAT_000d41c0,0x1aa);
          pcVar2 = X509_verify_cert_error_string(iVar1);
          ERR_add_error_data(2,DAT_000d41c4,pcVar2);
          return 0;
        }
      }
      iVar1 = 1;
    }
  }
  return iVar1;
}


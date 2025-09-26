
X509_REQ * X509_to_X509_REQ(X509 *x,EVP_PKEY *pkey,EVP_MD *md)

{
  X509_REQ *req;
  void *pvVar1;
  X509_NAME *name;
  EVP_PKEY *pkey_00;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  
  req = X509_REQ_new();
  if (req == (X509_REQ *)0x0) {
    ERR_put_error(0xb,0x7e,0x41,"crypto/x509/x509_req.c",0x1f);
  }
  else {
    puVar4 = (undefined4 *)req->references;
    *puVar4 = 1;
    pvVar1 = CRYPTO_malloc(1,"crypto/x509/x509_req.c",0x26);
    iVar2 = req->references;
    puVar4[2] = pvVar1;
    puVar3 = *(undefined1 **)(iVar2 + 8);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0;
      name = X509_get_subject_name(x);
      iVar2 = X509_REQ_set_subject_name(req,name);
      if ((((iVar2 != 0) && (pkey_00 = (EVP_PKEY *)X509_get0_pubkey(x), pkey_00 != (EVP_PKEY *)0x0))
          && (iVar2 = X509_REQ_set_pubkey(req,pkey_00), iVar2 != 0)) &&
         ((pkey == (EVP_PKEY *)0x0 || (iVar2 = X509_REQ_sign(req,pkey,md), iVar2 != 0)))) {
        return req;
      }
    }
  }
  X509_REQ_free(req);
  return (X509_REQ *)0x0;
}


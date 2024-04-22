
X509_REQ * X509_to_X509_REQ(X509 *x,EVP_PKEY *pkey,EVP_MD *md)

{
  char *file;
  X509_REQ *req;
  uchar *puVar1;
  X509_NAME *name;
  int iVar2;
  EVP_PKEY *pkey_00;
  ASN1_INTEGER *pAVar3;
  ASN1_INTEGER *pAVar4;
  X509_REQ_INFO *pXVar5;
  
  req = X509_REQ_new();
  file = DAT_0010b4bc;
  if (req == (X509_REQ *)0x0) {
    ERR_put_error(0xb,0x7e,0x41,DAT_0010b4bc,0x4f);
  }
  else {
    pXVar5 = req->req_info;
    pAVar4 = pXVar5->version;
    pAVar4->length = 1;
    puVar1 = (uchar *)CRYPTO_malloc(1,file,0x56);
    pAVar3 = pXVar5->version;
    pAVar4->data = puVar1;
    puVar1 = pAVar3->data;
    if (puVar1 != (uchar *)0x0) {
      *puVar1 = '\0';
      name = X509_get_subject_name(x);
      iVar2 = X509_REQ_set_subject_name(req,name);
      if ((iVar2 != 0) && (pkey_00 = X509_get_pubkey(x), pkey_00 != (EVP_PKEY *)0x0)) {
        iVar2 = X509_REQ_set_pubkey(req,pkey_00);
        EVP_PKEY_free(pkey_00);
        if (iVar2 != 0) {
          if (pkey == (EVP_PKEY *)0x0) {
            return req;
          }
          iVar2 = X509_REQ_sign(req,pkey,md);
          if (iVar2 != 0) {
            return req;
          }
        }
      }
    }
  }
  X509_REQ_free(req);
  return (X509_REQ *)0x0;
}


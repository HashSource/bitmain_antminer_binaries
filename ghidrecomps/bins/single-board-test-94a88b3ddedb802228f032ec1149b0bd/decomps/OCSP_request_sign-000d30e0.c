
int OCSP_request_sign(OCSP_REQUEST *req,X509 *signer,EVP_PKEY *key,EVP_MD *dgst,stack_st_X509 *certs
                     ,ulong flags)

{
  X509_NAME *name;
  GENERAL_NAME *a;
  int iVar1;
  OCSP_SIGNATURE *a_00;
  _STACK *p_Var2;
  int iVar3;
  void *data;
  OCSP_REQINFO *pOVar4;
  
  name = X509_get_subject_name(signer);
  a = GENERAL_NAME_new();
  if (a != (GENERAL_NAME *)0x0) {
    iVar1 = X509_NAME_set(&(a->d).directoryName,name);
    if (iVar1 == 0) {
      GENERAL_NAME_free(a);
    }
    else {
      pOVar4 = req->tbsRequest;
      a->type = 4;
      if (pOVar4->requestorName != (GENERAL_NAME *)0x0) {
        GENERAL_NAME_free(pOVar4->requestorName);
        pOVar4 = req->tbsRequest;
      }
      pOVar4->requestorName = a;
      a_00 = OCSP_SIGNATURE_new();
      req->optionalSignature = a_00;
      if (a_00 == (OCSP_SIGNATURE *)0x0) goto LAB_000d3148;
      if (key != (EVP_PKEY *)0x0) {
        iVar1 = X509_check_private_key(signer,key);
        if (iVar1 == 0) {
          ERR_put_error(0x27,0x6e,0x6e,DAT_000d3224,0xa8);
          a_00 = req->optionalSignature;
          goto LAB_000d3148;
        }
        iVar1 = ASN1_item_sign(DAT_000d3228,req->optionalSignature->signatureAlgorithm,
                               (X509_ALGOR *)0x0,req->optionalSignature->signature,req->tbsRequest,
                               key,dgst);
        if (iVar1 == 0) goto LAB_000d315c;
      }
      if ((int)(flags << 0x1f) < 0) {
        return 1;
      }
      a_00 = req->optionalSignature;
      if (a_00 == (OCSP_SIGNATURE *)0x0) {
        a_00 = OCSP_SIGNATURE_new();
        req->optionalSignature = a_00;
        if (a_00 == (OCSP_SIGNATURE *)0x0) goto LAB_000d3148;
      }
      if (signer == (X509 *)0x0) goto LAB_000d31aa;
      p_Var2 = &a_00->certs->stack;
      if (p_Var2 == (_STACK *)0x0) {
        p_Var2 = sk_new_null();
        a_00->certs = (stack_st_X509 *)p_Var2;
        if (p_Var2 == (_STACK *)0x0) goto LAB_000d315c;
      }
      iVar1 = sk_push(p_Var2,signer);
      if (iVar1 != 0) {
        CRYPTO_add_lock(&signer->references,1,3,DAT_000d3224,0x8c);
LAB_000d31aa:
        iVar1 = 0;
        do {
          iVar3 = sk_num(&certs->stack);
          if (iVar3 <= iVar1) {
            return 1;
          }
          data = sk_value(&certs->stack,iVar1);
          a_00 = req->optionalSignature;
          if (a_00 == (OCSP_SIGNATURE *)0x0) {
            a_00 = OCSP_SIGNATURE_new();
            req->optionalSignature = a_00;
            if (a_00 == (OCSP_SIGNATURE *)0x0) goto LAB_000d3148;
          }
          if (data != (void *)0x0) {
            p_Var2 = &a_00->certs->stack;
            if (p_Var2 == (_STACK *)0x0) {
              p_Var2 = sk_new_null();
              a_00->certs = (stack_st_X509 *)p_Var2;
              if (p_Var2 == (_STACK *)0x0) break;
            }
            iVar3 = sk_push(p_Var2,data);
            if (iVar3 == 0) break;
            CRYPTO_add_lock((int *)((int)data + 0x10),1,3,DAT_000d3224,0x8c);
          }
          iVar1 = iVar1 + 1;
        } while( true );
      }
    }
  }
LAB_000d315c:
  a_00 = req->optionalSignature;
LAB_000d3148:
  OCSP_SIGNATURE_free(a_00);
  req->optionalSignature = (OCSP_SIGNATURE *)0x0;
  return 0;
}



int OCSP_REQUEST_print(BIO *bp,OCSP_REQUEST *a,ulong flags)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  int iVar4;
  X509 *pXVar5;
  OCSP_REQINFO *pOVar6;
  OCSP_SIGNATURE *pOVar7;
  
  pOVar6 = a->tbsRequest;
  pOVar7 = a->optionalSignature;
  iVar1 = BIO_write(bp,DAT_000d3704,0x13);
  if (0 < iVar1) {
    lVar2 = ASN1_INTEGER_get(pOVar6->version);
    iVar1 = BIO_printf(bp,DAT_000d3708,lVar2 + 1);
    if (0 < iVar1) {
      if (pOVar6->requestorName != (GENERAL_NAME *)0x0) {
        iVar1 = BIO_write(bp,DAT_000d370c,0x15);
        if (iVar1 < 1) {
          return 0;
        }
        GENERAL_NAME_print(bp,pOVar6->requestorName);
      }
      iVar1 = BIO_write(bp,DAT_000d3710,0x15);
      if (0 < iVar1) {
        iVar1 = 0;
        do {
          iVar4 = sk_num(&pOVar6->requestList->stack);
          if (iVar4 <= iVar1) {
            iVar1 = X509V3_extensions_print(bp,DAT_000d3718,pOVar6->requestExtensions,flags,4);
            if (iVar1 == 0) {
              return 0;
            }
            if (pOVar7 != (OCSP_SIGNATURE *)0x0) {
              X509_signature_print(bp,pOVar7->signatureAlgorithm,pOVar7->signature);
              for (iVar1 = 0; iVar4 = sk_num(&pOVar7->certs->stack), iVar1 < iVar4;
                  iVar1 = iVar1 + 1) {
                pXVar5 = (X509 *)sk_value(&pOVar7->certs->stack,iVar1);
                X509_print(bp,pXVar5);
                pXVar5 = (X509 *)sk_value(&pOVar7->certs->stack,iVar1);
                PEM_write_bio_X509(bp,pXVar5);
              }
            }
            return 1;
          }
          puVar3 = (undefined4 *)sk_value(&pOVar6->requestList->stack,iVar1);
          ocsp_certid_print(bp,*puVar3,8);
          iVar4 = X509V3_extensions_print
                            (bp,DAT_000d3714,(stack_st_X509_EXTENSION *)puVar3[1],flags,8);
          iVar1 = iVar1 + 1;
        } while (iVar4 != 0);
      }
    }
  }
  return 0;
}


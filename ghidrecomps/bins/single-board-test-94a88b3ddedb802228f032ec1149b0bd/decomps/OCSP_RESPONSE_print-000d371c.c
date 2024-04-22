
int OCSP_RESPONSE_print(BIO *bp,OCSP_RESPONSE *o,ulong flags)

{
  int iVar1;
  long lVar2;
  OCSP_BASICRESP *a;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  ASN1_ENUMERATED *a_00;
  X509 *pXVar6;
  OCSP_RESPID *pOVar7;
  int iVar8;
  OCSP_RESPBYTES *pOVar9;
  int *piVar10;
  ASN1_GENERALIZEDTIME **ppAVar11;
  int *piVar12;
  OCSP_RESPDATA *pOVar13;
  
  pOVar9 = o->responseBytes;
  iVar1 = BIO_puts(bp,DAT_000d3994);
  piVar10 = DAT_000d3998;
  if (0 < iVar1) {
    lVar2 = ASN1_ENUMERATED_get(o->responseStatus);
    piVar12 = piVar10 + 0xc;
    do {
      if (lVar2 == *piVar10) {
        iVar1 = piVar10[1];
        break;
      }
      piVar10 = piVar10 + 2;
      iVar1 = DAT_000d399c;
    } while (piVar10 < piVar12);
    iVar1 = BIO_printf(bp,DAT_000d39a0,iVar1);
    if (0 < iVar1) {
      if (pOVar9 == (OCSP_RESPBYTES *)0x0) {
        return 1;
      }
      iVar1 = BIO_puts(bp,DAT_000d39a4);
      if ((0 < iVar1) && (iVar1 = i2a_ASN1_OBJECT(bp,pOVar9->responseType), 0 < iVar1)) {
        iVar1 = OBJ_obj2nid(pOVar9->responseType);
        if (iVar1 != 0x16d) {
          BIO_puts(bp,DAT_000d39a8);
          return 1;
        }
        ASN1_STRING_length(pOVar9->response);
        a = OCSP_response_get1_basic(o);
        if (a != (OCSP_BASICRESP *)0x0) {
          pOVar13 = a->tbsResponseData;
          lVar2 = ASN1_INTEGER_get(pOVar13->version);
          iVar1 = BIO_printf(bp,DAT_000d39ac,lVar2 + 1);
          if ((0 < iVar1) && (iVar1 = BIO_puts(bp,DAT_000d39b0), 0 < iVar1)) {
            pOVar7 = pOVar13->responderId;
            if (pOVar7->type == 0) {
              X509_NAME_print_ex(bp,(pOVar7->value).byName,0,0x82031f);
            }
            else if (pOVar7->type == 1) {
              i2a_ASN1_STRING(bp,(ASN1_STRING *)(pOVar7->value).byName,4);
            }
            iVar1 = BIO_printf(bp,DAT_000d39b4);
            if (((0 < iVar1) &&
                (iVar1 = ASN1_GENERALIZEDTIME_print(bp,pOVar13->producedAt), iVar1 != 0)) &&
               (iVar1 = BIO_printf(bp,DAT_000d39b8), 0 < iVar1)) {
              for (iVar1 = 0; iVar3 = sk_num(&pOVar13->responses->stack), iVar1 < iVar3;
                  iVar1 = iVar1 + 1) {
                pvVar4 = sk_value(&pOVar13->responses->stack,iVar1);
                if (pvVar4 != (void *)0x0) {
                  puVar5 = (undefined4 *)sk_value(&pOVar13->responses->stack,iVar1);
                  iVar3 = ocsp_certid_print(bp,*puVar5,4);
                  if (iVar3 < 1) goto LAB_000d380c;
                  piVar10 = (int *)puVar5[1];
                  iVar3 = BIO_printf(bp,DAT_000d39d0);
                  if (iVar3 < 1) goto LAB_000d380c;
                  if (*piVar10 == 1) {
                    ppAVar11 = (ASN1_GENERALIZEDTIME **)piVar10[1];
                    iVar3 = BIO_printf(bp,DAT_000d39d4);
                    if ((iVar3 < 1) ||
                       (iVar3 = ASN1_GENERALIZEDTIME_print(bp,*ppAVar11), iVar3 == 0))
                    goto LAB_000d380c;
                    a_00 = ppAVar11[1];
                    if (a_00 != (ASN1_ENUMERATED *)0x0) {
                      lVar2 = ASN1_ENUMERATED_get(a_00);
                      iVar3 = DAT_000d3a4c;
                      if (((lVar2 == 0) || (iVar3 = DAT_000d3a48, lVar2 == 1)) ||
                         ((iVar3 = DAT_000d3a44, lVar2 == 2 ||
                          ((((iVar3 = DAT_000d3a40, lVar2 == 3 || (iVar3 = DAT_000d3a3c, lVar2 == 4)
                             ) || (iVar3 = DAT_000d3a38, lVar2 == 5)) ||
                           ((iVar3 = DAT_000d39e8, lVar2 == 6 ||
                            (iVar8 = DAT_000d399c, iVar3 = DAT_000d39d8, lVar2 == 8)))))))) {
                        iVar8 = *(int *)(iVar3 + 4);
                      }
                      iVar3 = BIO_printf(bp,DAT_000d39dc,iVar8,lVar2);
                      if (iVar3 < 1) goto LAB_000d380c;
                    }
                  }
                  iVar3 = BIO_printf(bp,DAT_000d39bc);
                  if ((((iVar3 < 1) ||
                       (iVar3 = ASN1_GENERALIZEDTIME_print(bp,(ASN1_GENERALIZEDTIME *)puVar5[2]),
                       iVar3 == 0)) ||
                      (((puVar5[3] != 0 &&
                        ((iVar3 = BIO_printf(bp,DAT_000d39c0), iVar3 < 1 ||
                         (iVar3 = ASN1_GENERALIZEDTIME_print(bp,(ASN1_GENERALIZEDTIME *)puVar5[3]),
                         iVar3 == 0)))) || (iVar3 = BIO_write(bp,DAT_000d39c4,1), iVar3 < 1)))) ||
                     ((iVar3 = X509V3_extensions_print
                                         (bp,DAT_000d39c8,(stack_st_X509_EXTENSION *)puVar5[4],flags
                                          ,8), iVar3 == 0 ||
                      (iVar3 = BIO_write(bp,DAT_000d39c4,1), iVar3 < 1)))) goto LAB_000d380c;
                }
              }
              iVar1 = X509V3_extensions_print(bp,DAT_000d39ec,pOVar13->responseExtensions,flags,4);
              if (iVar1 != 0) {
                iVar1 = 0;
                iVar3 = X509_signature_print(bp,a->signatureAlgorithm,a->signature);
                if (0 < iVar3) {
                  for (; iVar3 = sk_num(&a->certs->stack), iVar1 < iVar3; iVar1 = iVar1 + 1) {
                    pXVar6 = (X509 *)sk_value(&a->certs->stack,iVar1);
                    X509_print(bp,pXVar6);
                    pXVar6 = (X509 *)sk_value(&a->certs->stack,iVar1);
                    PEM_write_bio_X509(bp,pXVar6);
                  }
                  iVar1 = 1;
                }
                goto LAB_000d3794;
              }
            }
          }
LAB_000d380c:
          iVar1 = 0;
          goto LAB_000d3794;
        }
      }
    }
  }
  a = (OCSP_BASICRESP *)0x0;
  iVar1 = 0;
LAB_000d3794:
  OCSP_BASICRESP_free(a);
  return iVar1;
}


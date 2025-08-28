
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
  char *pcVar8;
  undefined1 *puVar9;
  int *piVar10;
  OCSP_RESPBYTES *pOVar11;
  undefined4 *puVar12;
  OCSP_RESPDATA *pOVar13;
  
  pOVar11 = o->responseBytes;
  iVar1 = BIO_puts(bp,"OCSP Response Data:\n");
  if (0 < iVar1) {
    piVar10 = &rstat_tbl_16206;
    lVar2 = ASN1_ENUMERATED_get(o->responseStatus);
    do {
      if (lVar2 == *piVar10) {
        pcVar8 = (char *)piVar10[1];
        goto LAB_000d3750;
      }
      piVar10 = piVar10 + 2;
    } while (piVar10 < cstat_tbl_16210);
    pcVar8 = "(UNKNOWN)";
LAB_000d3750:
    iVar1 = BIO_printf(bp,"    OCSP Response Status: %s (0x%lx)\n",pcVar8);
    if (0 < iVar1) {
      if (pOVar11 == (OCSP_RESPBYTES *)0x0) {
        return 1;
      }
      iVar1 = BIO_puts(bp,"    Response Type: ");
      if ((0 < iVar1) && (iVar1 = i2a_ASN1_OBJECT(bp,pOVar11->responseType), 0 < iVar1)) {
        iVar1 = OBJ_obj2nid(pOVar11->responseType);
        if (iVar1 != 0x16d) {
          BIO_puts(bp," (unknown response type)\n");
          return 1;
        }
        ASN1_STRING_length(pOVar11->response);
        a = OCSP_response_get1_basic(o);
        if (a != (OCSP_BASICRESP *)0x0) {
          pOVar13 = a->tbsResponseData;
          lVar2 = ASN1_INTEGER_get(pOVar13->version);
          iVar1 = BIO_printf(bp,"\n    Version: %lu (0x%lx)\n",lVar2 + 1);
          if ((0 < iVar1) && (iVar1 = BIO_puts(bp,"    Responder Id: "), 0 < iVar1)) {
            pOVar7 = pOVar13->responderId;
            if (pOVar7->type == 0) {
              X509_NAME_print_ex(bp,(pOVar7->value).byName,0,0x82031f);
            }
            else if (pOVar7->type == 1) {
              i2a_ASN1_STRING(bp,(ASN1_STRING *)(pOVar7->value).byName,4);
            }
            iVar1 = BIO_printf(bp,"\n    Produced At: ");
            if (((0 < iVar1) &&
                (iVar1 = ASN1_GENERALIZEDTIME_print(bp,pOVar13->producedAt), iVar1 != 0)) &&
               (iVar1 = BIO_printf(bp,"\n    Responses:\n"), 0 < iVar1)) {
              for (iVar1 = 0; iVar3 = sk_num(&pOVar13->responses->stack), iVar1 < iVar3;
                  iVar1 = iVar1 + 1) {
                pvVar4 = sk_value(&pOVar13->responses->stack,iVar1);
                if (pvVar4 != (void *)0x0) {
                  puVar5 = (undefined4 *)sk_value(&pOVar13->responses->stack,iVar1);
                  iVar3 = ocsp_certid_print(bp,*puVar5,4);
                  if (iVar3 < 1) goto LAB_000d380c;
                  piVar10 = (int *)puVar5[1];
                  iVar3 = *piVar10;
                  if (iVar3 == 0) {
                    puVar9 = cstat_tbl_16210;
LAB_000d395e:
                    pcVar8 = *(char **)(puVar9 + 4);
                  }
                  else {
                    if (iVar3 == 1) {
                      puVar9 = (undefined1 *)0x168ec8;
                      goto LAB_000d395e;
                    }
                    if (iVar3 == 2) {
                      puVar9 = (undefined1 *)0x168ed0;
                      goto LAB_000d395e;
                    }
                    pcVar8 = "(UNKNOWN)";
                  }
                  iVar3 = BIO_printf(bp,"    Cert Status: %s",pcVar8);
                  if (iVar3 < 1) goto LAB_000d380c;
                  if (*piVar10 == 1) {
                    puVar12 = (undefined4 *)piVar10[1];
                    iVar3 = BIO_printf(bp,"\n    Revocation Time: ");
                    if ((iVar3 < 1) ||
                       (iVar3 = ASN1_GENERALIZEDTIME_print(bp,(ASN1_GENERALIZEDTIME *)*puVar12),
                       iVar3 == 0)) goto LAB_000d380c;
                    a_00 = (ASN1_ENUMERATED *)puVar12[1];
                    if (a_00 != (ASN1_ENUMERATED *)0x0) {
                      lVar2 = ASN1_ENUMERATED_get(a_00);
                      if (lVar2 == 0) {
                        puVar9 = reason_tbl_16214;
LAB_000d3968:
                        pcVar8 = *(char **)(puVar9 + 4);
                      }
                      else {
                        if (lVar2 == 1) {
                          puVar9 = (undefined1 *)0x168ee0;
                          goto LAB_000d3968;
                        }
                        if (lVar2 == 2) {
                          puVar9 = (undefined1 *)0x168ee8;
                          goto LAB_000d3968;
                        }
                        if (lVar2 == 3) {
                          puVar9 = (undefined1 *)0x168ef0;
                          goto LAB_000d3968;
                        }
                        if (lVar2 == 4) {
                          puVar9 = (undefined1 *)0x168ef8;
                          goto LAB_000d3968;
                        }
                        if (lVar2 == 5) {
                          puVar9 = (undefined1 *)0x168f00;
                          goto LAB_000d3968;
                        }
                        if (lVar2 == 6) {
                          puVar9 = (undefined1 *)0x168f08;
                          goto LAB_000d3968;
                        }
                        if (lVar2 == 8) {
                          puVar9 = (undefined1 *)0x168f10;
                          goto LAB_000d3968;
                        }
                        pcVar8 = "(UNKNOWN)";
                      }
                      iVar3 = BIO_printf(bp,"\n    Revocation Reason: %s (0x%lx)",pcVar8,lVar2);
                      if (iVar3 < 1) goto LAB_000d380c;
                    }
                  }
                  iVar3 = BIO_printf(bp,"\n    This Update: ");
                  if (((((iVar3 < 1) ||
                        (iVar3 = ASN1_GENERALIZEDTIME_print(bp,(ASN1_GENERALIZEDTIME *)puVar5[2]),
                        iVar3 == 0)) ||
                       ((puVar5[3] != 0 &&
                        ((iVar3 = BIO_printf(bp,"\n    Next Update: "), iVar3 < 1 ||
                         (iVar3 = ASN1_GENERALIZEDTIME_print(bp,(ASN1_GENERALIZEDTIME *)puVar5[3]),
                         iVar3 == 0)))))) || (iVar3 = BIO_write(bp,"\n",1), iVar3 < 1)) ||
                     ((iVar3 = X509V3_extensions_print
                                         (bp,"Response Single Extensions",
                                          (stack_st_X509_EXTENSION *)puVar5[4],flags,8), iVar3 == 0
                      || (iVar3 = BIO_write(bp,"\n",1), iVar3 < 1)))) goto LAB_000d380c;
                }
              }
              iVar1 = X509V3_extensions_print
                                (bp,"Response Extensions",pOVar13->responseExtensions,flags,4);
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


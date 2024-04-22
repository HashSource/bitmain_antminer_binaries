
int CMS_set1_signers_certs(CMS_ContentInfo *cms,stack_st_X509 *certs,uint flags)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  X509 *pXVar5;
  EVP_PKEY *pEVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  _STACK *p_Var11;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    iVar10 = *(int *)(cms + 4);
    iVar1 = -1;
    if (iVar10 != 0) {
      iVar1 = 0;
      p_Var11 = *(_STACK **)(iVar10 + 0xc);
      for (iVar9 = 0; iVar2 = sk_num(*(_STACK **)(iVar10 + 0x14)), iVar9 < iVar2; iVar9 = iVar9 + 1)
      {
        pvVar3 = sk_value(*(_STACK **)(iVar10 + 0x14),iVar9);
        iVar2 = *(int *)((int)pvVar3 + 0x1c);
        if (iVar2 == 0) {
          for (; iVar4 = sk_num(&certs->stack), iVar2 < iVar4; iVar2 = iVar2 + 1) {
            pXVar5 = (X509 *)sk_value(&certs->stack,iVar2);
            piVar7 = *(int **)((int)pvVar3 + 4);
            if (*piVar7 == 0) {
              iVar4 = cms_ias_cert_cmp(piVar7[1],pXVar5);
joined_r0x0011054a:
              if (iVar4 == 0) {
                if (pXVar5 != (X509 *)0x0) {
                  CRYPTO_add_lock(&pXVar5->references,1,3,DAT_0011066c,0x1e9);
                  if (*(EVP_PKEY **)((int)pvVar3 + 0x20) != (EVP_PKEY *)0x0) {
                    EVP_PKEY_free(*(EVP_PKEY **)((int)pvVar3 + 0x20));
                  }
                  pEVar6 = X509_get_pubkey(pXVar5);
                  *(EVP_PKEY **)((int)pvVar3 + 0x20) = pEVar6;
                }
                if (*(X509 **)((int)pvVar3 + 0x1c) != (X509 *)0x0) {
                  X509_free(*(X509 **)((int)pvVar3 + 0x1c));
                }
                *(X509 **)((int)pvVar3 + 0x1c) = pXVar5;
                iVar1 = iVar1 + 1;
                if (pXVar5 != (X509 *)0x0) goto LAB_001104f2;
                goto LAB_0011058c;
              }
            }
            else if (*piVar7 == 1) {
              iVar4 = cms_keyid_cert_cmp(piVar7[1]);
              goto joined_r0x0011054a;
            }
          }
          if (*(int *)((int)pvVar3 + 0x1c) == 0) {
LAB_0011058c:
            if ((flags & 0x10) == 0) {
              for (iVar2 = 0; iVar4 = sk_num(p_Var11), iVar2 < iVar4; iVar2 = iVar2 + 1) {
                piVar7 = (int *)sk_value(p_Var11,iVar2);
                if (*piVar7 == 0) {
                  piVar8 = *(int **)((int)pvVar3 + 4);
                  pXVar5 = (X509 *)piVar7[1];
                  if (*piVar8 == 0) {
                    iVar4 = cms_ias_cert_cmp(piVar8[1],pXVar5);
                  }
                  else {
                    if (*piVar8 != 1) goto LAB_00110596;
                    iVar4 = cms_keyid_cert_cmp(piVar8[1]);
                  }
                  if (iVar4 == 0) {
                    if (pXVar5 != (X509 *)0x0) {
                      CRYPTO_add_lock(&pXVar5->references,1,3,DAT_0011066c,0x1e9);
                      if (*(EVP_PKEY **)((int)pvVar3 + 0x20) != (EVP_PKEY *)0x0) {
                        EVP_PKEY_free(*(EVP_PKEY **)((int)pvVar3 + 0x20));
                      }
                      pEVar6 = X509_get_pubkey(pXVar5);
                      *(EVP_PKEY **)((int)pvVar3 + 0x20) = pEVar6;
                    }
                    if (*(X509 **)((int)pvVar3 + 0x1c) != (X509 *)0x0) {
                      X509_free(*(X509 **)((int)pvVar3 + 0x1c));
                    }
                    *(X509 **)((int)pvVar3 + 0x1c) = pXVar5;
                    iVar1 = iVar1 + 1;
                    break;
                  }
                }
LAB_00110596:
              }
            }
          }
        }
LAB_001104f2:
      }
    }
  }
  else {
    iVar1 = -1;
    ERR_put_error(0x2e,0x85,0x6c,DAT_0011066c,0x48);
  }
  return iVar1;
}


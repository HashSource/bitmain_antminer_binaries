
undefined4 process_pci_value(CONF_VALUE *param_1,int *param_2,ASN1_INTEGER **param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  ASN1_OBJECT *pAVar4;
  void *pvVar5;
  BIO *b;
  size_t __n;
  int *piVar6;
  char *pcVar7;
  ASN1_OCTET_STRING *pAVar8;
  size_t local_828 [513];
  
  pcVar7 = param_1->name;
  iVar2 = strcmp(pcVar7,"language");
  if (iVar2 == 0) {
    if (*param_2 == 0) {
      pAVar4 = OBJ_txt2obj(param_1->value,0);
      *param_2 = (int)pAVar4;
      if (pAVar4 != (ASN1_OBJECT *)0x0) {
        return 1;
      }
      ERR_put_error(0x22,0x96,0x6e,"crypto/x509v3/v3_pci.c",0x65);
      ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                         param_1->value);
    }
    else {
      ERR_put_error(0x22,0x96,0x9b,"crypto/x509v3/v3_pci.c",0x5f);
      ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                         param_1->value);
    }
  }
  else {
    iVar2 = strcmp(pcVar7,"pathlen");
    if (iVar2 == 0) {
      if (*param_3 != (ASN1_INTEGER *)0x0) {
        ERR_put_error(0x22,0x96,0x9d,"crypto/x509v3/v3_pci.c",0x6c);
        ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                           param_1->value);
        return 0;
      }
      iVar2 = X509V3_get_value_int(param_1,param_3);
      if (iVar2 != 0) {
        return 1;
      }
      ERR_put_error(0x22,0x96,0x9c,"crypto/x509v3/v3_pci.c",0x72);
      ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                         param_1->value);
    }
    else {
      iVar2 = strcmp(pcVar7,"policy");
      if (iVar2 != 0) {
        return 1;
      }
      pAVar8 = (ASN1_OCTET_STRING *)*param_4;
      if (pAVar8 == (ASN1_OCTET_STRING *)0x0) {
        pAVar8 = ASN1_OCTET_STRING_new();
        *param_4 = (int)pAVar8;
        if (pAVar8 == (ASN1_OCTET_STRING *)0x0) {
          ERR_put_error(0x22,0x96,0x41,"crypto/x509v3/v3_pci.c",0x7c);
          ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                             param_1->value);
          return 0;
        }
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      pcVar7 = param_1->value;
      iVar2 = strncmp(pcVar7,"hex:",4);
      if (iVar2 == 0) {
        pvVar5 = (void *)OPENSSL_hexstr2buf(pcVar7 + 4,local_828);
        if (pvVar5 == (void *)0x0) {
          ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                             param_1->value);
        }
        else {
          pvVar3 = CRYPTO_realloc((void *)((int *)*param_4)[2],local_828[0] + *(int *)*param_4 + 1,
                                  "crypto/x509v3/v3_pci.c",0x8c);
          if (pvVar3 != (void *)0x0) {
            *(void **)(*param_4 + 8) = pvVar3;
            memcpy((void *)(((int *)*param_4)[2] + *(int *)*param_4),pvVar5,local_828[0]);
            param_4 = (int *)*param_4;
            iVar2 = *param_4;
            *param_4 = local_828[0] + iVar2;
            *(undefined1 *)(param_4[2] + local_828[0] + iVar2) = 0;
            CRYPTO_free(pvVar5);
            return 1;
          }
          CRYPTO_free(pvVar5);
          CRYPTO_free(*(void **)(*param_4 + 8));
          *(undefined4 *)(*param_4 + 8) = 0;
          *(undefined4 *)*param_4 = 0;
          ERR_put_error(0x22,0x96,0x41,"crypto/x509v3/v3_pci.c",0x9c);
          ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                             param_1->value);
        }
      }
      else {
        iVar2 = strncmp(pcVar7,"file:",5);
        if (iVar2 == 0) {
          b = BIO_new_file(pcVar7 + 5,"r");
          if (b == (BIO *)0x0) {
            ERR_put_error(0x22,0x96,0x20,"crypto/x509v3/v3_pci.c",0xa6);
            ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                               param_1->value);
          }
          else {
            pvVar5 = (void *)0x0;
            do {
              while( true ) {
                __n = BIO_read(b,local_828,0x800);
                if ((int)__n < 1) break;
                pvVar5 = CRYPTO_realloc((void *)((int *)*param_4)[2],*(int *)*param_4 + __n + 1,
                                        "crypto/x509v3/v3_pci.c",0xb0);
                if (pvVar5 == (void *)0x0) {
                  CRYPTO_free(*(void **)(*param_4 + 8));
                  *(undefined4 *)(*param_4 + 8) = 0;
                  *(undefined4 *)*param_4 = 0;
                  ERR_put_error(0x22,0x96,0x41,"crypto/x509v3/v3_pci.c",0xb7);
                  ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                                     param_1->value);
                  BIO_free_all(b);
                  goto LAB_001728e2;
                }
                *(void **)(*param_4 + 8) = pvVar5;
                memcpy((void *)(((int *)*param_4)[2] + *(int *)*param_4),local_828,__n);
                piVar6 = (int *)*param_4;
                iVar2 = *piVar6;
                *piVar6 = __n + iVar2;
                *(undefined1 *)(piVar6[2] + __n + iVar2) = 0;
              }
              if (__n != 0) {
                BIO_free_all(b);
                ERR_put_error(0x22,0x96,0x20,"crypto/x509v3/v3_pci.c",0xc5);
                ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                                   param_1->value);
                goto LAB_001728e2;
              }
              iVar2 = BIO_test_flags(b,8);
            } while (iVar2 != 0);
            BIO_free_all(b);
            if (pvVar5 != (void *)0x0) {
              return 1;
            }
            ERR_put_error(0x22,0x96,0x41,"crypto/x509v3/v3_pci.c",0xe6);
            ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                               param_1->value);
          }
        }
        else {
          iVar2 = strncmp(pcVar7,"text:",5);
          if (iVar2 == 0) {
            local_828[0] = strlen(pcVar7 + 5);
            pvVar5 = CRYPTO_realloc(pAVar8->data,pAVar8->length + local_828[0] + 1,
                                    "crypto/x509v3/v3_pci.c",0xcc);
            if (pvVar5 != (void *)0x0) {
              pcVar7 = param_1->value;
              *(void **)(*param_4 + 8) = pvVar5;
              memcpy((void *)(((int *)*param_4)[2] + *(int *)*param_4),pcVar7 + 5,local_828[0]);
              param_4 = (int *)*param_4;
              iVar2 = *param_4;
              *param_4 = local_828[0] + iVar2;
              *(undefined1 *)(param_4[2] + local_828[0] + iVar2) = 0;
              return 1;
            }
            CRYPTO_free(*(void **)(*param_4 + 8));
            *(undefined4 *)(*param_4 + 8) = 0;
            *(undefined4 *)*param_4 = 0;
            ERR_put_error(0x22,0x96,0x41,"crypto/x509v3/v3_pci.c",0xdb);
            ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                               param_1->value);
          }
          else {
            ERR_put_error(0x22,0x96,0x98,"crypto/x509v3/v3_pci.c",0xe1);
            ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                               param_1->value);
          }
        }
      }
LAB_001728e2:
      if (bVar1) {
        ASN1_OCTET_STRING_free((ASN1_STRING *)*param_4);
        *param_4 = 0;
      }
    }
  }
  return 0;
}


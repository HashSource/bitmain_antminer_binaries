
undefined4
process_pci_value(CONF_VALUE *param_1,ASN1_OBJECT **param_2,ASN1_INTEGER **param_3,
                 ASN1_OCTET_STRING **param_4)

{
  int iVar1;
  uchar *puVar2;
  ASN1_OBJECT *pAVar3;
  uchar *puVar4;
  BIO *b;
  size_t __n;
  char *pcVar5;
  ASN1_OCTET_STRING *pAVar6;
  bool bVar7;
  int iVar8;
  size_t local_824;
  undefined auStack_820 [2048];
  
  pcVar5 = param_1->name;
  iVar1 = strcmp(pcVar5,DAT_000cd1dc);
  if (iVar1 == 0) {
    if (*param_2 != (ASN1_OBJECT *)0x0) {
      iVar1 = 0x9b;
      iVar8 = 0x55;
LAB_000ccf86:
      ERR_put_error(0x22,0x96,iVar1,DAT_000cd1e0,iVar8);
      ERR_add_error_data(6,DAT_000cd1e8,param_1->section,DAT_000cd1ec,param_1->name,DAT_000cd1e4,
                         param_1->value);
      return 0;
    }
    pAVar3 = OBJ_txt2obj(param_1->value,0);
    *param_2 = pAVar3;
    if (pAVar3 != (ASN1_OBJECT *)0x0) {
      return 1;
    }
    iVar8 = 0x5b;
    iVar1 = 0x6e;
LAB_000cd0e6:
    ERR_put_error(0x22,0x96,iVar1,DAT_000cd1e0,iVar8);
    ERR_add_error_data(6,DAT_000cd1e8,param_1->section,DAT_000cd1ec,param_1->name,DAT_000cd1e4,
                       param_1->value);
    return 0;
  }
  iVar1 = strcmp(pcVar5,DAT_000cd1f0);
  if (iVar1 == 0) {
    if (*param_3 != (ASN1_INTEGER *)0x0) {
      iVar8 = 0x62;
      iVar1 = 0x9d;
      goto LAB_000ccf86;
    }
    iVar1 = X509V3_get_value_int(param_1,param_3);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = 0x9c;
    iVar8 = 0x68;
    goto LAB_000cd0e6;
  }
  iVar1 = strcmp(pcVar5,DAT_000cd1f4);
  if (iVar1 != 0) {
    return 1;
  }
  pAVar6 = *param_4;
  if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
    pAVar6 = ASN1_OCTET_STRING_new();
    *param_4 = pAVar6;
    if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
      ERR_put_error(0x22,0x96,0x41,DAT_000cd2a0,0x72);
      ERR_add_error_data(6,DAT_000cd2ac,param_1->section,DAT_000cd2a8,param_1->name,DAT_000cd2a4,
                         param_1->value);
      return 0;
    }
    bVar7 = true;
  }
  else {
    bVar7 = false;
  }
  pcVar5 = param_1->value;
  iVar1 = strncmp(pcVar5,DAT_000cd1f8,4);
  if (iVar1 == 0) {
    puVar4 = string_to_hex(pcVar5 + 4,(long *)&local_824);
    if (puVar4 == (uchar *)0x0) {
      iVar1 = 0x7e;
      iVar8 = 0x71;
      pcVar5 = DAT_000cd1e0;
      goto LAB_000cd028;
    }
    puVar2 = (uchar *)CRYPTO_realloc((*param_4)->data,(*param_4)->length + local_824 + 1,
                                     DAT_000cd1e0,0x84);
    if (puVar2 != (uchar *)0x0) {
      (*param_4)->data = puVar2;
      memcpy((*param_4)->data + (*param_4)->length,puVar4,local_824);
      pAVar6 = *param_4;
      iVar1 = pAVar6->length + local_824;
      pAVar6->length = iVar1;
      pAVar6->data[iVar1] = '\0';
      CRYPTO_free(puVar4);
      return 1;
    }
    CRYPTO_free(puVar4);
    pAVar6 = *param_4;
    iVar1 = 0x93;
  }
  else {
    iVar1 = strncmp(pcVar5,DAT_000cd1fc,5);
    if (iVar1 == 0) {
      b = BIO_new_file(pcVar5 + 5,DAT_000cd204);
      if (b == (BIO *)0x0) {
        iVar1 = 0x9d;
        iVar8 = 0x20;
        pcVar5 = DAT_000cd1e0;
      }
      else {
        puVar4 = (uchar *)0x0;
        do {
          while( true ) {
            __n = BIO_read(b,auStack_820,0x800);
            if ((int)__n < 1) break;
            puVar4 = (uchar *)CRYPTO_realloc((*param_4)->data,__n + (*param_4)->length + 1,
                                             DAT_000cd1e0,0xa7);
            if (puVar4 == (uchar *)0x0) {
              BIO_free_all(b);
              goto LAB_000cd1d0;
            }
            (*param_4)->data = puVar4;
            memcpy((*param_4)->data + (*param_4)->length,auStack_820,__n);
            pAVar6 = *param_4;
            iVar1 = __n + pAVar6->length;
            pAVar6->length = iVar1;
            pAVar6->data[iVar1] = '\0';
          }
          if (__n != 0) {
            BIO_free_all(b);
            iVar1 = 0xb4;
            iVar8 = 0x20;
            pcVar5 = DAT_000cd1e0;
            goto LAB_000cd028;
          }
          iVar1 = BIO_test_flags(b,8);
        } while (iVar1 != 0);
        BIO_free_all(b);
        if (puVar4 != (uchar *)0x0) {
          return 1;
        }
LAB_000cd1d0:
        iVar1 = 0xd4;
        iVar8 = 0x41;
        pcVar5 = DAT_000cd1e0;
      }
      goto LAB_000cd028;
    }
    iVar1 = strncmp(pcVar5,DAT_000cd200,5);
    if (iVar1 != 0) {
      iVar8 = 0x98;
      iVar1 = 0xcf;
      pcVar5 = DAT_000cd1e0;
      goto LAB_000cd028;
    }
    local_824 = strlen(pcVar5 + 5);
    puVar4 = (uchar *)CRYPTO_realloc(pAVar6->data,local_824 + pAVar6->length + 1,DAT_000cd1e0,0xbb);
    if (puVar4 != (uchar *)0x0) {
      pcVar5 = param_1->value;
      (*param_4)->data = puVar4;
      memcpy((*param_4)->data + (*param_4)->length,pcVar5 + 5,local_824);
      pAVar6 = *param_4;
      iVar1 = pAVar6->length + local_824;
      pAVar6->length = iVar1;
      pAVar6->data[iVar1] = '\0';
      return 1;
    }
    pAVar6 = *param_4;
    iVar1 = 0xc9;
  }
  pAVar6->data = (uchar *)0x0;
  pcVar5 = DAT_000cd2a0;
  iVar8 = 0x41;
  (*param_4)->length = 0;
LAB_000cd028:
  ERR_put_error(0x22,0x96,iVar8,pcVar5,iVar1);
  ERR_add_error_data(6,DAT_000cd1e8,param_1->section,DAT_000cd1ec,param_1->name,DAT_000cd1e4,
                     param_1->value);
  if (bVar7) {
    ASN1_OCTET_STRING_free(*param_4);
    *param_4 = (ASN1_OCTET_STRING *)0x0;
    return 0;
  }
  return 0;
}


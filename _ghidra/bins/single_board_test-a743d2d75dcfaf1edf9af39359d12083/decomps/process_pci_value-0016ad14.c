
undefined4 process_pci_value(CONF_VALUE *param_1,int *param_2,ASN1_INTEGER **param_3,int *param_4)

{
  int iVar1;
  uchar *ptr;
  ASN1_OBJECT *pAVar2;
  void *pvVar3;
  BIO *b;
  size_t __n;
  int *piVar4;
  char *pcVar5;
  ASN1_OCTET_STRING *pAVar6;
  bool bVar7;
  int iVar8;
  size_t local_824;
  undefined1 auStack_820 [2048];
  
  pcVar5 = param_1->name;
  iVar1 = strcmp(pcVar5,"language");
  if (iVar1 == 0) {
    if (*param_2 != 0) {
      iVar1 = 0x9b;
      iVar8 = 0x55;
LAB_0016ad46:
      ERR_put_error(0x22,0x96,iVar1,"v3_pci.c",iVar8);
      ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                         param_1->value);
      return 0;
    }
    pAVar2 = OBJ_txt2obj(param_1->value,0);
    *param_2 = (int)pAVar2;
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      return 1;
    }
    iVar8 = 0x5b;
    iVar1 = 0x6e;
LAB_0016aea6:
    ERR_put_error(0x22,0x96,iVar1,"v3_pci.c",iVar8);
    ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",param_1->value
                      );
    return 0;
  }
  iVar1 = strcmp(pcVar5,"pathlen");
  if (iVar1 == 0) {
    if (*param_3 != (ASN1_INTEGER *)0x0) {
      iVar8 = 0x62;
      iVar1 = 0x9d;
      goto LAB_0016ad46;
    }
    iVar1 = X509V3_get_value_int(param_1,param_3);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = 0x9c;
    iVar8 = 0x68;
    goto LAB_0016aea6;
  }
  iVar1 = strcmp(pcVar5,"policy");
  if (iVar1 != 0) {
    return 1;
  }
  pAVar6 = (ASN1_OCTET_STRING *)*param_4;
  if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
    pAVar6 = ASN1_OCTET_STRING_new();
    *param_4 = (int)pAVar6;
    if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
      ERR_put_error(0x22,0x96,0x41,"v3_pci.c",0x72);
      ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                         param_1->value);
      return 0;
    }
    bVar7 = true;
  }
  else {
    bVar7 = false;
  }
  pcVar5 = param_1->value;
  iVar1 = strncmp(pcVar5,"hex:",4);
  if (iVar1 == 0) {
    ptr = string_to_hex(pcVar5 + 4,(long *)&local_824);
    if (ptr == (uchar *)0x0) {
      iVar1 = 0x7e;
      iVar8 = 0x71;
      goto LAB_0016ade8;
    }
    pvVar3 = CRYPTO_realloc((void *)((int *)*param_4)[2],*(int *)*param_4 + local_824 + 1,"v3_pci.c"
                            ,0x84);
    if (pvVar3 != (void *)0x0) {
      *(void **)(*param_4 + 8) = pvVar3;
      memcpy((void *)(((int *)*param_4)[2] + *(int *)*param_4),ptr,local_824);
      param_4 = (int *)*param_4;
      iVar1 = *param_4;
      *param_4 = iVar1 + local_824;
      *(undefined1 *)(param_4[2] + iVar1 + local_824) = 0;
      CRYPTO_free(ptr);
      return 1;
    }
    CRYPTO_free(ptr);
    iVar8 = *param_4;
    iVar1 = 0x93;
  }
  else {
    iVar1 = strncmp(pcVar5,"file:",5);
    if (iVar1 == 0) {
      b = BIO_new_file(pcVar5 + 5,"r");
      if (b == (BIO *)0x0) {
        iVar1 = 0x9d;
        iVar8 = 0x20;
      }
      else {
        pvVar3 = (void *)0x0;
        do {
          while( true ) {
            __n = BIO_read(b,auStack_820,0x800);
            if ((int)__n < 1) break;
            pvVar3 = CRYPTO_realloc((void *)((int *)*param_4)[2],__n + *(int *)*param_4 + 1,
                                    "v3_pci.c",0xa7);
            if (pvVar3 == (void *)0x0) {
              BIO_free_all(b);
              goto LAB_0016af90;
            }
            *(void **)(*param_4 + 8) = pvVar3;
            memcpy((void *)(((int *)*param_4)[2] + *(int *)*param_4),auStack_820,__n);
            piVar4 = (int *)*param_4;
            iVar1 = *piVar4;
            *piVar4 = __n + iVar1;
            *(undefined1 *)(piVar4[2] + __n + iVar1) = 0;
          }
          if (__n != 0) {
            BIO_free_all(b);
            iVar1 = 0xb4;
            iVar8 = 0x20;
            goto LAB_0016ade8;
          }
          iVar1 = BIO_test_flags(b,8);
        } while (iVar1 != 0);
        BIO_free_all(b);
        if (pvVar3 != (void *)0x0) {
          return 1;
        }
LAB_0016af90:
        iVar1 = 0xd4;
        iVar8 = 0x41;
      }
      goto LAB_0016ade8;
    }
    iVar1 = strncmp(pcVar5,"text:",5);
    if (iVar1 != 0) {
      iVar8 = 0x98;
      iVar1 = 0xcf;
      goto LAB_0016ade8;
    }
    local_824 = strlen(pcVar5 + 5);
    pvVar3 = CRYPTO_realloc(pAVar6->data,local_824 + pAVar6->length + 1,"v3_pci.c",0xbb);
    if (pvVar3 != (void *)0x0) {
      pcVar5 = param_1->value;
      *(void **)(*param_4 + 8) = pvVar3;
      memcpy((void *)(((int *)*param_4)[2] + *(int *)*param_4),pcVar5 + 5,local_824);
      param_4 = (int *)*param_4;
      iVar1 = *param_4;
      *param_4 = iVar1 + local_824;
      *(undefined1 *)(param_4[2] + iVar1 + local_824) = 0;
      return 1;
    }
    iVar8 = *param_4;
    iVar1 = 0xc9;
  }
  *(undefined4 *)(iVar8 + 8) = 0;
  iVar8 = 0x41;
  *(undefined4 *)*param_4 = 0;
LAB_0016ade8:
  ERR_put_error(0x22,0x96,iVar8,"v3_pci.c",iVar1);
  ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",param_1->value);
  if (bVar7) {
    ASN1_OCTET_STRING_free((ASN1_OCTET_STRING *)*param_4);
    *param_4 = 0;
    return 0;
  }
  return 0;
}


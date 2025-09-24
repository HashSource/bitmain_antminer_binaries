
ASIdentifiers * v2i_ASIdentifiers(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ASIdentifiers *a;
  int iVar1;
  CONF_VALUE *value;
  char *pcVar2;
  size_t sVar3;
  ASN1_STRING *y;
  char *pcVar4;
  char *pcVar5;
  char cVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  ASN1_INTEGER *local_2c [2];
  
  iVar10 = 0;
  local_2c[0] = (ASN1_INTEGER *)0x0;
  a = ASIdentifiers_new();
  if (a == (ASIdentifiers *)0x0) {
    ERR_put_error(0x22,0xa3,0x41,"crypto/x509v3/v3_asid.c",0x20e);
  }
  else {
    iVar1 = OPENSSL_sk_num(param_3);
    if (0 < iVar1) {
      do {
        value = (CONF_VALUE *)OPENSSL_sk_value(param_3,iVar10);
        iVar1 = name_cmp(value->name,"AS");
        if (iVar1 != 0) {
          iVar1 = name_cmp(value->name,"RDI");
          if (iVar1 != 0) {
            y = (ASN1_STRING *)0x0;
            ERR_put_error(0x22,0xa3,0x73,"crypto/x509v3/v3_asid.c",0x21f);
            ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",
                               value->value);
            goto LAB_00172b5a;
          }
          pcVar11 = value->value;
          uVar9 = 1;
          iVar1 = strcmp(pcVar11,"inherit");
          uVar8 = uVar9;
          if (iVar1 == 0) goto LAB_00172b14;
LAB_001729c6:
          pcVar2 = (char *)strspn(pcVar11,"0123456789");
          cVar6 = pcVar11[(int)pcVar2];
          pcVar4 = pcVar11 + (int)pcVar2;
          if (cVar6 == '\0') {
            iVar1 = X509V3_get_value_int(value,local_2c);
            y = (ASN1_INTEGER *)0x0;
            if (iVar1 == 0) {
              ERR_put_error(0x22,0xa3,0x41,"crypto/x509v3/v3_asid.c",0x24f);
              y = (ASN1_STRING *)0x0;
              goto LAB_00172b5a;
            }
LAB_00172a94:
            iVar1 = X509v3_asid_add_id_or_range(a,uVar8,local_2c[0],y);
            if (iVar1 != 0) {
              local_2c[0] = (ASN1_INTEGER *)0x0;
              goto LAB_00172aa8;
            }
            iVar10 = 0x267;
          }
          else {
            pcVar5 = pcVar2;
            if (cVar6 == ' ' || cVar6 == '\t') {
              do {
                pcVar5 = pcVar4 + (1 - (int)pcVar11);
                pcVar4 = pcVar4 + 1;
                cVar6 = *pcVar4;
              } while (cVar6 == '\t' || cVar6 == ' ');
            }
            if (cVar6 != '-') {
              y = (ASN1_STRING *)0x0;
              ERR_put_error(0x22,0xa3,0xa2,"crypto/x509v3/v3_asid.c",0x23b);
              ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",
                                 value->value);
              goto LAB_00172b5a;
            }
            pcVar7 = pcVar5 + 1;
            pcVar4 = pcVar11 + (int)pcVar7;
            if (pcVar11[(int)pcVar7] == '\t' || pcVar11[(int)pcVar7] == ' ') {
              pcVar5 = pcVar5 + 2 + (int)pcVar11;
              do {
                pcVar4 = pcVar5;
                pcVar7 = pcVar4 + -(int)pcVar11;
                pcVar5 = pcVar4 + 1;
              } while (*pcVar4 == '\t' || *pcVar4 == ' ');
            }
            sVar3 = strspn(pcVar4,"0123456789");
            if ((pcVar11 + sVar3)[(int)pcVar7] != '\0') {
              y = (ASN1_STRING *)0x0;
              ERR_put_error(0x22,0xa3,0xa3,"crypto/x509v3/v3_asid.c",0x244);
              ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",
                                 value->value);
              goto LAB_00172b5a;
            }
            pcVar11 = CRYPTO_strdup(pcVar11,"crypto/x509v3/v3_asid.c",0x253);
            if (pcVar11 == (char *)0x0) {
              ERR_put_error(0x22,0xa3,0x41,"crypto/x509v3/v3_asid.c",0x255);
              y = (ASN1_STRING *)0x0;
              goto LAB_00172b5a;
            }
            pcVar11[(int)pcVar2] = '\0';
            local_2c[0] = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,pcVar11);
            y = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,pcVar11 + (int)pcVar7);
            CRYPTO_free(pcVar11);
            if ((local_2c[0] != (ASN1_INTEGER *)0x0) && (y != (ASN1_INTEGER *)0x0)) {
              iVar1 = ASN1_INTEGER_cmp(local_2c[0],y);
              if (iVar1 < 1) goto LAB_00172a94;
              ERR_put_error(0x22,0xa3,0x74,"crypto/x509v3/v3_asid.c",0x262);
              goto LAB_00172b5a;
            }
            iVar10 = 0x25d;
          }
          ERR_put_error(0x22,0xa3,0x41,"crypto/x509v3/v3_asid.c",iVar10);
          goto LAB_00172b5a;
        }
        pcVar11 = value->value;
        iVar1 = strcmp(pcVar11,"inherit");
        uVar9 = 0;
        uVar8 = 0;
        if (iVar1 != 0) goto LAB_001729c6;
LAB_00172b14:
        iVar1 = X509v3_asid_add_inherit(a,uVar9);
        if (iVar1 == 0) {
          ERR_put_error(0x22,0xa3,0xa5,"crypto/x509v3/v3_asid.c",0x22b);
          ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value
                            );
          y = (ASN1_STRING *)0x0;
          goto LAB_00172b5a;
        }
LAB_00172aa8:
        iVar10 = iVar10 + 1;
        iVar1 = OPENSSL_sk_num(param_3);
      } while (iVar10 < iVar1);
    }
    iVar10 = X509v3_asid_canonize(a);
    if (iVar10 == 0) {
      y = (ASN1_STRING *)0x0;
LAB_00172b5a:
      ASIdentifiers_free(a);
      ASN1_INTEGER_free(local_2c[0]);
      ASN1_INTEGER_free(y);
      return (ASIdentifiers *)0x0;
    }
  }
  return a;
}


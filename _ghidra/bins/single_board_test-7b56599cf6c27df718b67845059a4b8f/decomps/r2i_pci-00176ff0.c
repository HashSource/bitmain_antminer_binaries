
PROXY_CERT_INFO_EXTENSION * r2i_pci(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  stack_st_CONF_VALUE *psVar1;
  int iVar2;
  undefined4 *puVar3;
  stack_st_CONF_VALUE *section;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  PROXY_POLICY *pPVar8;
  PROXY_CERT_INFO_EXTENSION *pPVar9;
  int iVar10;
  ASN1_OBJECT *local_34;
  ASN1_STRING *local_30;
  ASN1_OCTET_STRING *local_2c [2];
  
  local_34 = (ASN1_OBJECT *)0x0;
  local_30 = (ASN1_INTEGER *)0x0;
  local_2c[0] = (ASN1_OCTET_STRING *)0x0;
  psVar1 = X509V3_parse_list(param_3);
  for (iVar10 = 0; iVar2 = OPENSSL_sk_num(psVar1), iVar10 < iVar2; iVar10 = iVar10 + 1) {
    puVar3 = (undefined4 *)OPENSSL_sk_value(psVar1,iVar10);
    pcVar7 = (char *)puVar3[1];
    if (pcVar7 == (char *)0x0) {
LAB_001770d2:
      ERR_put_error(0x22,0x9b,0x99,"crypto/x509v3/v3_pci.c",0x103);
      ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
      goto LAB_00177094;
    }
    if (*pcVar7 == '@') {
      section = X509V3_get_section(param_2,pcVar7 + 1);
      if (section == (stack_st_CONF_VALUE *)0x0) {
        ERR_put_error(0x22,0x9b,0x87,"crypto/x509v3/v3_pci.c",0x10d);
        ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
        goto LAB_00177094;
      }
      iVar2 = 0;
      while( true ) {
        iVar4 = OPENSSL_sk_num(section);
        if (iVar4 <= iVar2) break;
        uVar5 = OPENSSL_sk_value(section,iVar2);
        iVar4 = process_pci_value(uVar5,&local_34,&local_30,local_2c);
        iVar2 = iVar2 + 1;
        if (iVar4 == 0) {
          X509V3_section_free(param_2,section);
          goto LAB_00177094;
        }
      }
      X509V3_section_free(param_2,section);
    }
    else {
      if (puVar3[2] == 0) goto LAB_001770d2;
      iVar2 = process_pci_value(puVar3,&local_34,&local_30,local_2c);
      if (iVar2 == 0) {
        ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
        goto LAB_00177094;
      }
    }
  }
  if (local_34 == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0x22,0x9b,0x9a,"crypto/x509v3/v3_pci.c",0x124);
  }
  else {
    uVar6 = OBJ_obj2nid(local_34);
    if (((uVar6 & 0xfffffffd) == 0x299) && (local_2c[0] != (ASN1_OCTET_STRING *)0x0)) {
      ERR_put_error(0x22,0x9b,0x9f,"crypto/x509v3/v3_pci.c",0x12a);
    }
    else {
      pPVar9 = PROXY_CERT_INFO_EXTENSION_new();
      if (pPVar9 != (PROXY_CERT_INFO_EXTENSION *)0x0) {
        pPVar8 = pPVar9->proxyPolicy;
        pPVar8->policy = local_2c[0];
        pPVar8->policyLanguage = local_34;
        local_34 = (ASN1_OBJECT *)0x0;
        local_2c[0] = (ASN1_OCTET_STRING *)0x0;
        pPVar9->pcPathLengthConstraint = local_30;
        local_30 = (ASN1_STRING *)0x0;
        goto LAB_001770b4;
      }
      ERR_put_error(0x22,0x9b,0x41,"crypto/x509v3/v3_pci.c",0x130);
    }
  }
LAB_00177094:
  ASN1_OBJECT_free(local_34);
  pPVar9 = (PROXY_CERT_INFO_EXTENSION *)0x0;
  ASN1_INTEGER_free(local_30);
  local_30 = (ASN1_STRING *)0x0;
  ASN1_OCTET_STRING_free(local_2c[0]);
  local_2c[0] = (ASN1_OCTET_STRING *)0x0;
  PROXY_CERT_INFO_EXTENSION_free((PROXY_CERT_INFO_EXTENSION *)0x0);
LAB_001770b4:
  OPENSSL_sk_pop_free(psVar1,0x1794f9);
  return pPVar9;
}


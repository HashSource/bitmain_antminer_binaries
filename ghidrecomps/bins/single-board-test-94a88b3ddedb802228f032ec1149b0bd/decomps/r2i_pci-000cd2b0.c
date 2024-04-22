
PROXY_CERT_INFO_EXTENSION * r2i_pci(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  _STACK *st;
  int iVar1;
  undefined4 *puVar2;
  _STACK *section;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  char *pcVar6;
  PROXY_POLICY *pPVar7;
  PROXY_CERT_INFO_EXTENSION *pPVar8;
  int iVar9;
  ASN1_OBJECT *local_24;
  ASN1_INTEGER *local_20;
  ASN1_OCTET_STRING *local_1c;
  
  local_24 = (ASN1_OBJECT *)0x0;
  local_20 = (ASN1_INTEGER *)0x0;
  local_1c = (ASN1_OCTET_STRING *)0x0;
  st = &X509V3_parse_list(param_3)->stack;
  for (iVar9 = 0; iVar1 = sk_num(st), iVar9 < iVar1; iVar9 = iVar9 + 1) {
    puVar2 = (undefined4 *)sk_value(st,iVar9);
    pcVar6 = (char *)puVar2[1];
    if (pcVar6 == (char *)0x0) {
LAB_000cd37e:
      iVar9 = 0x99;
      iVar1 = 0xf1;
LAB_000cd388:
      ERR_put_error(0x22,0x9b,iVar9,DAT_000cd42c,iVar1);
LAB_000cd38e:
      ERR_add_error_data(6,DAT_000cd434,*puVar2,DAT_000cd438,puVar2[1],DAT_000cd430,puVar2[2]);
      goto LAB_000cd33e;
    }
    if (*pcVar6 != '@') {
      if (puVar2[2] == 0) goto LAB_000cd37e;
      iVar1 = process_pci_value(puVar2,&local_24,&local_20,&local_1c);
      if (iVar1 != 0) goto LAB_000cd2e0;
      goto LAB_000cd38e;
    }
    section = &X509V3_get_section(param_2,pcVar6 + 1)->stack;
    if (section == (_STACK *)0x0) {
      iVar1 = 0xfb;
      iVar9 = 0x87;
      goto LAB_000cd388;
    }
    iVar1 = 0;
    while( true ) {
      iVar3 = sk_num(section);
      if (iVar3 <= iVar1) break;
      pvVar4 = sk_value(section,iVar1);
      iVar3 = process_pci_value(pvVar4,&local_24,&local_20,&local_1c);
      iVar1 = iVar1 + 1;
      if (iVar3 == 0) {
        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
        goto LAB_000cd33e;
      }
    }
    X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
LAB_000cd2e0:
  }
  if (local_24 == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0x22,0x9b,0x9a,DAT_000cd42c,0x112);
  }
  else {
    uVar5 = OBJ_obj2nid(local_24);
    if (((uVar5 & 0xfffffffd) == 0x299) && (local_1c != (ASN1_OCTET_STRING *)0x0)) {
      ERR_put_error(0x22,0x9b,0x9f,DAT_000cd42c,0x118);
    }
    else {
      pPVar8 = PROXY_CERT_INFO_EXTENSION_new();
      if (pPVar8 != (PROXY_CERT_INFO_EXTENSION *)0x0) {
        pPVar7 = pPVar8->proxyPolicy;
        pPVar7->policy = local_1c;
        pPVar7->policyLanguage = local_24;
        local_24 = (ASN1_OBJECT *)0x0;
        local_1c = (ASN1_OCTET_STRING *)0x0;
        pPVar8->pcPathLengthConstraint = local_20;
        local_20 = (ASN1_INTEGER *)0x0;
        goto LAB_000cd364;
      }
      ERR_put_error(0x22,0x9b,0x41,DAT_000cd42c,0x11e);
    }
  }
LAB_000cd33e:
  if (local_24 != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(local_24);
    local_24 = (ASN1_OBJECT *)0x0;
  }
  if (local_20 != (ASN1_INTEGER *)0x0) {
    ASN1_INTEGER_free(local_20);
    local_20 = (ASN1_INTEGER *)0x0;
  }
  if (local_1c != (ASN1_OCTET_STRING *)0x0) {
    ASN1_OCTET_STRING_free(local_1c);
    local_1c = (ASN1_OCTET_STRING *)0x0;
  }
  pPVar8 = (PROXY_CERT_INFO_EXTENSION *)0x0;
LAB_000cd364:
  sk_pop_free(st,DAT_000cd428);
  return pPVar8;
}


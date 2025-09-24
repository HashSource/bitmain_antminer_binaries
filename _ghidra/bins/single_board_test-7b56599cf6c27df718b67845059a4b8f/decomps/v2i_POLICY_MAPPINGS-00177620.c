
int v2i_POLICY_MAPPINGS(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  POLICY_MAPPING *pPVar3;
  undefined4 *puVar4;
  int iVar5;
  ASN1_OBJECT *a;
  ASN1_OBJECT *a_00;
  
  iVar1 = OPENSSL_sk_num(param_3);
  iVar2 = OPENSSL_sk_new_reserve(0,iVar1);
  if (iVar2 == 0) {
    ERR_put_error(0x22,0x91,0x41,"crypto/x509v3/v3_pmaps.c",0x4c);
  }
  else if (0 < iVar1) {
    iVar5 = 0;
    do {
      puVar4 = (undefined4 *)OPENSSL_sk_value(param_3,iVar5);
      iVar5 = iVar5 + 1;
      if ((puVar4[2] == 0) || ((char *)puVar4[1] == (char *)0x0)) {
        a = (ASN1_OBJECT *)0x0;
        ERR_put_error(0x22,0x91,0x6e,"crypto/x509v3/v3_pmaps.c",0x54);
        a_00 = (ASN1_OBJECT *)0x0;
        ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
LAB_001776d6:
        ASN1_OBJECT_free(a_00);
        ASN1_OBJECT_free(a);
        OPENSSL_sk_pop_free(iVar2,0x1775f9);
        return 0;
      }
      a_00 = OBJ_txt2obj((char *)puVar4[1],0);
      a = OBJ_txt2obj((char *)puVar4[2],0);
      if (a == (ASN1_OBJECT *)0x0 || a_00 == (ASN1_OBJECT *)0x0) {
        ERR_put_error(0x22,0x91,0x6e,"crypto/x509v3/v3_pmaps.c",0x5c);
        ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
        goto LAB_001776d6;
      }
      pPVar3 = POLICY_MAPPING_new();
      if (pPVar3 == (POLICY_MAPPING *)0x0) {
        ERR_put_error(0x22,0x91,0x41,"crypto/x509v3/v3_pmaps.c",0x62);
        goto LAB_001776d6;
      }
      pPVar3->issuerDomainPolicy = a_00;
      pPVar3->subjectDomainPolicy = a;
      OPENSSL_sk_push(iVar2,pPVar3);
    } while (iVar1 != iVar5);
  }
  return iVar2;
}


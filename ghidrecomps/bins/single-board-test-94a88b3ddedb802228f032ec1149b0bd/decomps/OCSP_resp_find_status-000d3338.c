
int OCSP_resp_find_status
              (OCSP_BASICRESP *bs,OCSP_CERTID *id,int *status,int *reason,
              ASN1_GENERALIZEDTIME **revtime,ASN1_GENERALIZEDTIME **thisupd,
              ASN1_GENERALIZEDTIME **nextupd)

{
  OCSP_CERTID **ppOVar1;
  int iVar2;
  void *pvVar3;
  ASN1_ENUMERATED *a;
  long lVar4;
  ASN1_GENERALIZEDTIME **ppAVar5;
  int iVar6;
  _STACK *p_Var7;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
    p_Var7 = &bs->tbsResponseData->responses->stack;
    for (iVar6 = 0; iVar2 = sk_num(p_Var7), iVar6 < iVar2; iVar6 = iVar6 + 1) {
      ppOVar1 = (OCSP_CERTID **)sk_value(p_Var7,iVar6);
      iVar2 = OCSP_id_cmp(id,*ppOVar1);
      if (iVar2 == 0) {
        if (iVar6 < 0) {
          return 0;
        }
        iVar2 = -1;
        pvVar3 = sk_value(&bs->tbsResponseData->responses->stack,iVar6);
        if (pvVar3 != (void *)0x0) {
          iVar2 = **(int **)((int)pvVar3 + 4);
          if (iVar2 == 1) {
            ppAVar5 = (ASN1_GENERALIZEDTIME **)(*(int **)((int)pvVar3 + 4))[1];
            if (revtime != (ASN1_GENERALIZEDTIME **)0x0) {
              *revtime = *ppAVar5;
            }
            if (reason != (int *)0x0) {
              a = ppAVar5[1];
              if (a == (ASN1_ENUMERATED *)0x0) {
                *reason = -1;
              }
              else {
                lVar4 = ASN1_ENUMERATED_get(a);
                *reason = lVar4;
              }
            }
          }
          if (thisupd != (ASN1_GENERALIZEDTIME **)0x0) {
            *thisupd = *(ASN1_GENERALIZEDTIME **)((int)pvVar3 + 8);
          }
          if (nextupd != (ASN1_GENERALIZEDTIME **)0x0) {
            *nextupd = *(ASN1_GENERALIZEDTIME **)((int)pvVar3 + 0xc);
          }
        }
        if (status != (int *)0x0) {
          *status = iVar2;
          return 1;
        }
        return 1;
      }
    }
  }
  return 0;
}


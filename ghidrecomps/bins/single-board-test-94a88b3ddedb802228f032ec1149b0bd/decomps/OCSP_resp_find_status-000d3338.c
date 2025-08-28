
int OCSP_resp_find_status
              (OCSP_BASICRESP *bs,OCSP_CERTID *id,int *status,int *reason,
              ASN1_GENERALIZEDTIME **revtime,ASN1_GENERALIZEDTIME **thisupd,
              ASN1_GENERALIZEDTIME **nextupd)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  ASN1_ENUMERATED *a;
  long lVar4;
  int iVar5;
  _STACK *p_Var6;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
    p_Var6 = &bs->tbsResponseData->responses->stack;
    for (iVar5 = 0; iVar2 = sk_num(p_Var6), iVar5 < iVar2; iVar5 = iVar5 + 1) {
      puVar1 = (undefined4 *)sk_value(p_Var6,iVar5);
      iVar2 = OCSP_id_cmp(id,(OCSP_CERTID *)*puVar1);
      if (iVar2 == 0) {
        if (iVar5 < 0) {
          return 0;
        }
        iVar2 = -1;
        pvVar3 = sk_value(&bs->tbsResponseData->responses->stack,iVar5);
        if (pvVar3 != (void *)0x0) {
          iVar2 = **(int **)((int)pvVar3 + 4);
          if (iVar2 == 1) {
            puVar1 = (undefined4 *)(*(int **)((int)pvVar3 + 4))[1];
            if (revtime != (ASN1_GENERALIZEDTIME **)0x0) {
              *revtime = (ASN1_GENERALIZEDTIME *)*puVar1;
            }
            if (reason != (int *)0x0) {
              a = (ASN1_ENUMERATED *)puVar1[1];
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


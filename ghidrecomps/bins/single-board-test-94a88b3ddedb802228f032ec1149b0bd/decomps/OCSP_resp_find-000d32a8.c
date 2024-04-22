
int OCSP_resp_find(OCSP_BASICRESP *bs,OCSP_CERTID *id,int last)

{
  OCSP_CERTID **ppOVar1;
  int iVar2;
  int iVar3;
  _STACK *p_Var4;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
    if (last < 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = last + 1;
    }
    p_Var4 = &bs->tbsResponseData->responses->stack;
    for (; iVar2 = sk_num(p_Var4), iVar3 < iVar2; iVar3 = iVar3 + 1) {
      ppOVar1 = (OCSP_CERTID **)sk_value(p_Var4,iVar3);
      iVar2 = OCSP_id_cmp(id,*ppOVar1);
      if (iVar2 == 0) {
        return iVar3;
      }
    }
  }
  return -1;
}


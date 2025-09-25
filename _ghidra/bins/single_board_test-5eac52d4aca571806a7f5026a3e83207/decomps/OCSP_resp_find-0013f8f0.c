
int OCSP_resp_find(OCSP_BASICRESP *bs,OCSP_CERTID *id,int last)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  OCSP_RESPDATA *pOVar4;
  
  if (bs == (OCSP_BASICRESP *)0x0) {
    return -1;
  }
  if (last < 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = last + 1;
  }
  pOVar4 = bs[1].tbsResponseData;
  while( true ) {
    iVar2 = OPENSSL_sk_num(pOVar4);
    if (iVar2 <= iVar3) {
      return -1;
    }
    puVar1 = (undefined4 *)OPENSSL_sk_value(pOVar4,iVar3);
    iVar2 = OCSP_id_cmp(id,(OCSP_CERTID *)*puVar1);
    if (iVar2 == 0) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}


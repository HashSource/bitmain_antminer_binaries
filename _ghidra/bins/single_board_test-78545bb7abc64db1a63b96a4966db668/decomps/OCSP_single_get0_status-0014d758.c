
int OCSP_single_get0_status
              (OCSP_SINGLERESP *single,int *reason,ASN1_GENERALIZEDTIME **revtime,
              ASN1_GENERALIZEDTIME **thisupd,ASN1_GENERALIZEDTIME **nextupd)

{
  ASN1_ENUMERATED *a;
  long lVar1;
  OCSP_REVOKEDINFO *pOVar2;
  int iVar3;
  
  if (single == (OCSP_SINGLERESP *)0x0) {
    return -1;
  }
  iVar3 = single->certStatus->type;
  if (iVar3 == 1) {
    pOVar2 = (single->certStatus->value).revoked;
    if (revtime != (ASN1_GENERALIZEDTIME **)0x0) {
      *revtime = pOVar2->revocationTime;
    }
    if (reason != (int *)0x0) {
      a = pOVar2->revocationReason;
      if (a == (ASN1_ENUMERATED *)0x0) {
        *reason = -1;
      }
      else {
        lVar1 = ASN1_ENUMERATED_get(a);
        *reason = lVar1;
      }
    }
  }
  if (thisupd != (ASN1_GENERALIZEDTIME **)0x0) {
    *thisupd = single->thisUpdate;
  }
  if (nextupd != (ASN1_GENERALIZEDTIME **)0x0) {
    *nextupd = single->nextUpdate;
    return iVar3;
  }
  return iVar3;
}


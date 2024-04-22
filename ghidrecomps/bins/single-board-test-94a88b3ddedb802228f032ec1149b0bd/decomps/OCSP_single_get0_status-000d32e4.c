
int OCSP_single_get0_status
              (OCSP_SINGLERESP *single,int *reason,ASN1_GENERALIZEDTIME **revtime,
              ASN1_GENERALIZEDTIME **thisupd,ASN1_GENERALIZEDTIME **nextupd)

{
  OCSP_REVOKEDINFO *pOVar1;
  ASN1_ENUMERATED *a;
  long lVar2;
  int iVar3;
  
  if (single == (OCSP_SINGLERESP *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = single->certStatus->type;
    if (iVar3 == 1) {
      pOVar1 = (single->certStatus->value).revoked;
      if (revtime != (ASN1_GENERALIZEDTIME **)0x0) {
        *revtime = pOVar1->revocationTime;
      }
      if (reason != (int *)0x0) {
        a = pOVar1->revocationReason;
        if (a == (ASN1_ENUMERATED *)0x0) {
          *reason = -1;
        }
        else {
          lVar2 = ASN1_ENUMERATED_get(a);
          *reason = lVar2;
        }
      }
    }
    if (thisupd != (ASN1_GENERALIZEDTIME **)0x0) {
      *thisupd = single->thisUpdate;
    }
    if (nextupd != (ASN1_GENERALIZEDTIME **)0x0) {
      *nextupd = single->nextUpdate;
    }
  }
  return iVar3;
}


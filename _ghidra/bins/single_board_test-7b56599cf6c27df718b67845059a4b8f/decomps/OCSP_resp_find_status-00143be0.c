
int OCSP_resp_find_status
              (OCSP_BASICRESP *bs,OCSP_CERTID *id,int *status,int *reason,
              ASN1_GENERALIZEDTIME **revtime,ASN1_GENERALIZEDTIME **thisupd,
              ASN1_GENERALIZEDTIME **nextupd)

{
  int iVar1;
  OCSP_SINGLERESP *single;
  
  iVar1 = OCSP_resp_find(bs,id,-1);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else {
    single = OCSP_resp_get0(bs,iVar1);
    iVar1 = OCSP_single_get0_status(single,reason,revtime,thisupd,nextupd);
    if (status == (int *)0x0) {
      iVar1 = 1;
    }
    else {
      *status = iVar1;
      iVar1 = 1;
    }
  }
  return iVar1;
}


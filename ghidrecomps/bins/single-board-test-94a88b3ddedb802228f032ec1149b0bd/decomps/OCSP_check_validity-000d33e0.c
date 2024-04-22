
int OCSP_check_validity(ASN1_GENERALIZEDTIME *thisupd,ASN1_GENERALIZEDTIME *nextupd,long sec,
                       long maxsec)

{
  int iVar1;
  uint uVar2;
  int local_28;
  int local_24 [2];
  
  time(&local_28);
  iVar1 = ASN1_GENERALIZEDTIME_check(thisupd);
  if (iVar1 == 0) {
    ERR_put_error(0x27,0x73,0x7b,DAT_000d34f4,0x152);
    uVar2 = 0;
  }
  else {
    local_24[0] = local_28 + sec;
    iVar1 = X509_cmp_time(thisupd,local_24);
    if (iVar1 >= 1) {
      ERR_put_error(0x27,0x73,0x7e,DAT_000d34f4,0x157);
    }
    uVar2 = (uint)(iVar1 < 1);
    if (-1 < maxsec) {
      local_24[0] = local_28 - maxsec;
      iVar1 = X509_cmp_time(thisupd,local_24);
      if (iVar1 < 0) {
        uVar2 = 0;
        ERR_put_error(0x27,0x73,0x7f,DAT_000d34f4,0x162);
      }
    }
  }
  if (nextupd != (ASN1_GENERALIZEDTIME *)0x0) {
    iVar1 = ASN1_GENERALIZEDTIME_check(nextupd);
    if (iVar1 == 0) {
      ERR_put_error(0x27,0x73,0x7a,DAT_000d34f4,0x16d);
      iVar1 = ASN1_STRING_cmp(nextupd,thisupd);
      uVar2 = 0;
    }
    else {
      local_24[0] = local_28 - sec;
      iVar1 = X509_cmp_time(nextupd,local_24);
      if (iVar1 < 0) {
        uVar2 = 0;
        ERR_put_error(0x27,0x73,0x7d,DAT_000d34f4,0x172);
      }
      iVar1 = ASN1_STRING_cmp(nextupd,thisupd);
    }
    if (iVar1 < 0) {
      uVar2 = 0;
      ERR_put_error(0x27,0x73,0x7c,DAT_000d34f4,0x17a);
    }
  }
  return uVar2;
}


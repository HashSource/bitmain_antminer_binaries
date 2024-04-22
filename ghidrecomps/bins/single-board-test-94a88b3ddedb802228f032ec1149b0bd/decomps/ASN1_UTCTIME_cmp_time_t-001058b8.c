
int ASN1_UTCTIME_cmp_time_t(ASN1_UTCTIME *s,time_t t)

{
  int iVar1;
  time_t local_6c;
  int local_68;
  int local_64;
  undefined auStack_60 [44];
  undefined auStack_34 [52];
  
  if ((((s->type != 0x17) ||
       (local_6c = t, iVar1 = asn1_utctime_to_tm_part_0(auStack_60,s), iVar1 == 0)) ||
      (iVar1 = OPENSSL_gmtime(&local_6c,auStack_34), iVar1 == 0)) ||
     (iVar1 = OPENSSL_gmtime_diff(&local_68,&local_64,auStack_34,auStack_60), iVar1 == 0)) {
    return -2;
  }
  if (local_68 < 1) {
    if (local_68 == 0) {
      if (0 < local_64) goto LAB_001058fa;
      if (local_64 == 0) {
        return 0;
      }
    }
    iVar1 = -1;
  }
  else {
LAB_001058fa:
    iVar1 = 1;
  }
  return iVar1;
}


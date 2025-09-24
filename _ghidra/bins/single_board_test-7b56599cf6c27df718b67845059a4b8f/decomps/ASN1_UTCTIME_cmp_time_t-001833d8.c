
int ASN1_UTCTIME_cmp_time_t(ASN1_UTCTIME *s,time_t t)

{
  int iVar1;
  time_t local_74;
  int local_70;
  int local_6c;
  undefined1 auStack_68 [44];
  undefined1 auStack_3c [48];
  
  local_74 = t;
  iVar1 = asn1_utctime_to_tm(auStack_68,s);
  if (iVar1 != 0) {
    iVar1 = OPENSSL_gmtime(&local_74,auStack_3c);
    if ((iVar1 != 0) &&
       (iVar1 = OPENSSL_gmtime_diff(&local_70,&local_6c,auStack_3c,auStack_68), iVar1 != 0)) {
      if ((local_70 < 1) && (local_6c < 1)) {
        if (local_70 == 0 && local_6c == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = -1;
        }
        return iVar1;
      }
      return 1;
    }
  }
  return -2;
}



int ASN1_TIME_to_tm(int param_1,void *param_2)

{
  int iVar1;
  time_t atStack_14 [2];
  
  if (param_1 != 0) {
    iVar1 = asn1_time_to_tm(param_2,param_1);
    return iVar1;
  }
  time(atStack_14);
  memset(param_2,0,0x2c);
  iVar1 = OPENSSL_gmtime(atStack_14,param_2);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


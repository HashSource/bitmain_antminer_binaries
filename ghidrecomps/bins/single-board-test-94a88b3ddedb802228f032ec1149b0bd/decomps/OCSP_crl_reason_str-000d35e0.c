
char * OCSP_crl_reason_str(long s)

{
  int *piVar1;
  
  piVar1 = DAT_000d35fc;
  do {
    if (s == *piVar1) {
      return (char *)piVar1[1];
    }
    piVar1 = piVar1 + 2;
  } while (piVar1 < DAT_000d35fc + 0x10);
  return DAT_000d3600;
}


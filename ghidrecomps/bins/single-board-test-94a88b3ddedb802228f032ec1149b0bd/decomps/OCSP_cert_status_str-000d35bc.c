
char * OCSP_cert_status_str(long s)

{
  int *piVar1;
  
  piVar1 = DAT_000d35d8;
  do {
    if (s == *piVar1) {
      return (char *)piVar1[1];
    }
    piVar1 = piVar1 + 2;
  } while (piVar1 < DAT_000d35d8 + 6);
  return DAT_000d35dc;
}



char * OCSP_response_status_str(long s)

{
  int *piVar1;
  
  piVar1 = DAT_000d35b4;
  do {
    if (s == *piVar1) {
      return (char *)piVar1[1];
    }
    piVar1 = piVar1 + 2;
  } while (piVar1 < DAT_000d35b4 + 0xc);
  return DAT_000d35b8;
}


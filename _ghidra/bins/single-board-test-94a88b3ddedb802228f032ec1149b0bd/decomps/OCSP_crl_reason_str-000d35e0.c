
char * OCSP_crl_reason_str(long s)

{
  undefined1 *puVar1;
  
  puVar1 = reason_tbl_16214;
  do {
    if (s == *(int *)puVar1) {
      return *(char **)((int)puVar1 + 4);
    }
    puVar1 = (undefined1 *)((int)puVar1 + 8);
  } while (puVar1 < "%*sCertificate ID:\n");
  return "(UNKNOWN)";
}


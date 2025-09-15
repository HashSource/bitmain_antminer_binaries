
char * OCSP_cert_status_str(long s)

{
  undefined1 *puVar1;
  
  puVar1 = cstat_tbl_16210;
  do {
    if (s == *(int *)puVar1) {
      return *(char **)((int)puVar1 + 4);
    }
    puVar1 = (undefined1 *)((int)puVar1 + 8);
  } while (puVar1 < reason_tbl_16214);
  return "(UNKNOWN)";
}


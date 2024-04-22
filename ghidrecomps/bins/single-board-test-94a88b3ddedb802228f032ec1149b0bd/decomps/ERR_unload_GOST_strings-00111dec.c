
void ERR_unload_GOST_strings(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = DAT_00111e14;
  piVar1 = DAT_00111e10;
  if (*DAT_00111e10 == 0) {
    ERR_unload_strings(*DAT_00111e14,(ERR_STRING_DATA *)(DAT_00111e10 + 1));
    ERR_unload_strings(*piVar2,(ERR_STRING_DATA *)(piVar1 + 0x59));
    *piVar1 = 1;
  }
  return;
}


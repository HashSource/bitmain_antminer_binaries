
void ERR_load_GOST_strings(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  ERR_STRING_DATA *str;
  
  piVar1 = DAT_00111de4;
  if (*DAT_00111de4 == 0) {
    iVar3 = ERR_get_next_error_library();
    *piVar1 = iVar3;
  }
  piVar2 = DAT_00111de8;
  if (*DAT_00111de8 == 0) {
    return;
  }
  str = (ERR_STRING_DATA *)(DAT_00111de8 + 1);
  *DAT_00111de8 = 0;
  ERR_load_strings(*piVar1,str);
  ERR_load_strings(*piVar1,(ERR_STRING_DATA *)(piVar2 + 0x59));
  return;
}



undefined4 surewarehk_destroy(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = DAT_000dd13c;
  piVar1 = DAT_000dd138;
  if (*DAT_000dd138 == 0) {
    ERR_unload_strings(*(int *)(DAT_000dd13c + 4),(ERR_STRING_DATA *)(DAT_000dd138 + 1));
    ERR_unload_strings(*(int *)(iVar2 + 4),(ERR_STRING_DATA *)(piVar1 + 0x1f));
    ERR_unload_strings(0,(ERR_STRING_DATA *)(piVar1 + 0x31));
    *piVar1 = 1;
  }
  return 1;
}


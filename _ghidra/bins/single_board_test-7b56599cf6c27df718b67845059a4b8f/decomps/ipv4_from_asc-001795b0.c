
undefined4 ipv4_from_asc(undefined1 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  
  iVar1 = __isoc99_sscanf(param_2,"%d.%d.%d.%d%n",&local_24,&local_20,&local_1c,&local_18,&local_14)
  ;
  if ((((iVar1 == 4) && (local_24 < 0x100)) && (local_20 < 0x100)) &&
     (((local_1c < 0x100 && (local_18 < 0x100)) &&
      ((*(char *)(param_2 + local_14) == '\0' ||
       (iVar1 = ossl_ctype_check(*(char *)(param_2 + local_14),8), iVar1 != 0)))))) {
    uVar2 = 1;
    *param_1 = (char)local_24;
    param_1[1] = (char)local_20;
    param_1[2] = (char)local_1c;
    param_1[3] = (char)local_18;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


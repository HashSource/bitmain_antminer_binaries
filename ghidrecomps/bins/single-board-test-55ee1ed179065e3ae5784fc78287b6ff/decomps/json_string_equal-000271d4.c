
undefined json_string_equal(undefined4 param_1,undefined4 param_2)

{
  char *__s1;
  char *__s2;
  int iVar1;
  undefined uVar2;
  bool bVar3;
  
  __s1 = (char *)json_string_value(param_1);
  __s2 = (char *)json_string_value(param_2);
  iVar1 = strcmp(__s1,__s2);
  bVar3 = iVar1 != 0;
  if (bVar3) {
    iVar1 = 0;
  }
  uVar2 = (undefined)iVar1;
  if (!bVar3) {
    uVar2 = 1;
  }
  return uVar2;
}


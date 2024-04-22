
undefined4 opt_set_bool_arg(char *param_1,undefined *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcasecmp(param_1,"yes");
  if ((iVar1 == 0) || (iVar1 = strcasecmp(param_1,"true"), iVar1 == 0)) {
    *param_2 = 1;
    return 0;
  }
  iVar1 = strcasecmp(param_1,(char *)&DAT_000584ec);
  if ((iVar1 != 0) && (iVar1 = strcasecmp(param_1,"false"), iVar1 != 0)) {
    uVar2 = opt_invalid_argument(param_1);
    return uVar2;
  }
  *param_2 = 0;
  return 0;
}


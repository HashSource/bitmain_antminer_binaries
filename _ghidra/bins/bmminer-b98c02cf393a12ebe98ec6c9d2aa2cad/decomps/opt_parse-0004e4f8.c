
bool opt_parse(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_1c [2];
  
  opt_argv0 = *param_2;
  local_1c[0] = 0;
  do {
    iVar1 = parse_one(param_1,param_2,local_1c,param_3);
  } while (iVar1 == 1);
  return iVar1 == 0;
}


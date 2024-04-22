
int parse_json(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x38) = 0;
  lex_scan(param_1,param_3,param_3,0,param_4);
  if (((param_2 & 4) == 0) && ((*(uint *)(param_1 + 0x3c) & 0xffffffdf) != 0x5b)) {
    error_set(param_3,param_1,"\'[\' or \'{\' expected");
    return 0;
  }
  iVar1 = parse_value(param_1,param_2,param_3);
  if (iVar1 == 0) {
    return 0;
  }
  if ((-1 < (int)(param_2 << 0x1e)) && (lex_scan(param_1,param_3), *(int *)(param_1 + 0x3c) != 0)) {
    error_set(param_3,param_1,"end of file expected");
    if (*(int *)(iVar1 + 4) == -1) {
      return 0;
    }
    iVar2 = *(int *)(iVar1 + 4) + -1;
    *(int *)(iVar1 + 4) = iVar2;
    if (iVar2 != 0) {
      return 0;
    }
    json_delete(iVar1);
    return 0;
  }
  if (param_3 == 0) {
    return iVar1;
  }
  *(undefined4 *)(param_3 + 8) = *(undefined4 *)(param_1 + 0x24);
  return iVar1;
}


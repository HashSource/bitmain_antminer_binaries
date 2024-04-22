
int parse_json(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  lex_scan(param_1,param_3);
  if ((((param_2 & 4) == 0) && (*(int *)(param_1 + 0x34) != 0x5b)) &&
     (*(int *)(param_1 + 0x34) != 0x7b)) {
    error_set(param_3,param_1,"\'[\' or \'{\' expected");
    iVar1 = 0;
  }
  else {
    iVar1 = parse_value(param_1,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else if (((param_2 & 2) == 0) && (lex_scan(param_1,param_3), *(int *)(param_1 + 0x34) != 0)) {
      error_set(param_3,param_1,"end of file expected");
      json_decref(iVar1);
      iVar1 = 0;
    }
    else if (param_3 != 0) {
      *(undefined4 *)(param_3 + 8) = *(undefined4 *)(param_1 + 0x24);
    }
  }
  return iVar1;
}


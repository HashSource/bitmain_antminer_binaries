
int parse_array(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = json_array();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    lex_scan(param_1,param_3);
    if (*(int *)(param_1 + 0x34) != 0x5d) {
      while (*(int *)(param_1 + 0x34) != 0) {
        iVar2 = parse_value(param_1,param_2,param_3);
        if (iVar2 == 0) goto LAB_0002534e;
        iVar3 = json_array_append(iVar1,iVar2);
        if (iVar3 != 0) {
          json_decref(iVar2);
          goto LAB_0002534e;
        }
        json_decref(iVar2);
        lex_scan(param_1,param_3);
        if (*(int *)(param_1 + 0x34) != 0x2c) break;
        lex_scan(param_1,param_3);
      }
      if (*(int *)(param_1 + 0x34) != 0x5d) {
        error_set(param_3,param_1,"\']\' expected");
LAB_0002534e:
        json_decref(iVar1);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


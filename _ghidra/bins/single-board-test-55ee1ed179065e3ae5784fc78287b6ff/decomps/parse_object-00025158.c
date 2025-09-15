
int parse_object(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = json_object();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    lex_scan(param_1,param_3);
    if (*(int *)(param_1 + 0x34) != 0x7d) {
      while (*(int *)(param_1 + 0x34) == 0x100) {
        iVar2 = lex_steal_string(param_1);
        if (iVar2 == 0) {
          return 0;
        }
        if (((param_2 & 1) != 0) && (iVar3 = json_object_get(iVar1,iVar2), iVar3 != 0)) {
          jsonp_free(iVar2);
          error_set(param_3,param_1,"duplicate object key");
          goto LAB_00025294;
        }
        lex_scan(param_1,param_3);
        if (*(int *)(param_1 + 0x34) != 0x3a) {
          jsonp_free(iVar2);
          error_set(param_3,param_1,"\':\' expected");
          goto LAB_00025294;
        }
        lex_scan(param_1,param_3);
        iVar3 = parse_value(param_1,param_2,param_3);
        if (iVar3 == 0) {
          jsonp_free(iVar2);
          goto LAB_00025294;
        }
        iVar4 = json_object_set_nocheck(iVar1,iVar2,iVar3);
        if (iVar4 != 0) {
          jsonp_free(iVar2);
          json_decref(iVar3);
          goto LAB_00025294;
        }
        json_decref(iVar3);
        jsonp_free(iVar2);
        lex_scan(param_1,param_3);
        if (*(int *)(param_1 + 0x34) != 0x2c) {
          if (*(int *)(param_1 + 0x34) == 0x7d) {
            return iVar1;
          }
          error_set(param_3,param_1,"\'}\' expected");
          goto LAB_00025294;
        }
        lex_scan(param_1,param_3);
      }
      error_set(param_3,param_1,"string or \'}\' expected");
LAB_00025294:
      json_decref(iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}



undefined4 json_loadf(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  code *local_60;
  int iStack_5c;
  undefined local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_3c;
  undefined auStack_38 [12];
  undefined4 local_2c;
  undefined4 local_24;
  
  pcVar3 = "<stdin>";
  if (stdin != param_1) {
    pcVar3 = "<stream>";
  }
  jsonp_error_init(param_3,pcVar3);
  if (param_1 == 0) {
    error_set(param_3,0,"wrong arguments");
    uVar2 = 0;
  }
  else {
    local_60 = fgetc;
    local_58 = 0;
    local_50 = 0;
    local_4c = 0;
    local_44 = 0;
    local_3c = 0;
    local_48 = 1;
    iStack_5c = param_1;
    iVar1 = strbuffer_init(auStack_38);
    if (iVar1 != 0) {
      return 0;
    }
    local_24 = 0xffffffff;
    local_2c = param_2;
    uVar2 = parse_json(&local_60,param_2,param_3);
    lex_close(&local_60);
  }
  return uVar2;
}


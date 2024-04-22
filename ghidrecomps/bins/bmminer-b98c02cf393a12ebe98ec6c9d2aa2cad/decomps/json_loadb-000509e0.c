
undefined4 json_loadb(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int *local_5c;
  undefined local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_3c;
  undefined auStack_38 [12];
  undefined4 local_2c;
  undefined4 local_24;
  
  jsonp_error_init(param_4,"<buffer>");
  if (param_1 == 0) {
    error_set(param_4,0,"wrong arguments");
    uVar2 = 0;
  }
  else {
    local_5c = &local_6c;
    local_60 = 0x4fc51;
    local_64 = 0;
    local_58 = 0;
    local_50 = 0;
    local_4c = 0;
    local_44 = 0;
    local_3c = 0;
    local_48 = 1;
    local_6c = param_1;
    local_68 = param_2;
    iVar1 = strbuffer_init(auStack_38);
    if (iVar1 != 0) {
      return 0;
    }
    local_24 = 0xffffffff;
    local_2c = param_3;
    uVar2 = parse_json(&local_60,param_3,param_4);
    lex_close(&local_60);
  }
  return uVar2;
}



undefined4 json_load_callback(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_470;
  undefined *local_46c;
  undefined local_468;
  undefined4 local_460;
  undefined4 local_45c;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_44c;
  undefined auStack_448 [12];
  undefined4 local_43c;
  undefined4 local_434;
  undefined auStack_428 [1032];
  int local_20;
  undefined4 local_1c;
  
  memset(auStack_428,0,0x410);
  local_20 = param_1;
  local_1c = param_2;
  jsonp_error_init(param_4,"<callback>");
  if (param_1 == 0) {
    error_set(param_4,0,"wrong arguments");
    uVar2 = 0;
  }
  else {
    local_470 = 0x4fc6d;
    local_46c = auStack_428;
    local_458 = 1;
    local_468 = 0;
    local_460 = 0;
    local_45c = 0;
    local_454 = 0;
    local_44c = 0;
    iVar1 = strbuffer_init(auStack_448);
    if (iVar1 != 0) {
      return 0;
    }
    local_434 = 0xffffffff;
    local_43c = param_3;
    uVar2 = parse_json(&local_470,param_3,param_4);
    lex_close(&local_470);
  }
  return uVar2;
}



undefined4 json_load_callback(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined auStack_468 [1032];
  int local_60;
  undefined4 local_5c;
  undefined auStack_58 [68];
  undefined4 local_14;
  
  memset(auStack_468,0,0x410);
  local_60 = param_1;
  local_5c = param_2;
  jsonp_error_init(param_4,"<callback>");
  if (param_1 == 0) {
    error_set(param_4,0,"wrong arguments");
    local_14 = 0;
  }
  else {
    iVar1 = lex_init(auStack_58,0x25809,auStack_468);
    if (iVar1 == 0) {
      local_14 = parse_json(auStack_58,param_3,param_4);
      lex_close(auStack_58);
    }
    else {
      local_14 = 0;
    }
  }
  return local_14;
}


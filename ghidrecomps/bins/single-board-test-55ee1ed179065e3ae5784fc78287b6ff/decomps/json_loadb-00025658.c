
undefined4 json_loadb(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined auStack_50 [68];
  undefined4 local_c;
  
  jsonp_error_init(param_4,"<buffer>");
  if (param_1 == 0) {
    error_set(param_4,0,"wrong arguments");
    local_c = 0;
  }
  else {
    local_54 = 0;
    local_5c = param_1;
    local_58 = param_2;
    iVar1 = lex_init(auStack_50,0x25615,&local_5c);
    if (iVar1 == 0) {
      local_c = parse_json(auStack_50,param_3,param_4);
      lex_close(auStack_50);
    }
    else {
      local_c = 0;
    }
  }
  return local_c;
}


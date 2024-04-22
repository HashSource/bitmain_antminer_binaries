
undefined4 json_loads(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_58;
  undefined4 local_54;
  undefined auStack_50 [68];
  undefined4 local_c;
  
  jsonp_error_init(param_3,"<string>");
  if (param_1 == 0) {
    error_set(param_3,0,"wrong arguments");
    local_c = 0;
  }
  else {
    local_54 = 0;
    local_58 = param_1;
    iVar1 = lex_init(auStack_50,0x25551,&local_58);
    if (iVar1 == 0) {
      local_c = parse_json(auStack_50,param_2,param_3);
      lex_close(auStack_50);
    }
    else {
      local_c = 0;
    }
  }
  return local_c;
}


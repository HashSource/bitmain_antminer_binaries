
undefined4 json_loadf(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_50 [64];
  undefined4 local_10;
  char *local_c;
  
  if (param_1 == stdin) {
    local_c = "<stdin>";
  }
  else {
    local_c = "<stream>";
  }
  jsonp_error_init(param_3,local_c);
  if (param_1 == 0) {
    error_set(param_3,0,"wrong arguments");
    local_10 = 0;
  }
  else {
    iVar1 = lex_init(auStack_50,fgetc,param_1);
    if (iVar1 == 0) {
      local_10 = parse_json(auStack_50,param_2,param_3);
      lex_close(auStack_50);
    }
    else {
      local_10 = 0;
    }
  }
  return local_10;
}


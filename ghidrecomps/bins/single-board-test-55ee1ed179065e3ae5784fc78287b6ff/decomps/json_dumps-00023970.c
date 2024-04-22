
undefined4 json_dumps(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_18 [12];
  undefined4 local_c;
  
  iVar1 = strbuffer_init(auStack_18);
  if (iVar1 == 0) {
    iVar1 = json_dump_callback(param_1,0x22f99,auStack_18,param_2);
    if (iVar1 == 0) {
      uVar2 = strbuffer_value(auStack_18);
      local_c = jsonp_strdup(uVar2);
    }
    else {
      local_c = 0;
    }
    strbuffer_close(auStack_18);
  }
  else {
    local_c = 0;
  }
  return local_c;
}


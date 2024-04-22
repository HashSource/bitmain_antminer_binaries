
undefined4 json_dumps(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_1c [12];
  
  iVar1 = strbuffer_init(auStack_1c);
  if (iVar1 == 0) {
    iVar1 = json_dump_callback(param_1,0x4ec29,auStack_1c,param_2);
    uVar2 = 0;
    if (iVar1 == 0) {
      strbuffer_value(auStack_1c);
      uVar2 = jsonp_strdup();
    }
    strbuffer_close(auStack_1c);
    return uVar2;
  }
  return 0;
}


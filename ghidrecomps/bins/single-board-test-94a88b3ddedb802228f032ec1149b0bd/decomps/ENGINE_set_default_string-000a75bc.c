
int ENGINE_set_default_string(ENGINE *e,char *def_list)

{
  int iVar1;
  uint local_14;
  
  local_14 = 0;
  iVar1 = CONF_parse_list(def_list,0x2c,1,DAT_000a7608,&local_14);
  if (iVar1 == 0) {
    ERR_put_error(0x26,0xbd,0x96,DAT_000a760c,0x8e);
    ERR_add_error_data(2,DAT_000a7610,def_list);
    iVar1 = 0;
  }
  else {
    iVar1 = ENGINE_set_default(e,local_14);
  }
  return iVar1;
}


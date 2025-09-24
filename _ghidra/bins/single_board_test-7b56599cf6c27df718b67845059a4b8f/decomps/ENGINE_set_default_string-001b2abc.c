
int ENGINE_set_default_string(ENGINE *e,char *def_list)

{
  int iVar1;
  uint local_14;
  
  local_14 = 0;
  iVar1 = CONF_parse_list(def_list,0x2c,1,(list_cb *)0x1b28bd,&local_14);
  if (iVar1 != 0) {
    iVar1 = ENGINE_set_default(e,local_14);
    return iVar1;
  }
  ERR_put_error(0x26,0xbd,0x96,"crypto/engine/eng_fat.c",0x56);
  ERR_add_error_data(2,&DAT_00235d00,def_list);
  return 0;
}


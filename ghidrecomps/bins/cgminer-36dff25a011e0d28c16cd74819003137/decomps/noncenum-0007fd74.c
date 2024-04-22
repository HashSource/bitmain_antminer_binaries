
void noncenum(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  uint uVar1;
  _Bool _Var2;
  api_data *paVar3;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  _Bool io_open;
  api_data *root;
  
  message(io_data,0x10,0,(char *)0x0,isjson);
  if (isjson) {
    uVar1 = 0xdf30;
  }
  else {
    uVar1 = 0xdf40;
  }
  _Var2 = io_add(io_data,(char *)(uVar1 | 0xa0000));
  paVar3 = api_add_string((api_data *)0x0,"10min nonce",nonce_num10_string,false);
  paVar3 = api_add_string(paVar3,"30min nonce",nonce_num30_string,false);
  paVar3 = api_add_string(paVar3,"60min nonce",nonce_num60_string,false);
  print_data(io_data,paVar3,isjson,false);
  if ((isjson) && (_Var2)) {
    io_close(io_data);
  }
  return;
}


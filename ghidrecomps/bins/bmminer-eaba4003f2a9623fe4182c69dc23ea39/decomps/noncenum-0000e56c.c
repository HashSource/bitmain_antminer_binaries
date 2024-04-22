
void noncenum(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  api_data *paVar2;
  char *buf;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  _Bool io_open;
  api_data *root;
  
  message(io_data,0x10,0,(char *)0x0,isjson);
  if (isjson) {
    buf = ",\"NONCENUM\":[";
  }
  else {
    buf = "NONCENUM,";
  }
  _Var1 = io_add(io_data,buf);
  paVar2 = api_add_string((api_data *)0x0,"10min nonce",nonce_num10_string,false);
  paVar2 = api_add_string(paVar2,"30min nonce",nonce_num30_string,false);
  paVar2 = api_add_string(paVar2,"60min nonce",nonce_num60_string,false);
  print_data(io_data,paVar2,isjson,false);
  if ((isjson) && (_Var1)) {
    io_close(io_data);
  }
  return;
}


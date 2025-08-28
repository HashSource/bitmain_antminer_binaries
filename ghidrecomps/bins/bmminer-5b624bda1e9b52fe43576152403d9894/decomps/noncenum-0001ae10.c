
/* WARNING: Unknown calling convention */

void noncenum(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  api_data *paVar2;
  
  message(io_data,0x10,0,(char *)0x0,isjson);
  if (isjson) {
    _Var1 = io_add(io_data,",\"NONCENUM\":[");
    paVar2 = api_add_string((api_data *)0x0,"10min nonce",nonce_num10_string,false);
    paVar2 = api_add_string(paVar2,"30min nonce",nonce_num30_string,false);
    paVar2 = api_add_string(paVar2,"60min nonce",nonce_num60_string,false);
    print_data(io_data,paVar2,true,false);
    if (_Var1) {
      io_data->close = true;
    }
    return;
  }
  io_add(io_data,"NONCENUM,");
  paVar2 = api_add_string((api_data *)0x0,"10min nonce",nonce_num10_string,isjson);
  paVar2 = api_add_string(paVar2,"30min nonce",nonce_num30_string,isjson);
  paVar2 = api_add_string(paVar2,"60min nonce",nonce_num60_string,isjson);
  print_data(io_data,paVar2,isjson,isjson);
  return;
}


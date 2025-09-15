
void pgacount(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  uint uVar1;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  int count;
  _Bool io_open;
  api_data *root;
  
  root = (api_data *)0x0;
  count = 0;
  message(io_data,0x3b,0,(char *)0x0,isjson);
  if (isjson) {
    uVar1 = 0xdf70;
  }
  else {
    uVar1 = 0xdf7c;
  }
  io_open = io_add(io_data,(char *)(uVar1 | 0xa0000));
  root = api_add_int(root,"Count",&count,false);
  root = print_data(io_data,root,isjson,false);
  if ((isjson) && (io_open != false)) {
    io_close(io_data);
  }
  return;
}


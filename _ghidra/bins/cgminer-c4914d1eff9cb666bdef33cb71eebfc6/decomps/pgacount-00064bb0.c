
void pgacount(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char *buf;
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
    buf = ",\"PGAS\":[";
  }
  else {
    buf = "PGAS,";
  }
  io_open = io_add(io_data,buf);
  root = api_add_int(root,"Count",&count,false);
  root = print_data(io_data,root,isjson,false);
  if ((isjson) && (io_open != false)) {
    io_close(io_data);
  }
  return;
}


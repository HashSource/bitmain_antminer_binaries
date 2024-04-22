
/* WARNING: Unknown calling convention */

void asccount(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  _Bool io_open;
  api_data *paVar2;
  int count;
  
  count = 0;
  message(io_data,0x68,0,(char *)0x0,isjson);
  if (isjson) {
    _Var1 = io_add(io_data,DAT_0001a03c);
    paVar2 = api_add_int((api_data *)0x0,DAT_0001a040,&count,false);
    print_data(io_data,paVar2,true,false);
    if (_Var1) {
      io_data->close = true;
    }
  }
  else {
    io_add(io_data,DAT_0001a044);
    paVar2 = api_add_int((api_data *)0x0,DAT_0001a040,&count,isjson);
    print_data(io_data,paVar2,isjson,isjson);
  }
  return;
}


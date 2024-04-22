
/* WARNING: Unknown calling convention */

void apiversion(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  _Bool io_open;
  api_data *paVar2;
  
  message(io_data,0x16,0,(char *)0x0,isjson);
  if (isjson) {
    _Var1 = io_add(io_data,DAT_0001b0c0);
    paVar2 = api_add_string((api_data *)0x0,DAT_0001b0c4,DAT_0001b0c8,false);
    paVar2 = api_add_const(paVar2,DAT_0001b0cc,DAT_0001b0d0,false);
    paVar2 = api_add_string(paVar2,DAT_0001b0d4,DAT_0001b0d8,false);
    paVar2 = api_add_string(paVar2,DAT_0001b0dc,DAT_0001b0e0,false);
    paVar2 = api_add_string(paVar2,DAT_0001b0e4,DAT_0001b0e8,false);
    print_data(io_data,paVar2,true,false);
    if (_Var1) {
      io_data->close = true;
    }
    return;
  }
  io_add(io_data,DAT_0001b0ec);
  paVar2 = api_add_string((api_data *)0x0,DAT_0001b0c4,DAT_0001b0c8,isjson);
  paVar2 = api_add_const(paVar2,DAT_0001b0cc,DAT_0001b0d0,isjson);
  paVar2 = api_add_string(paVar2,DAT_0001b0d4,DAT_0001b0d8,isjson);
  paVar2 = api_add_string(paVar2,DAT_0001b0dc,DAT_0001b0e0,isjson);
  paVar2 = api_add_string(paVar2,DAT_0001b0e4,DAT_0001b0e8,isjson);
  print_data(io_data,paVar2,isjson,isjson);
  return;
}


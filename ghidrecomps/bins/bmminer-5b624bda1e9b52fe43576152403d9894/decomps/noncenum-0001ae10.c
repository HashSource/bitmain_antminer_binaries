
/* WARNING: Unknown calling convention */

void noncenum(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  _Bool io_open;
  api_data *paVar2;
  
  message(io_data,0x10,0,(char *)0x0,isjson);
  if (isjson) {
    _Var1 = io_add(io_data,DAT_0001aea0);
    paVar2 = api_add_string((api_data *)0x0,DAT_0001aea4,DAT_0001aea8,false);
    paVar2 = api_add_string(paVar2,DAT_0001aeac,DAT_0001aeb0,false);
    paVar2 = api_add_string(paVar2,DAT_0001aeb4,DAT_0001aeb8,false);
    print_data(io_data,paVar2,true,false);
    if (_Var1) {
      io_data->close = true;
    }
    return;
  }
  io_add(io_data,DAT_0001aebc);
  paVar2 = api_add_string((api_data *)0x0,DAT_0001aea4,DAT_0001aea8,isjson);
  paVar2 = api_add_string(paVar2,DAT_0001aeac,DAT_0001aeb0,isjson);
  paVar2 = api_add_string(paVar2,DAT_0001aeb4,DAT_0001aeb8,isjson);
  print_data(io_data,paVar2,isjson,isjson);
  return;
}



/* WARNING: Unknown calling convention */

void minerconfig(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  _Bool io_open;
  api_data *paVar2;
  char *buf;
  undefined uVar3;
  int asccount;
  int pgacount;
  
  asccount = 0;
  pgacount = 0;
  message(io_data,0x21,0,(char *)0x0,isjson);
  buf = DAT_0001afa8;
  if (isjson) {
    buf = DAT_0001afa4;
  }
  _Var1 = io_add(io_data,buf);
  paVar2 = api_add_int((api_data *)0x0,DAT_0001afac,&asccount,false);
  paVar2 = api_add_int(paVar2,DAT_0001afb0,&pgacount,false);
  paVar2 = api_add_int(paVar2,DAT_0001afb4,DAT_0001afb8,false);
  paVar2 = api_add_const(paVar2,DAT_0001afc0,*(char **)(DAT_0001afbc + *DAT_0001b004 * 4),false);
  paVar2 = api_add_int(paVar2,DAT_0001afc4,DAT_0001afc8,false);
  paVar2 = api_add_const(paVar2,DAT_0001afcc,DAT_0001afd0,false);
  paVar2 = api_add_const(paVar2,DAT_0001afd4,DAT_0001afd8,false);
  paVar2 = api_add_bool(paVar2,DAT_0001afdc,DAT_0001afe0,false);
  paVar2 = api_add_int(paVar2,DAT_0001afe4,DAT_0001afe8,false);
  paVar2 = api_add_int(paVar2,DAT_0001afec,DAT_0001aff0,false);
  paVar2 = api_add_int(paVar2,DAT_0001aff4,DAT_0001aff8,false);
  paVar2 = api_add_const(paVar2,DAT_0001affc,DAT_0001b000,false);
  uVar3 = 0;
  print_data(io_data,paVar2,isjson,false);
  if (_Var1 && isjson) {
    uVar3 = true;
  }
  if (_Var1 && isjson) {
    io_data->close = (_Bool)uVar3;
  }
  return;
}


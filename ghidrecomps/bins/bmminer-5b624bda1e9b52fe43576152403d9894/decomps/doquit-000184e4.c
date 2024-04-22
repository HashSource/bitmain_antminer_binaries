
/* WARNING: Unknown calling convention */

void doquit(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  undefined *puVar1;
  
  if (isjson) {
    io_put(io_data,DAT_00018508);
  }
  else {
    io_put(io_data,DAT_00018500);
  }
  puVar1 = DAT_00018504;
  *DAT_00018504 = 1;
  puVar1[2] = 1;
  return;
}



/* WARNING: Unknown calling convention */

void dorestart(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  undefined *puVar1;
  
  if (isjson) {
    io_put(io_data,DAT_000184e0);
  }
  else {
    io_put(io_data,DAT_000184d8);
  }
  puVar1 = DAT_000184dc;
  *DAT_000184dc = 1;
  puVar1[1] = 1;
  return;
}



/* WARNING: Unknown calling convention */

void dorestart(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  if (isjson) {
    io_put(io_data,"{\"STATUS\":\"RESTART\"");
  }
  else {
    io_put(io_data,"RESTART");
  }
  bye = true;
  do_a_restart = true;
  return;
}


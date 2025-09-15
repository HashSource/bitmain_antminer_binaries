
/* WARNING: Unknown calling convention */

void usbstats(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  message(io_data,0x58,0,(char *)0x0,isjson);
  return;
}


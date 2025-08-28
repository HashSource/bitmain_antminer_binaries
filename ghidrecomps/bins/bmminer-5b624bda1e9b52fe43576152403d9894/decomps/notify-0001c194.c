
/* WARNING: Unknown calling convention */

void notify(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char cVar1;
  cgpu_info *cgpu;
  int id;
  int iVar2;
  
  if (total_devices == 0) {
    message(io_data,10,0,(char *)0x0,isjson);
    return;
  }
  message(io_data,0x3c,0,(char *)0x0,isjson);
  cVar1 = isjson;
  if (isjson) {
    cVar1 = io_add(io_data,",\"NOTIFY\":[");
  }
  if (0 < total_devices) {
    id = 0;
    do {
      cgpu = get_devices(id);
      iVar2 = id + 1;
      notifystatus(io_data,id,cgpu,isjson,group);
      id = iVar2;
    } while (iVar2 < total_devices);
  }
  if (cVar1 != '\0') {
    io_data->close = true;
  }
  return;
}


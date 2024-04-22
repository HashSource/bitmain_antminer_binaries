
/* WARNING: Unknown calling convention */

void notify(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int *piVar1;
  char cVar2;
  cgpu_info *cgpu_00;
  cgpu_info *cgpu;
  int id;
  int iVar3;
  
  piVar1 = DAT_0001c210;
  if (*DAT_0001c210 == 0) {
    message(io_data,10,0,(char *)0x0,isjson);
    return;
  }
  message(io_data,0x3c,0,(char *)0x0,isjson);
  cVar2 = isjson;
  if (isjson) {
    cVar2 = io_add(io_data,DAT_0001c214);
  }
  if (0 < *piVar1) {
    id = 0;
    do {
      cgpu_00 = get_devices(id);
      iVar3 = id + 1;
      notifystatus(io_data,id,cgpu_00,isjson,group);
      id = iVar3;
    } while (iVar3 < *piVar1);
  }
  if (cVar2 != '\0') {
    io_data->close = true;
  }
  return;
}


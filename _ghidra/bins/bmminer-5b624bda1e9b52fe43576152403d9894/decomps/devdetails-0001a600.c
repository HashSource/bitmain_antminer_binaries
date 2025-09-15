
/* WARNING: Unknown calling convention */

void devdetails(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char cVar1;
  cgpu_info *pcVar2;
  char *pcVar3;
  undefined1 precom;
  int iVar4;
  api_data *paVar5;
  int local_24;
  
  if (total_devices == 0) {
    message(io_data,10,0,(char *)0x0,isjson);
  }
  else {
    message(io_data,0x45,0,(char *)0x0,isjson);
    cVar1 = isjson;
    if (isjson) {
      cVar1 = io_add(io_data,",\"DEVDETAILS\":[");
    }
    local_24 = 0;
    if (0 < total_devices) {
      paVar5 = (api_data *)0x0;
      do {
        pcVar2 = get_devices(local_24);
        paVar5 = api_add_int(paVar5,"DEVDETAILS",&local_24,false);
        paVar5 = api_add_string(paVar5,"Name",pcVar2->drv->name,false);
        paVar5 = api_add_int(paVar5,"ID",&pcVar2->device_id,false);
        paVar5 = api_add_string(paVar5,"Driver",pcVar2->drv->dname,false);
        pcVar3 = pcVar2->kname;
        if (pcVar3 == (char *)0x0) {
          pcVar3 = "";
        }
        paVar5 = api_add_const(paVar5,"Kernel",pcVar3,false);
        pcVar3 = pcVar2->name;
        if (pcVar3 == (char *)0x0) {
          pcVar3 = "";
        }
        paVar5 = api_add_const(paVar5,"Model",pcVar3,false);
        pcVar3 = pcVar2->device_path;
        if (pcVar3 == (char *)0x0) {
          pcVar3 = "";
        }
        paVar5 = api_add_const(paVar5,"Device Path",pcVar3,false);
        precom = isjson;
        if (isjson) {
          iVar4 = local_24;
          if (local_24 < 1) {
            iVar4 = 0;
          }
          precom = (undefined1)iVar4;
          if (0 < local_24) {
            precom = true;
          }
        }
        paVar5 = print_data(io_data,paVar5,isjson,(_Bool)precom);
        local_24 = local_24 + 1;
      } while (local_24 < total_devices);
    }
    if (cVar1 != '\0') {
      io_data->close = true;
    }
  }
  return;
}


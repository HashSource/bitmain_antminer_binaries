
/* WARNING: Unknown calling convention */
/* Local variable io_open:_Bool[r0:1] conflicts with parameter, skipped. */

void devdetails(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  cgpu_info *pcVar4;
  cgpu_info *cgpu;
  char *pcVar5;
  undefined precom;
  int iVar6;
  api_data *paVar7;
  int i;
  
  piVar1 = DAT_0001a6f0;
  if (*DAT_0001a6f0 == 0) {
    message(io_data,10,0,(char *)0x0,isjson);
  }
  else {
    message(io_data,0x45,0,(char *)0x0,isjson);
    cVar3 = isjson;
    if (isjson) {
      cVar3 = io_add(io_data,DAT_0001a714);
    }
    i = 0;
    if (0 < *piVar1) {
      paVar7 = (api_data *)0x0;
      do {
        pcVar4 = get_devices(i);
        pcVar2 = DAT_0001a6f8;
        paVar7 = api_add_int(paVar7,DAT_0001a6f4,&i,false);
        paVar7 = api_add_string(paVar7,DAT_0001a6fc,pcVar4->drv->name,false);
        paVar7 = api_add_int(paVar7,DAT_0001a700,&pcVar4->device_id,false);
        paVar7 = api_add_string(paVar7,DAT_0001a704,pcVar4->drv->dname,false);
        pcVar5 = pcVar4->kname;
        if (pcVar4->kname == (char *)0x0) {
          pcVar5 = pcVar2;
        }
        paVar7 = api_add_const(paVar7,DAT_0001a708,pcVar5,false);
        pcVar5 = pcVar4->name;
        if (pcVar4->name == (char *)0x0) {
          pcVar5 = pcVar2;
        }
        paVar7 = api_add_const(paVar7,DAT_0001a70c,pcVar5,false);
        pcVar5 = pcVar4->device_path;
        if (pcVar4->device_path == (char *)0x0) {
          pcVar5 = pcVar2;
        }
        paVar7 = api_add_const(paVar7,DAT_0001a710,pcVar5,false);
        precom = isjson;
        if (isjson) {
          iVar6 = i;
          if (i < 1) {
            iVar6 = 0;
          }
          precom = (undefined)iVar6;
          if (0 < i) {
            precom = true;
          }
        }
        paVar7 = print_data(io_data,paVar7,isjson,(_Bool)precom);
        i = i + 1;
      } while (i < *piVar1);
    }
    if (cVar3 != '\0') {
      io_data->close = true;
    }
  }
  return;
}


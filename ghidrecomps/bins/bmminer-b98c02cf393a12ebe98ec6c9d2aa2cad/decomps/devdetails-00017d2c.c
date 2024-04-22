
void devdetails(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int local_2c [2];
  
  if (total_devices == 0) {
    message(param_1,10,0,0,param_4);
    return;
  }
  message(param_1,0x45,0,0,param_4);
  if (param_4 == 0) {
    if (total_devices < 1) {
      return;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = io_add(param_1,",\"DEVDETAILS\":[");
    if (total_devices < 1) goto LAB_00017e40;
  }
  local_2c[0] = 0;
  uVar4 = 0;
  do {
    iVar1 = get_devices(local_2c[0]);
    uVar4 = api_add_data_full(uVar4,"DEVDETAILS",6,local_2c,0);
    uVar4 = api_add_data_full(uVar4,&DAT_0005813c,1,*(undefined4 *)(*(int *)(iVar1 + 4) + 8),0);
    uVar4 = api_add_data_full(uVar4,"ID",6,iVar1 + 8,0);
    uVar4 = api_add_data_full(uVar4,"Driver",1,*(undefined4 *)(*(int *)(iVar1 + 4) + 4),0);
    puVar3 = *(undefined1 **)(iVar1 + 0xa8);
    if (*(undefined1 **)(iVar1 + 0xa8) == (undefined1 *)0x0) {
      puVar3 = &DAT_000609ec;
    }
    uVar4 = api_add_data_full(uVar4,"Kernel",2,puVar3,0);
    puVar3 = *(undefined1 **)(iVar1 + 0xc);
    if (*(undefined1 **)(iVar1 + 0xc) == (undefined1 *)0x0) {
      puVar3 = &DAT_000609ec;
    }
    uVar4 = api_add_data_full(uVar4,"Model",2,puVar3,0);
    puVar3 = *(undefined1 **)(iVar1 + 0x10);
    if (*(undefined1 **)(iVar1 + 0x10) == (undefined1 *)0x0) {
      puVar3 = &DAT_000609ec;
    }
    uVar4 = api_add_data_full(uVar4,"Device Path",2,puVar3,0);
    iVar1 = param_4;
    if (param_4 != 0) {
      if (local_2c[0] < 1) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
    }
    uVar4 = print_data(param_1,uVar4,param_4,iVar1);
    local_2c[0] = local_2c[0] + 1;
  } while (local_2c[0] < total_devices);
LAB_00017e40:
  if (iVar2 != 0) {
    *(undefined *)(param_1 + 0xd) = 1;
  }
  return;
}


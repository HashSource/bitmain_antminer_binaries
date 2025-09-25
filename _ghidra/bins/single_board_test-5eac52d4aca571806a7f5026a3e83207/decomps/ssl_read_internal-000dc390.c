
undefined4 ssl_read_internal(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    ERR_put_error(0x14,0x20b,0x114,"ssl/ssl_lib.c",0x6d7);
    return 0xffffffff;
  }
  uVar3 = *(uint *)(param_1 + 0x28) & 2;
  if (uVar3 != 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    return 0;
  }
  if (*(int *)(param_1 + 0x68) == 8 || *(int *)(param_1 + 0x68) == 1) {
    ERR_put_error(0x14,0x20b,0x42,"ssl/ssl_lib.c",0x6e2);
    return 0;
  }
  ossl_statem_check_finish_init(param_1,0);
  if ((-1 < *(int *)(param_1 + 0x4f0) << 0x17) || (iVar1 = ASYNC_get_current_job(), iVar1 != 0)) {
    uVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x20))(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  iVar1 = *(int *)(param_1 + 0xf48);
  local_1c = *(undefined4 *)(*(int *)(param_1 + 4) + 0x20);
  local_2c = param_1;
  local_28 = param_2;
  local_24 = param_3;
  local_20 = uVar3;
  if (iVar1 == 0) {
    iVar1 = ASYNC_WAIT_CTX_new();
    *(int *)(param_1 + 0xf48) = iVar1;
    if (iVar1 == 0) {
      local_30 = 0xffffffff;
      goto LAB_000dc452;
    }
  }
  *(undefined4 *)(param_1 + 0x14) = 1;
  uVar2 = ASYNC_start_job(param_1 + 0xf44,iVar1,&local_30,0xdb44d,&local_2c,0x14);
  switch(uVar2) {
  case 0:
    *(undefined4 *)(param_1 + 0x14) = 1;
    local_30 = 0xffffffff;
    ERR_put_error(0x14,0x185,0x195,"ssl/ssl_lib.c",0x6ab);
    break;
  case 1:
    local_30 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x14) = 6;
    break;
  case 2:
    local_30 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x14) = 5;
    break;
  case 3:
    *(undefined4 *)(param_1 + 0xf44) = 0;
    break;
  default:
    *(undefined4 *)(param_1 + 0x14) = 1;
    ERR_put_error(0x14,0x185,0x44,"ssl/ssl_lib.c",0x6b8);
    local_30 = 0xffffffff;
  }
LAB_000dc452:
  *param_4 = *(undefined4 *)(param_1 + 0xf4c);
  return local_30;
}


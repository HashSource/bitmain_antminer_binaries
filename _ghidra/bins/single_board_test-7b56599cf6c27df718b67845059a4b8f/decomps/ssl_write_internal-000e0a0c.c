
undefined4 ssl_write_internal(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    ERR_put_error(0x14,0x20c,0x114,"ssl/ssl_lib.c",0x797);
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x28) & 1) != 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    ERR_put_error(0x14,0x20c,0xcf,"ssl/ssl_lib.c",0x79d);
    return 0xffffffff;
  }
  if (*(uint *)(param_1 + 0x68) == 1 || (*(uint *)(param_1 + 0x68) & 0xfffffffd) == 8) {
    ERR_put_error(0x14,0x20c,0x42,"ssl/ssl_lib.c",0x7a4);
    return 0;
  }
  ossl_statem_check_finish_init(param_1,1);
  if ((-1 < *(int *)(param_1 + 0x4f0) << 0x17) || (iVar2 = ASYNC_get_current_job(), iVar2 != 0)) {
    uVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x28))(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  iVar2 = *(int *)(param_1 + 0xf48);
  local_1c = *(undefined4 *)(*(int *)(param_1 + 4) + 0x28);
  local_20 = 1;
  local_2c = param_1;
  local_28 = param_2;
  local_24 = param_3;
  if (iVar2 == 0) {
    iVar2 = ASYNC_WAIT_CTX_new();
    *(int *)(param_1 + 0xf48) = iVar2;
    if (iVar2 == 0) {
      local_30 = 0xffffffff;
      goto LAB_000e0acc;
    }
  }
  *(undefined4 *)(param_1 + 0x14) = 1;
  uVar1 = ASYNC_start_job(param_1 + 0xf44,iVar2,&local_30,0xdf69d,&local_2c,0x14);
  switch(uVar1) {
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
LAB_000e0acc:
  *param_4 = *(undefined4 *)(param_1 + 0xf4c);
  return local_30;
}


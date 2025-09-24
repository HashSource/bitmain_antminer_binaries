
uint SSL_peek_ex(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    ERR_put_error(0x14,0x20a,0x114,"ssl/ssl_lib.c",0x75b);
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x28) << 0x1e;
  if (iVar1 < 0) {
    return 0;
  }
  if ((-1 < *(int *)(param_1 + 0x4f0) << 0x17) ||
     (local_18 = ASYNC_get_current_job(iVar1), local_18 != 0)) {
    local_28 = (**(code **)(*(int *)(param_1 + 4) + 0x24))(param_1,param_2,param_3,param_4);
    goto LAB_000e090e;
  }
  iVar1 = *(int *)(param_1 + 0xf48);
  local_14 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x24);
  local_24 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  if (iVar1 == 0) {
    iVar1 = ASYNC_WAIT_CTX_new();
    *(int *)(param_1 + 0xf48) = iVar1;
    if (iVar1 != 0) goto LAB_000e093c;
    local_28 = 0xffffffff;
  }
  else {
LAB_000e093c:
    *(undefined4 *)(param_1 + 0x14) = 1;
    uVar2 = ASYNC_start_job(param_1 + 0xf44,iVar1,&local_28,0xdf69d,&local_24,0x14);
    switch(uVar2) {
    case 0:
      *(undefined4 *)(param_1 + 0x14) = 1;
      ERR_put_error(0x14,0x185,0x195,"ssl/ssl_lib.c",0x6ab);
      local_28 = 0xffffffff;
      break;
    case 1:
      local_28 = 0xffffffff;
      *(undefined4 *)(param_1 + 0x14) = 6;
      break;
    case 2:
      local_28 = 0xffffffff;
      *(undefined4 *)(param_1 + 0x14) = 5;
      break;
    case 3:
      *(undefined4 *)(param_1 + 0xf44) = 0;
      break;
    default:
      *(undefined4 *)(param_1 + 0x14) = 1;
      ERR_put_error(0x14,0x185,0x44,"ssl/ssl_lib.c",0x6b8);
      local_28 = 0xffffffff;
    }
  }
  *param_4 = *(undefined4 *)(param_1 + 0xf4c);
LAB_000e090e:
  return local_28 & ~((int)local_28 >> 0x1f);
}


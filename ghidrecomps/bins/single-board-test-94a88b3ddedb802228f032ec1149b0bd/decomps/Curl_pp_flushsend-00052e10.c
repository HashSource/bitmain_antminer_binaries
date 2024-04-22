
int Curl_pp_flushsend(int param_1)

{
  int iVar1;
  undefined4 local_28;
  undefined4 uStack_24;
  int local_1c [2];
  
  iVar1 = Curl_write(*(int *)(param_1 + 0x2c),*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x154),
                     *(int *)(param_1 + 0x14) +
                     (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18)),*(int *)(param_1 + 0x18),
                     local_1c);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x18) == local_1c[0]) {
      (**DAT_00052e68)(*(undefined4 *)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      curlx_tvnow(&local_28);
      *(undefined4 *)(param_1 + 0x20) = local_28;
      *(undefined4 *)(param_1 + 0x24) = uStack_24;
    }
    else {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - local_1c[0];
    }
  }
  return iVar1;
}


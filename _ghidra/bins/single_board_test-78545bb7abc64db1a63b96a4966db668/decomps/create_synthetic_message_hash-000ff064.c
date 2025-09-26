
undefined4
create_synthetic_message_hash
          (int param_1,undefined1 *param_2,undefined1 *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined1 *local_64 [2];
  undefined4 local_5c;
  undefined1 auStack_58 [68];
  
  local_5c = 0;
  local_64[0] = param_3;
  if (param_2 == (undefined1 *)0x0) {
    local_64[0] = param_2;
    iVar1 = ssl3_digest_cached_records();
    if (iVar1 == 0) {
      return 0;
    }
    param_2 = auStack_58;
    iVar1 = ssl_handshake_hash(param_1,param_2,0x40,local_64);
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = ssl3_init_finished_mac(param_1);
  if (iVar1 != 0) {
    local_5c = CONCAT31(local_5c._1_3_,0xfe);
    local_5c = CONCAT13((char)local_64[0],(undefined3)local_5c);
    iVar1 = ssl3_finish_mac(param_1,&local_5c,4);
    if ((iVar1 != 0) && (iVar1 = ssl3_finish_mac(param_1,param_2,local_64[0]), iVar1 != 0)) {
      if (param_4 == 0) {
        return 1;
      }
      iVar1 = ssl3_finish_mac(param_1,param_4,param_5);
      if (iVar1 != 0) {
        iVar1 = ssl3_finish_mac(param_1,*(undefined4 *)(*(int *)(param_1 + 0x6c) + 4),
                                *(int *)(*(int *)(param_1 + 0x7c) + 0x208) + 4);
        if (iVar1 != 0) {
          return 1;
        }
        return 0;
      }
    }
  }
  return 0;
}


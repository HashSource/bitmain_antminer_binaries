
undefined4 check_hw(int param_1,undefined4 param_2,undefined param_3,char param_4)

{
  undefined4 uVar1;
  undefined auStack_e4 [32];
  undefined auStack_c4 [140];
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined local_34;
  byte local_d;
  uint local_c;
  
  local_c = 0;
  memset(auStack_c4,0,0xb4);
  memset(auStack_c4,0,0xb4);
  memcpy(auStack_c4,(void *)(param_1 + 8),0xb4);
  local_38 = (undefined)param_2;
  local_37 = (undefined)((uint)param_2 >> 8);
  local_36 = (undefined)((uint)param_2 >> 0x10);
  local_35 = (undefined)((uint)param_2 >> 0x18);
  if (Conf._116_4_ == 0x6bd) {
    local_34 = param_3;
  }
  decred_hash_simple(auStack_e4,auStack_c4);
  local_d = target_to_dcrdiff(auStack_e4);
  if (local_d < 0x26) {
    if (param_4 != '\0') {
      printf("\n%s: Got a HW!\n","check_hw");
      printf("\tdata=");
      for (local_c = 0; local_c < 0xb4; local_c = local_c + 1) {
        printf("%02x",(uint)*(byte *)(param_1 + local_c + 8));
      }
      printf("\treturn nonce=0x%08x, but it should be nonce=0x%08x\n",param_2,
             *(undefined4 *)(param_1 + 4));
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


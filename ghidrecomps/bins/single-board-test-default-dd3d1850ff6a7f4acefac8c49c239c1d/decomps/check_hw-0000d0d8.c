
/* WARNING: Type propagation algorithm not settling */

undefined4 check_hw(int param_1,uint param_2,char param_3)

{
  undefined4 uVar1;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 local_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined1 auStack_11c [12];
  undefined1 auStack_110 [180];
  uint local_5c [9];
  byte local_38 [32];
  byte *local_18;
  uint local_14;
  
  local_14 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  local_38[8] = 0;
  local_38[9] = 0;
  local_38[10] = 0;
  local_38[0xb] = 0;
  local_38[0xc] = 0;
  local_38[0xd] = 0;
  local_38[0xe] = 0;
  local_38[0xf] = 0;
  local_38[0x10] = 0;
  local_38[0x11] = 0;
  local_38[0x12] = 0;
  local_38[0x13] = 0;
  local_38[0x14] = 0;
  local_38[0x15] = 0;
  local_38[0x16] = 0;
  local_38[0x17] = 0;
  local_38[0x18] = 0;
  local_38[0x19] = 0;
  local_38[0x1a] = 0;
  local_38[0x1b] = 0;
  local_38[0x1c] = 0;
  local_38[0x1d] = 0;
  local_38[0x1e] = 0;
  local_38[0x1f] = 0;
  local_5c[1] = 0;
  local_5c[2] = 0;
  local_5c[3] = 0;
  local_5c[4] = 0;
  local_5c[5] = 0;
  local_5c[6] = 0;
  local_5c[7] = 0;
  local_5c[8] = 0;
  local_18 = local_38;
  local_5c[0] = param_2 << 0x18 |
                param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8;
  local_13c = *(undefined4 *)(param_1 + 0x14);
  uStack_138 = *(undefined4 *)(param_1 + 0x18);
  uStack_134 = *(undefined4 *)(param_1 + 0x1c);
  uStack_130 = *(undefined4 *)(param_1 + 0x20);
  local_12c = *(undefined4 *)(param_1 + 0x24);
  uStack_128 = *(undefined4 *)(param_1 + 0x28);
  uStack_124 = *(undefined4 *)(param_1 + 0x2c);
  uStack_120 = *(undefined4 *)(param_1 + 0x30);
  rev(&local_13c,0x20);
  local_144 = 0x50;
  local_140 = 0;
  memcpy(local_38,(void *)(param_1 + 8),0xc);
  rev(local_38,0xc);
  flip_swab(auStack_11c,local_38,0xc);
  memcpy(local_38,local_5c,4);
  rev(local_38,4);
  flip_swab(auStack_110,local_38,4);
  sha2_finish(&local_144,local_38);
  memset(&local_144,0,0xe8);
  sha2(local_38,0x20,local_5c + 1);
  flip32(local_38,local_5c + 1);
  if (*(int *)(local_18 + 0x1c) == 0) {
    uVar1 = 0;
  }
  else {
    if (param_3 != '\0') {
      printf("\n%s: Got a HW!\n","check_hw");
      printf("hash1=0x");
      for (local_14 = 0; local_14 < 0x20; local_14 = local_14 + 1) {
        printf("%02x",(uint)local_38[local_14]);
      }
      putchar(10);
      printf("midstate=0x");
      for (local_14 = 0; local_14 < 0x20; local_14 = local_14 + 1) {
        printf("%02x",(uint)*(byte *)(param_1 + local_14 + 0x14));
      }
      printf("\tdata2=0x");
      for (local_14 = 0; local_14 < 0xc; local_14 = local_14 + 1) {
        printf("%02x",(uint)*(byte *)(param_1 + local_14 + 8));
      }
      printf("\treturn nonce=0x%08x, but it should be nonce=0x%08x\n",param_2,
             *(undefined4 *)(param_1 + 4));
    }
    uVar1 = 1;
  }
  return uVar1;
}


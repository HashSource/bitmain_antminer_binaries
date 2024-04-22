
void sha2_finish(uint *param_1,undefined *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  byte local_1d;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined local_19;
  
  uVar4 = *param_1;
  uVar2 = uVar4 & 0x3f;
  iVar5 = uVar4 << 3;
  iVar1 = param_1[1] << 3;
  local_1d = (byte)(uVar4 >> 0x1d) | (byte)iVar1;
  local_19 = (undefined)iVar5;
  local_1b = (undefined)((uint)iVar5 >> 0x10);
  local_1e = (undefined)((uint)iVar1 >> 8);
  if (uVar2 < 0x38) {
    iVar3 = 0x38 - uVar2;
  }
  else {
    iVar3 = 0x78 - uVar2;
  }
  local_1a = (undefined)((uint)iVar5 >> 8);
  local_20 = (undefined)((uint)iVar1 >> 0x18);
  local_1f = (undefined)((uint)iVar1 >> 0x10);
  local_1c = (undefined)((uint)iVar5 >> 0x18);
  sha2_update(param_1,&sha2_padding,iVar3);
  sha2_update(param_1,&local_20,8);
  *param_2 = *(undefined *)((int)param_1 + 0xb);
  param_2[1] = (char)*(undefined2 *)((int)param_1 + 10);
  param_2[2] = (char)(param_1[2] >> 8);
  param_2[3] = (char)param_1[2];
  param_2[4] = *(undefined *)((int)param_1 + 0xf);
  param_2[5] = (char)*(undefined2 *)((int)param_1 + 0xe);
  param_2[6] = (char)(param_1[3] >> 8);
  param_2[7] = (char)param_1[3];
  param_2[8] = *(undefined *)((int)param_1 + 0x13);
  param_2[9] = (char)*(undefined2 *)((int)param_1 + 0x12);
  param_2[10] = (char)(param_1[4] >> 8);
  param_2[0xb] = (char)param_1[4];
  param_2[0xc] = *(undefined *)((int)param_1 + 0x17);
  param_2[0xd] = (char)*(undefined2 *)((int)param_1 + 0x16);
  param_2[0xe] = (char)(param_1[5] >> 8);
  param_2[0xf] = (char)param_1[5];
  param_2[0x10] = *(undefined *)((int)param_1 + 0x1b);
  param_2[0x11] = (char)*(undefined2 *)((int)param_1 + 0x1a);
  param_2[0x12] = (char)(param_1[6] >> 8);
  param_2[0x13] = (char)param_1[6];
  param_2[0x14] = *(undefined *)((int)param_1 + 0x1f);
  param_2[0x15] = (char)*(undefined2 *)((int)param_1 + 0x1e);
  param_2[0x16] = (char)(param_1[7] >> 8);
  param_2[0x17] = (char)param_1[7];
  param_2[0x18] = *(undefined *)((int)param_1 + 0x23);
  param_2[0x19] = (char)*(undefined2 *)((int)param_1 + 0x22);
  param_2[0x1a] = (char)(param_1[8] >> 8);
  param_2[0x1b] = (char)param_1[8];
  param_2[0x1c] = *(undefined *)((int)param_1 + 0x27);
  param_2[0x1d] = (char)*(undefined2 *)((int)param_1 + 0x26);
  param_2[0x1e] = (char)(param_1[9] >> 8);
  param_2[0x1f] = (char)param_1[9];
  return;
}


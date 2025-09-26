
void curve448_scalar_encode(undefined1 *param_1,undefined4 *param_2)

{
  *param_1 = (char)*param_2;
  param_1[1] = (char)((uint)*param_2 >> 8);
  param_1[2] = (char)*(undefined2 *)((int)param_2 + 2);
  param_1[3] = *(undefined1 *)((int)param_2 + 3);
  param_1[4] = (char)param_2[1];
  param_1[5] = (char)((uint)param_2[1] >> 8);
  param_1[6] = (char)*(undefined2 *)((int)param_2 + 6);
  param_1[7] = *(undefined1 *)((int)param_2 + 7);
  param_1[8] = (char)param_2[2];
  param_1[9] = (char)((uint)param_2[2] >> 8);
  param_1[10] = (char)*(undefined2 *)((int)param_2 + 10);
  param_1[0xb] = *(undefined1 *)((int)param_2 + 0xb);
  param_1[0xc] = (char)param_2[3];
  param_1[0xd] = (char)((uint)param_2[3] >> 8);
  param_1[0xe] = (char)*(undefined2 *)((int)param_2 + 0xe);
  param_1[0xf] = *(undefined1 *)((int)param_2 + 0xf);
  param_1[0x10] = (char)param_2[4];
  param_1[0x11] = (char)((uint)param_2[4] >> 8);
  param_1[0x12] = (char)*(undefined2 *)((int)param_2 + 0x12);
  param_1[0x13] = *(undefined1 *)((int)param_2 + 0x13);
  param_1[0x14] = (char)param_2[5];
  param_1[0x15] = (char)((uint)param_2[5] >> 8);
  param_1[0x16] = (char)*(undefined2 *)((int)param_2 + 0x16);
  param_1[0x17] = *(undefined1 *)((int)param_2 + 0x17);
  param_1[0x18] = (char)param_2[6];
  param_1[0x19] = (char)((uint)param_2[6] >> 8);
  param_1[0x1a] = (char)*(undefined2 *)((int)param_2 + 0x1a);
  param_1[0x1b] = *(undefined1 *)((int)param_2 + 0x1b);
  param_1[0x1c] = (char)param_2[7];
  param_1[0x1d] = (char)((uint)param_2[7] >> 8);
  param_1[0x1e] = (char)*(undefined2 *)((int)param_2 + 0x1e);
  param_1[0x1f] = *(undefined1 *)((int)param_2 + 0x1f);
  param_1[0x20] = (char)param_2[8];
  param_1[0x21] = (char)((uint)param_2[8] >> 8);
  param_1[0x22] = (char)*(undefined2 *)((int)param_2 + 0x22);
  param_1[0x23] = *(undefined1 *)((int)param_2 + 0x23);
  param_1[0x24] = (char)param_2[9];
  param_1[0x25] = (char)((uint)param_2[9] >> 8);
  param_1[0x26] = (char)*(undefined2 *)((int)param_2 + 0x26);
  param_1[0x27] = *(undefined1 *)((int)param_2 + 0x27);
  param_1[0x28] = (char)param_2[10];
  param_1[0x29] = (char)((uint)param_2[10] >> 8);
  param_1[0x2a] = (char)*(undefined2 *)((int)param_2 + 0x2a);
  param_1[0x2b] = *(undefined1 *)((int)param_2 + 0x2b);
  param_1[0x2c] = (char)param_2[0xb];
  param_1[0x2d] = (char)((uint)param_2[0xb] >> 8);
  param_1[0x2e] = (char)*(undefined2 *)((int)param_2 + 0x2e);
  param_1[0x2f] = *(undefined1 *)((int)param_2 + 0x2f);
  param_1[0x30] = (char)param_2[0xc];
  param_1[0x31] = (char)((uint)param_2[0xc] >> 8);
  param_1[0x32] = (char)*(undefined2 *)((int)param_2 + 0x32);
  param_1[0x33] = *(undefined1 *)((int)param_2 + 0x33);
  param_1[0x34] = (char)param_2[0xd];
  param_1[0x35] = (char)((uint)param_2[0xd] >> 8);
  param_1[0x36] = (char)*(undefined2 *)((int)param_2 + 0x36);
  param_1[0x37] = *(undefined1 *)((int)param_2 + 0x37);
  return;
}


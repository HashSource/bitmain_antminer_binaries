
void gost_get_key(undefined4 *param_1,undefined *param_2)

{
  *param_2 = (char)*param_1;
  param_2[1] = (char)((uint)*param_1 >> 8);
  param_2[2] = (char)*(undefined2 *)((int)param_1 + 2);
  param_2[3] = *(undefined *)((int)param_1 + 3);
  param_2[4] = (char)param_1[1];
  param_2[5] = (char)((uint)param_1[1] >> 8);
  param_2[6] = (char)*(undefined2 *)((int)param_1 + 6);
  param_2[7] = *(undefined *)((int)param_1 + 7);
  param_2[8] = (char)param_1[2];
  param_2[9] = (char)((uint)param_1[2] >> 8);
  param_2[10] = (char)*(undefined2 *)((int)param_1 + 10);
  param_2[0xb] = *(undefined *)((int)param_1 + 0xb);
  param_2[0xc] = (char)param_1[3];
  param_2[0xd] = (char)((uint)param_1[3] >> 8);
  param_2[0xe] = (char)*(undefined2 *)((int)param_1 + 0xe);
  param_2[0xf] = *(undefined *)((int)param_1 + 0xf);
  param_2[0x10] = (char)param_1[4];
  param_2[0x11] = (char)((uint)param_1[4] >> 8);
  param_2[0x12] = (char)*(undefined2 *)((int)param_1 + 0x12);
  param_2[0x13] = *(undefined *)((int)param_1 + 0x13);
  param_2[0x14] = (char)param_1[5];
  param_2[0x15] = (char)((uint)param_1[5] >> 8);
  param_2[0x16] = (char)*(undefined2 *)((int)param_1 + 0x16);
  param_2[0x17] = *(undefined *)((int)param_1 + 0x17);
  param_2[0x18] = (char)param_1[6];
  param_2[0x19] = (char)((uint)param_1[6] >> 8);
  param_2[0x1a] = (char)*(undefined2 *)((int)param_1 + 0x1a);
  param_2[0x1b] = *(undefined *)((int)param_1 + 0x1b);
  param_2[0x1c] = (char)param_1[7];
  param_2[0x1d] = (char)((uint)param_1[7] >> 8);
  param_2[0x1e] = (char)*(undefined2 *)((int)param_1 + 0x1e);
  param_2[0x1f] = *(undefined *)((int)param_1 + 0x1f);
  return;
}


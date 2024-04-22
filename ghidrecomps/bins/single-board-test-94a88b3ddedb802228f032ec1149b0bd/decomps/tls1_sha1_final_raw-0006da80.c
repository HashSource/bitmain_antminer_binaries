
void tls1_sha1_final_raw(undefined4 *param_1,undefined *param_2)

{
  *param_2 = *(undefined *)((int)param_1 + 3);
  param_2[1] = (char)*(undefined2 *)((int)param_1 + 2);
  param_2[2] = (char)((uint)*param_1 >> 8);
  param_2[3] = (char)*param_1;
  param_2[4] = *(undefined *)((int)param_1 + 7);
  param_2[5] = (char)*(undefined2 *)((int)param_1 + 6);
  param_2[6] = (char)((uint)param_1[1] >> 8);
  param_2[7] = (char)param_1[1];
  param_2[8] = *(undefined *)((int)param_1 + 0xb);
  param_2[9] = (char)*(undefined2 *)((int)param_1 + 10);
  param_2[10] = (char)((uint)param_1[2] >> 8);
  param_2[0xb] = (char)param_1[2];
  param_2[0xc] = *(undefined *)((int)param_1 + 0xf);
  param_2[0xd] = (char)*(undefined2 *)((int)param_1 + 0xe);
  param_2[0xe] = (char)((uint)param_1[3] >> 8);
  param_2[0xf] = (char)param_1[3];
  param_2[0x10] = *(undefined *)((int)param_1 + 0x13);
  param_2[0x11] = (char)*(undefined2 *)((int)param_1 + 0x12);
  param_2[0x12] = (char)((uint)param_1[4] >> 8);
  param_2[0x13] = (char)param_1[4];
  return;
}


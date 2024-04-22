
void dtls1_get_message_header(undefined *param_1,undefined *param_2)

{
  memset(param_2,0,0x2c);
  *param_2 = *param_1;
  *(uint *)(param_2 + 4) =
       (uint)(byte)param_1[2] << 8 | (uint)(byte)param_1[1] << 0x10 | (uint)(byte)param_1[3];
  *(ushort *)(param_2 + 8) = CONCAT11(param_1[4],param_1[5]);
  *(uint *)(param_2 + 0xc) =
       (uint)(byte)param_1[7] << 8 | (uint)(byte)param_1[6] << 0x10 | (uint)(byte)param_1[8];
  *(uint *)(param_2 + 0x10) =
       (uint)(byte)param_1[10] << 8 | (uint)(byte)param_1[9] << 0x10 | (uint)(byte)param_1[0xb];
  return;
}


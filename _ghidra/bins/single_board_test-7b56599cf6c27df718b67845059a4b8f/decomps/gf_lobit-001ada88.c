
int gf_lobit(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int local_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int local_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int local_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int local_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_18;
  
  local_60 = *param_1;
  iStack_5c = param_1[1];
  iStack_58 = param_1[2];
  iStack_54 = param_1[3];
  local_50 = param_1[4];
  iStack_4c = param_1[5];
  iStack_48 = param_1[6];
  iStack_44 = param_1[7];
  local_40 = param_1[8];
  iStack_3c = param_1[9];
  iStack_38 = param_1[10];
  iStack_34 = param_1[0xb];
  local_30 = param_1[0xc];
  iStack_2c = param_1[0xd];
  iStack_28 = param_1[0xe];
  iStack_24 = param_1[0xf];
  uStack_18 = param_4;
  gf_strong_reduce(&local_60);
  return (local_60 << 0x1f) >> 0x1f;
}


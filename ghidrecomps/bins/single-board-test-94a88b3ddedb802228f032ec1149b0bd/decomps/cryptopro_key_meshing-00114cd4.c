
void cryptopro_key_meshing(uint *param_1,undefined4 *param_2)

{
  undefined4 local_50;
  undefined4 uStack_4c;
  byte local_48;
  byte local_47;
  byte local_46;
  byte local_45;
  byte local_44;
  byte local_43;
  byte local_42;
  byte local_41;
  byte local_40;
  byte local_3f;
  byte local_3e;
  byte local_3d;
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  byte local_2c;
  byte local_2b;
  byte local_2a;
  byte local_29;
  
  gostdecrypt(param_1,&CryptoProKeyMeshingKey,&local_48);
  gostdecrypt(param_1,&DAT_00179244,&local_40);
  gostdecrypt(param_1,&DAT_0017924c,&local_38);
  gostdecrypt(param_1,&DAT_00179254,&local_30);
  *param_1 = (uint)local_46 << 0x10 | (uint)local_47 << 8 | (uint)local_48 | (uint)local_45 << 0x18;
  param_1[1] = (uint)local_42 << 0x10 | (uint)local_43 << 8 | (uint)local_44 |
               (uint)local_41 << 0x18;
  param_1[3] = (uint)local_3a << 0x10 | (uint)local_3b << 8 | (uint)local_3c |
               (uint)local_39 << 0x18;
  param_1[5] = (uint)local_32 << 0x10 | (uint)local_33 << 8 | (uint)local_34 |
               (uint)local_31 << 0x18;
  param_1[2] = (uint)local_3e << 0x10 | (uint)local_3f << 8 | (uint)local_40 |
               (uint)local_3d << 0x18;
  param_1[6] = (uint)local_2e << 0x10 | (uint)local_2f << 8 | (uint)local_30 |
               (uint)local_2d << 0x18;
  param_1[4] = (uint)local_36 << 0x10 | (uint)local_37 << 8 | (uint)local_38 |
               (uint)local_35 << 0x18;
  param_1[7] = (uint)local_2a << 0x10 | (uint)local_2b << 8 | (uint)local_2c |
               (uint)local_29 << 0x18;
  gostcrypt(param_1,param_2,&local_50);
  *param_2 = local_50;
  param_2[1] = uStack_4c;
  return;
}


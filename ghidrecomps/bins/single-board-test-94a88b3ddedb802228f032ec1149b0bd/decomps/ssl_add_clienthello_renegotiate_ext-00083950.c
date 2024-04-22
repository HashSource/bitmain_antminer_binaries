
undefined4 ssl_add_clienthello_renegotiate_ext(int param_1,byte *param_2,int *param_3,int param_4)

{
  byte bVar1;
  
  if (param_2 != (byte *)0x0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x58) + 0x3d4);
    if (param_4 <= (int)(uint)bVar1) {
      ERR_put_error(0x14,0x12a,0x14f,DAT_000839a0,0x7a);
      return 0;
    }
    *param_2 = bVar1;
    memcpy(param_2 + 1,(void *)(*(int *)(param_1 + 0x58) + 0x394),
           (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x3d4));
  }
  *param_3 = *(byte *)(*(int *)(param_1 + 0x58) + 0x3d4) + 1;
  return 1;
}


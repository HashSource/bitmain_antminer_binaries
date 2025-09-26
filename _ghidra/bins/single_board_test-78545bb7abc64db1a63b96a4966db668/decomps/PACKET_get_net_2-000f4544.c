
undefined4 PACKET_get_net_2(undefined4 *param_1,uint *param_2)

{
  byte bVar1;
  byte *pbVar2;
  
  if (1 < (uint)param_1[1]) {
    pbVar2 = (byte *)*param_1;
    bVar1 = *pbVar2;
    *param_2 = (uint)bVar1 << 8;
    *param_2 = (uint)CONCAT11(bVar1,pbVar2[1]);
    *param_1 = pbVar2 + 2;
    param_1[1] = param_1[1] + -2;
    return 1;
  }
  return 0;
}



undefined4 PACKET_get_length_prefixed_2(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  if ((uint)param_1[1] < 2) {
    return 0;
  }
  uVar2 = param_1[1] - 2;
  puVar3 = (undefined1 *)*param_1;
  uVar1 = (uint)CONCAT11(*puVar3,puVar3[1]);
  if (uVar1 <= uVar2) {
    param_1[1] = uVar2 - uVar1;
    *param_1 = puVar3 + 2 + uVar1;
    *param_2 = puVar3 + 2;
    param_2[1] = uVar1;
    return 1;
  }
  return 0;
}


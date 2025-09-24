
void X448_public_from_private(undefined4 param_1,undefined4 *param_2)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 auStack_1a0 [272];
  byte abStack_90 [4];
  undefined4 auStack_8c [12];
  byte bStack_59;
  undefined1 auStack_58 [56];
  
  puVar6 = param_2;
  pbVar1 = abStack_90;
  do {
    puVar7 = (undefined4 *)pbVar1;
    puVar5 = puVar6;
    puVar6 = puVar5 + 4;
    uVar2 = puVar5[1];
    uVar3 = puVar5[2];
    uVar4 = puVar5[3];
    *puVar7 = *puVar5;
    puVar7[1] = uVar2;
    puVar7[2] = uVar3;
    puVar7[3] = uVar4;
    pbVar1 = (byte *)(puVar7 + 4);
  } while (puVar6 != param_2 + 0xc);
  uVar2 = puVar5[5];
  puVar7[4] = *puVar6;
  puVar7[5] = uVar2;
  abStack_90[0] = abStack_90[0] & 0xfc;
  bStack_59 = bStack_59 | 0x80;
  curve448_scalar_decode_long(auStack_58,abStack_90);
  curve448_scalar_halve(auStack_58,auStack_58);
  curve448_precomputed_scalarmul(auStack_1a0,curve448_precomputed_base,auStack_58);
  curve448_point_mul_by_ratio_and_encode_like_x448(param_1,auStack_1a0);
  curve448_point_destroy(auStack_1a0);
  return;
}


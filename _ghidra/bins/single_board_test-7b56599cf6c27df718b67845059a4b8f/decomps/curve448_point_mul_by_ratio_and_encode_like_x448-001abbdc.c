
void curve448_point_mul_by_ratio_and_encode_like_x448(undefined4 param_1,void *param_2)

{
  undefined1 auStack_1b0 [64];
  undefined1 auStack_170 [64];
  undefined1 auStack_130 [64];
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 auStack_70 [80];
  
  memcpy(auStack_1b0,param_2,0x100);
  gf_sqr(auStack_70,auStack_1b0);
  gf_isr(&local_b0,auStack_70);
  gf_sqr(auStack_70,&local_b0);
  gf_mul(&local_b0,auStack_70,auStack_1b0);
  local_f0 = local_b0;
  uStack_ec = uStack_ac;
  uStack_e8 = uStack_a8;
  uStack_e4 = uStack_a4;
  local_e0 = local_a0;
  uStack_dc = uStack_9c;
  uStack_d8 = uStack_98;
  uStack_d4 = uStack_94;
  local_d0 = local_90;
  uStack_cc = uStack_8c;
  uStack_c8 = uStack_88;
  uStack_c4 = uStack_84;
  local_c0 = local_80;
  uStack_bc = uStack_7c;
  uStack_b8 = uStack_78;
  uStack_b4 = uStack_74;
  gf_mul(auStack_130,&local_f0,auStack_170);
  gf_sqr(auStack_170,auStack_130);
  gf_serialize(param_1,auStack_170,1);
  curve448_point_destroy(auStack_1b0);
  return;
}


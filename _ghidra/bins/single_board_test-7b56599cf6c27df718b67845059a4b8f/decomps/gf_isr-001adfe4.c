
void gf_isr(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_130 [64];
  undefined1 auStack_f0 [64];
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
  undefined1 auStack_70 [72];
  undefined4 uStack_28;
  
  iVar1 = 4;
  uStack_28 = param_4;
  gf_sqr(&local_b0);
  gf_mul(auStack_f0,param_2,&local_b0);
  gf_sqr(&local_b0,auStack_f0);
  gf_mul(auStack_f0,param_2,&local_b0);
  gf_sqr(&local_b0,auStack_f0);
  gf_sqr(auStack_130,&local_b0);
  gf_sqr(&local_b0,auStack_130);
  gf_mul(auStack_70,auStack_f0,&local_b0);
  gf_sqr(&local_b0,auStack_70);
  gf_sqr(auStack_130,&local_b0);
  gf_sqr(&local_b0,auStack_130);
  gf_mul(auStack_70,auStack_f0,&local_b0);
  gf_sqr(auStack_f0,auStack_70);
  do {
    gf_sqr(auStack_130,auStack_f0);
    gf_sqr(auStack_f0,auStack_130);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 8;
  gf_mul(&local_b0,auStack_70,auStack_f0);
  gf_sqr(auStack_70,&local_b0);
  gf_mul(auStack_f0,param_2,auStack_70);
  gf_sqr(auStack_130,auStack_f0);
  gf_sqr(auStack_70,auStack_130);
  do {
    gf_sqr(auStack_130,auStack_70);
    gf_sqr(auStack_70,auStack_130);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x12;
  gf_mul(auStack_f0,&local_b0,auStack_70);
  gf_sqr(auStack_70,auStack_f0);
  do {
    gf_sqr(auStack_130,auStack_70);
    gf_sqr(auStack_70,auStack_130);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x12;
  gf_mul(&local_b0,auStack_f0,auStack_70);
  gf_sqr(auStack_70,&local_b0);
  do {
    gf_sqr(auStack_130,auStack_70);
    gf_sqr(auStack_70,auStack_130);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x37;
  gf_mul(&local_b0,auStack_f0,auStack_70);
  gf_sqr(auStack_70,&local_b0);
  do {
    gf_sqr(auStack_130,auStack_70);
    gf_sqr(auStack_70,auStack_130);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x6f;
  gf_mul(auStack_f0,&local_b0,auStack_70);
  gf_sqr(auStack_70,auStack_f0);
  gf_mul(&local_b0,param_2,auStack_70);
  gf_sqr(auStack_70,&local_b0);
  do {
    gf_sqr(auStack_130,auStack_70);
    gf_sqr(auStack_70,auStack_130);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  gf_mul(&local_b0,auStack_f0,auStack_70);
  gf_sqr(auStack_f0,&local_b0);
  gf_mul(auStack_70,auStack_f0,param_2);
  *param_1 = local_b0;
  param_1[1] = uStack_ac;
  param_1[2] = uStack_a8;
  param_1[3] = uStack_a4;
  param_1[4] = local_a0;
  param_1[5] = uStack_9c;
  param_1[6] = uStack_98;
  param_1[7] = uStack_94;
  param_1[8] = local_90;
  param_1[9] = uStack_8c;
  param_1[10] = uStack_88;
  param_1[0xb] = uStack_84;
  param_1[0xc] = local_80;
  param_1[0xd] = uStack_7c;
  param_1[0xe] = uStack_78;
  param_1[0xf] = uStack_74;
  gf_eq(auStack_70,ONE);
  return;
}


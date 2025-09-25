
uint curve448_point_valid(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_100 [64];
  undefined1 auStack_c0 [64];
  undefined1 auStack_80 [80];
  int local_30;
  uint local_2c;
  
  local_30 = param_1 + 0x40;
  iVar3 = param_1 + 0x80;
  gf_mul(auStack_80,param_1,local_30);
  gf_mul(auStack_c0,iVar3,param_1 + 0xc0);
  local_2c = gf_eq(auStack_80,auStack_c0);
  gf_sqr(auStack_80,param_1);
  gf_sqr(auStack_c0,local_30);
  gf_sub(auStack_80,auStack_c0,auStack_80);
  gf_sqr(auStack_c0,param_1 + 0xc0);
  gf_mulw_unsigned(auStack_100,auStack_c0,0x98aa);
  gf_sub(auStack_100,&ZERO,auStack_100);
  gf_sqr(auStack_c0,iVar3);
  gf_add(auStack_c0,auStack_c0,auStack_100);
  uVar1 = gf_eq(auStack_80,auStack_c0);
  uVar1 = local_2c & uVar1;
  uVar2 = gf_eq(iVar3,&ZERO);
  return uVar1 & ~uVar2;
}


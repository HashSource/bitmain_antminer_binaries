
int SHA384_Init(SHA512_CTX *c)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar3 = DAT_00096cec;
  uVar2 = DAT_00096ce8;
  uVar1 = DAT_00096ce4;
  *(undefined4 *)c->h = DAT_00096ce0;
  *(undefined4 *)((int)c->h + 4) = uVar1;
  uVar4 = DAT_00096cf4;
  uVar1 = DAT_00096cf0;
  *(undefined4 *)(c->h + 2) = uVar2;
  *(undefined4 *)((int)c->h + 0x14) = uVar3;
  uVar6 = DAT_00096d04;
  uVar5 = DAT_00096d00;
  uVar3 = DAT_00096cfc;
  uVar2 = DAT_00096cf8;
  *(undefined4 *)(c->h + 1) = uVar1;
  *(undefined4 *)((int)c->h + 0xc) = uVar4;
  *(undefined4 *)(c->h + 3) = uVar2;
  *(undefined4 *)((int)c->h + 0x1c) = uVar3;
  uVar7 = DAT_00096d1c;
  uVar4 = DAT_00096d18;
  uVar3 = DAT_00096d14;
  uVar2 = DAT_00096d10;
  uVar1 = DAT_00096d0c;
  *(undefined4 *)(c->h + 7) = DAT_00096d08;
  *(undefined4 *)((int)c->h + 0x3c) = uVar1;
  *(undefined4 *)(c->h + 4) = uVar5;
  *(undefined4 *)((int)c->h + 0x24) = uVar6;
  *(undefined4 *)(c->h + 5) = uVar2;
  *(undefined4 *)((int)c->h + 0x2c) = uVar3;
  *(undefined4 *)(c->h + 6) = uVar4;
  *(undefined4 *)((int)c->h + 0x34) = uVar7;
  c->num = 0;
  c->md_len = 0x30;
  *(undefined4 *)&c->Nl = 0;
  *(undefined4 *)((int)&c->Nl + 4) = 0;
  *(undefined4 *)&c->Nh = 0;
  *(undefined4 *)((int)&c->Nh + 4) = 0;
  return 1;
}


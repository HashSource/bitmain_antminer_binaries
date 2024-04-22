
int SHA512_Init(SHA512_CTX *c)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar3 = DAT_00096dac;
  uVar2 = DAT_00096da8;
  uVar1 = DAT_00096da4;
  *(undefined4 *)c->h = DAT_00096da0;
  *(undefined4 *)((int)c->h + 4) = uVar1;
  uVar4 = DAT_00096db4;
  uVar1 = DAT_00096db0;
  *(undefined4 *)(c->h + 2) = uVar2;
  *(undefined4 *)((int)c->h + 0x14) = uVar3;
  uVar6 = DAT_00096dc4;
  uVar5 = DAT_00096dc0;
  uVar3 = DAT_00096dbc;
  uVar2 = DAT_00096db8;
  *(undefined4 *)(c->h + 1) = uVar1;
  *(undefined4 *)((int)c->h + 0xc) = uVar4;
  *(undefined4 *)(c->h + 3) = uVar2;
  *(undefined4 *)((int)c->h + 0x1c) = uVar3;
  uVar7 = DAT_00096ddc;
  uVar4 = DAT_00096dd8;
  uVar3 = DAT_00096dd4;
  uVar2 = DAT_00096dd0;
  uVar1 = DAT_00096dcc;
  *(undefined4 *)(c->h + 7) = DAT_00096dc8;
  *(undefined4 *)((int)c->h + 0x3c) = uVar1;
  *(undefined4 *)(c->h + 4) = uVar5;
  *(undefined4 *)((int)c->h + 0x24) = uVar6;
  *(undefined4 *)(c->h + 5) = uVar2;
  *(undefined4 *)((int)c->h + 0x2c) = uVar3;
  *(undefined4 *)(c->h + 6) = uVar4;
  *(undefined4 *)((int)c->h + 0x34) = uVar7;
  c->num = 0;
  c->md_len = 0x40;
  *(undefined4 *)&c->Nl = 0;
  *(undefined4 *)((int)&c->Nl + 4) = 0;
  *(undefined4 *)&c->Nh = 0;
  *(undefined4 *)((int)&c->Nh + 4) = 0;
  return 1;
}


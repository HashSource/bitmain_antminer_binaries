
void add_opt(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  opt_table = realloc(opt_table,(opt_count + 1) * 0x1c);
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  puVar4 = (undefined4 *)((int)opt_table + opt_count * 0x1c);
  opt_count = opt_count + 1;
  *puVar4 = *param_1;
  puVar4[1] = uVar1;
  puVar4[2] = uVar2;
  puVar4[3] = uVar3;
  uVar1 = param_1[5];
  uVar2 = param_1[6];
  puVar4[4] = param_1[4];
  puVar4[5] = uVar1;
  puVar4[6] = uVar2;
  return;
}


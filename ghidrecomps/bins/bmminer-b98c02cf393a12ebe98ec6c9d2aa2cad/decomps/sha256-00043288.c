
void sha256(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 uStack_34;
  undefined4 local_30 [8];
  
  puVar1 = &uStack_34;
  puVar2 = DAT_000432c4;
  do {
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 1;
    *puVar1 = *puVar2;
  } while (puVar2 != DAT_000432c4 + 8);
  local_b8 = 0;
  local_b4 = 0;
  sha256_update(&local_b8,param_1,param_2);
  sha256_final(&local_b8,param_3);
  return;
}


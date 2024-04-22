
void sha256_init(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + 0x21;
  puVar1 = DAT_00043160;
  do {
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
    *puVar2 = *puVar1;
  } while (puVar2 != param_1 + 0x29);
  param_1[1] = 0;
  *param_1 = 0;
  return;
}


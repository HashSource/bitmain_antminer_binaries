
void tls1_get_supported_groups(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30000;
  if (uVar2 == 0x20000) {
    *param_2 = 0x20f692;
    *param_3 = 1;
    return;
  }
  if (uVar2 == 0x30000) {
    *param_2 = (int)&suiteb_curves;
    *param_3 = 2;
    return;
  }
  if (uVar2 == 0x10000) {
    *param_2 = (int)&suiteb_curves;
    *param_3 = 1;
    return;
  }
  if (*(int *)(param_1 + 0x574) != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x570);
    *param_2 = *(int *)(param_1 + 0x574);
    *param_3 = uVar1;
    return;
  }
  *param_2 = (int)eccurves_default;
  *param_3 = 5;
  return;
}


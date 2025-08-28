
void get_BM1385_plldata(undefined4 param_1,undefined4 *param_2,ushort *param_3,undefined4 *param_4)

{
  int iVar1;
  char local_78 [32];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  char local_38 [44];
  uint local_c;
  
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_38[8] = '\0';
  local_38[9] = '\0';
  local_38[10] = '\0';
  local_38[0xb] = '\0';
  local_38[0xc] = '\0';
  local_38[0xd] = '\0';
  local_38[0xe] = '\0';
  local_38[0xf] = '\0';
  local_38[0x10] = '\0';
  local_38[0x11] = '\0';
  local_38[0x12] = '\0';
  local_38[0x13] = '\0';
  local_38[0x14] = '\0';
  local_38[0x15] = '\0';
  local_38[0x16] = '\0';
  local_38[0x17] = '\0';
  local_38[0x18] = '\0';
  local_38[0x19] = '\0';
  local_38[0x1a] = '\0';
  local_38[0x1b] = '\0';
  local_38[0x1c] = '\0';
  local_38[0x1d] = '\0';
  local_38[0x1e] = '\0';
  local_38[0x1f] = '\0';
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_78[9] = '\0';
  local_78[10] = '\0';
  local_78[0xb] = '\0';
  local_78[0xc] = '\0';
  local_78[0xd] = '\0';
  local_78[0xe] = '\0';
  local_78[0xf] = '\0';
  local_78[0x10] = '\0';
  local_78[0x11] = '\0';
  local_78[0x12] = '\0';
  local_78[0x13] = '\0';
  local_78[0x14] = '\0';
  local_78[0x15] = '\0';
  local_78[0x16] = '\0';
  local_78[0x17] = '\0';
  local_78[0x18] = '\0';
  local_78[0x19] = '\0';
  local_78[0x1a] = '\0';
  local_78[0x1b] = '\0';
  local_78[0x1c] = '\0';
  local_78[0x1d] = '\0';
  local_78[0x1e] = '\0';
  local_78[0x1f] = '\0';
  sprintf(local_38 + 0x20,"%d",param_1);
  local_c = 0;
  while ((local_c < 0x7c &&
         (iVar1 = memcmp(*(void **)(freq_pll_1385 + local_c * 0x10),local_38 + 0x20,4), iVar1 != 0))
        ) {
    local_c = local_c + 1;
  }
  printf("%s: i = %d, sizeof(freq_pll_1385)/sizeof(freq_pll_1385[0]) = %d\n","get_BM1385_plldata",
         local_c,0x7c);
  if (local_c == 0x7c) {
    printf("%s: Freq set Err!!!!\n","get_BM1385_plldata");
    printf("%s: Using 200M\n","get_BM1385_plldata");
    local_c = 4;
  }
  sprintf(local_38,"%08x",*(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 4));
  sprintf((char *)&local_58,"%04x",*(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 8));
  sprintf(local_78,"%04x",*(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 0xc));
  printf("%s: Freq %s, PLL1 %s, PLL2 %s, vilpll %s\n","get_BM1385_plldata",local_38 + 0x20,local_38,
         &local_58,local_78);
  *param_2 = *(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 4);
  *param_3 = (ushort)*(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 8);
  *param_4 = *(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 0xc);
  printf("%s: PLL1 %#x, PLL2 %#x, vilpll %#x\n","get_BM1385_plldata",*param_2,(uint)*param_3,
         *param_4);
  return;
}


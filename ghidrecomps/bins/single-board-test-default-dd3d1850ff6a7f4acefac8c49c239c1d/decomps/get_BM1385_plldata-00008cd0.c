
void get_BM1385_plldata(undefined4 param_1,undefined4 *param_2,ushort *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  char acStack_18 [12];
  uint local_c;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  sprintf(acStack_18,"%d",param_1);
  local_c = 0;
  while ((local_c < 0x7c &&
         (iVar1 = memcmp(*(void **)(freq_pll_1385 + local_c * 0x10),acStack_18,4), iVar1 != 0))) {
    local_c = local_c + 1;
  }
  printf("%s: i = %d, sizeof(freq_pll_1385)/sizeof(freq_pll_1385[0]) = %d\n","get_BM1385_plldata",
         local_c,0x7c);
  if (local_c == 0x7c) {
    printf("%s: Freq set Err!!!!\n","get_BM1385_plldata");
    printf("%s: Using 200M\n","get_BM1385_plldata");
    local_c = 4;
  }
  sprintf((char *)&local_38,"%08x",*(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 4));
  sprintf((char *)&local_58,"%04x",*(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 8));
  sprintf((char *)&local_78,"%04x",*(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 0xc));
  printf("%s: Freq %s, PLL1 %s, PLL2 %s, vilpll %s\n","get_BM1385_plldata",acStack_18,&local_38,
         &local_58,&local_78);
  *param_2 = *(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 4);
  *param_3 = (ushort)*(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 8);
  *param_4 = *(undefined4 *)(freq_pll_1385 + local_c * 0x10 + 0xc);
  printf("%s: PLL1 %#x, PLL2 %#x, vilpll %#x\n","get_BM1385_plldata",*param_2,(uint)*param_3,
         *param_4);
  return;
}


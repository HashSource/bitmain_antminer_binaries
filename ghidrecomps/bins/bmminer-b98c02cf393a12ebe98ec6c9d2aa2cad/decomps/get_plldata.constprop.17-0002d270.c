
void get_plldata_constprop_17
               (undefined4 param_1,undefined4 *param_2,undefined2 *param_3,undefined4 *param_4)

{
  undefined *__s1;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char acStack_8c [12];
  char acStack_80 [32];
  char acStack_60 [32];
  char acStack_40 [32];
  
  puVar2 = DAT_0002d340;
  sprintf(acStack_8c,"%d",param_1);
  iVar5 = 0;
  memset(acStack_80,0,0x20);
  memset(acStack_60,0,0x20);
  memset(acStack_40,0,0x20);
  __s1 = &DAT_00062030;
  do {
    iVar1 = memcmp(__s1,acStack_8c,4);
    if (iVar1 == 0) {
      iVar5 = iVar5 * 0x10;
      uVar7 = *(undefined4 *)(freq_pll_1385 + iVar5 + 8);
      uVar6 = *(undefined4 *)(freq_pll_1385 + iVar5 + 4);
      uVar3 = *(undefined4 *)(freq_pll_1385 + iVar5 + 0xc);
      uVar4 = (undefined2)uVar7;
LAB_0002d2ea:
      sprintf(acStack_80,"%08x",uVar6);
      sprintf(acStack_60,"%04x",uVar7);
      sprintf(acStack_40,"%04x",uVar3);
      *param_2 = uVar6;
      *param_3 = uVar4;
      *param_4 = uVar3;
      return;
    }
    iVar5 = iVar5 + 1;
    if (iVar5 == 0x72) {
      uVar4 = 0x420;
      uVar7 = 0x420;
      uVar3 = 0x400241;
      uVar6 = 0x40040;
      goto LAB_0002d2ea;
    }
    __s1 = (undefined *)*puVar2;
    puVar2 = puVar2 + 4;
  } while( true );
}


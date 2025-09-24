
void CRYPTO_cfb128_8_encrypt
               (byte *param_1,int param_2,int param_3,undefined4 param_4,byte *param_5,
               undefined4 param_6,int param_7,code *param_8)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined3 uStack_4b;
  undefined1 uStack_48;
  undefined3 local_47;
  undefined1 uStack_44;
  undefined3 local_43;
  undefined1 uStack_40;
  undefined3 local_3f;
  
  if (param_3 != 0) {
    pbVar9 = (byte *)(param_2 + -1);
    pbVar8 = param_1;
    if (param_7 == 0) {
      do {
        uVar3 = *(undefined4 *)param_5;
        uVar4 = *(undefined4 *)(param_5 + 4);
        uVar5 = *(undefined4 *)(param_5 + 8);
        uVar6 = *(undefined4 *)(param_5 + 0xc);
        (*param_8)(param_5,param_5,param_4);
        pbVar7 = pbVar8 + 1;
        bVar1 = *pbVar8;
        uStack_4b = (undefined3)((uint)uVar3 >> 8);
        uStack_48 = (undefined1)uVar4;
        local_47 = (undefined3)((uint)uVar4 >> 8);
        uStack_44 = (undefined1)uVar5;
        local_43 = (undefined3)((uint)uVar5 >> 8);
        uStack_40 = (undefined1)uVar6;
        local_3f = (undefined3)((uint)uVar6 >> 8);
        pbVar9 = pbVar9 + 1;
        *pbVar9 = *param_5 ^ bVar1;
        *(uint *)param_5 = CONCAT13(uStack_48,uStack_4b);
        *(uint *)(param_5 + 4) = CONCAT13(uStack_44,local_47);
        *(uint *)(param_5 + 8) = CONCAT13(uStack_40,local_43);
        *(uint *)(param_5 + 0xc) = CONCAT13(bVar1,local_3f);
        pbVar8 = pbVar7;
      } while (pbVar7 != param_1 + param_3);
    }
    else {
      do {
        uVar3 = *(undefined4 *)param_5;
        uVar4 = *(undefined4 *)(param_5 + 4);
        uVar5 = *(undefined4 *)(param_5 + 8);
        uVar6 = *(undefined4 *)(param_5 + 0xc);
        (*param_8)(param_5,param_5,param_4);
        pbVar7 = pbVar8 + 1;
        bVar2 = *pbVar8;
        bVar1 = *param_5;
        uStack_4b = (undefined3)((uint)uVar3 >> 8);
        uStack_48 = (undefined1)uVar4;
        local_47 = (undefined3)((uint)uVar4 >> 8);
        uStack_44 = (undefined1)uVar5;
        local_43 = (undefined3)((uint)uVar5 >> 8);
        uStack_40 = (undefined1)uVar6;
        local_3f = (undefined3)((uint)uVar6 >> 8);
        pbVar9 = pbVar9 + 1;
        *pbVar9 = bVar1 ^ bVar2;
        *(uint *)param_5 = CONCAT13(uStack_48,uStack_4b);
        *(uint *)(param_5 + 4) = CONCAT13(uStack_44,local_47);
        *(uint *)(param_5 + 8) = CONCAT13(uStack_40,local_43);
        *(uint *)(param_5 + 0xc) = CONCAT13(bVar1 ^ bVar2,local_3f);
        pbVar8 = pbVar7;
      } while (param_1 + param_3 != pbVar7);
    }
  }
  return;
}


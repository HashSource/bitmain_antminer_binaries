
void BN_consttime_swap(int param_1,uint **param_2,uint **param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  uVar2 = -param_1 >> 0x1f;
  uVar7 = ((uint)param_3[1] ^ (uint)param_2[1]) & uVar2;
  param_2[1] = (uint *)((uint)param_2[1] ^ uVar7);
  param_3[1] = (uint *)(uVar7 ^ (uint)param_3[1]);
  switch(param_4) {
  case 1:
    puVar3 = *param_2;
    puVar5 = *param_3;
    goto LAB_0009d9ec;
  case 2:
    puVar3 = *param_2;
    puVar5 = *param_3;
    goto LAB_0009d9da;
  case 3:
    puVar3 = *param_2;
    puVar5 = *param_3;
    goto LAB_0009d9c8;
  case 4:
    puVar3 = *param_2;
    puVar5 = *param_3;
    goto LAB_0009d9b6;
  case 5:
    puVar3 = *param_2;
    puVar5 = *param_3;
    goto LAB_0009d9a4;
  case 6:
    puVar3 = *param_2;
    puVar5 = *param_3;
    goto LAB_0009d992;
  case 7:
    puVar3 = *param_2;
    puVar5 = *param_3;
    goto LAB_0009d980;
  case 8:
    puVar3 = *param_2;
    puVar5 = *param_3;
    goto LAB_0009d96e;
  case 9:
    puVar3 = *param_2;
    puVar5 = *param_3;
    goto LAB_0009d95c;
  case 10:
    puVar3 = *param_2;
    puVar5 = *param_3;
    break;
  default:
    puVar3 = *param_2;
    if (param_4 < 0xb) {
      puVar5 = *param_3;
    }
    else {
      puVar5 = *param_3;
      if (param_4 < 0x13) {
        iVar10 = 10;
        iVar8 = 0xb;
      }
      else {
        puVar6 = puVar3 + 0x18;
        puVar4 = puVar5 + 0x18;
        iVar9 = 10;
        do {
          iVar10 = iVar9 + 8;
          iVar8 = iVar9 + 9;
          HintPreloadData(puVar6);
          HintPreloadData(puVar4);
          uVar7 = (puVar6[-0xe] ^ puVar4[-0xe]) & uVar2;
          puVar6[-0xe] = uVar7 ^ puVar6[-0xe];
          puVar4[-0xe] = puVar4[-0xe] ^ uVar7;
          uVar7 = (puVar6[-0xd] ^ puVar4[-0xd]) & uVar2;
          puVar6[-0xd] = uVar7 ^ puVar6[-0xd];
          puVar4[-0xd] = puVar4[-0xd] ^ uVar7;
          uVar7 = (puVar6[-0xc] ^ puVar4[-0xc]) & uVar2;
          puVar6[-0xc] = uVar7 ^ puVar6[-0xc];
          puVar4[-0xc] = puVar4[-0xc] ^ uVar7;
          uVar7 = (puVar6[-0xb] ^ puVar4[-0xb]) & uVar2;
          puVar6[-0xb] = uVar7 ^ puVar6[-0xb];
          puVar4[-0xb] = puVar4[-0xb] ^ uVar7;
          uVar7 = (puVar6[-10] ^ puVar4[-10]) & uVar2;
          puVar6[-10] = uVar7 ^ puVar6[-10];
          puVar4[-10] = puVar4[-10] ^ uVar7;
          uVar7 = (puVar6[-9] ^ puVar4[-9]) & uVar2;
          puVar6[-9] = uVar7 ^ puVar6[-9];
          puVar4[-9] = puVar4[-9] ^ uVar7;
          uVar7 = (puVar6[-8] ^ puVar4[-8]) & uVar2;
          puVar6[-8] = uVar7 ^ puVar6[-8];
          puVar4[-8] = puVar4[-8] ^ uVar7;
          uVar7 = (puVar6[-7] ^ puVar4[-7]) & uVar2;
          puVar6[-7] = uVar7 ^ puVar6[-7];
          puVar6 = puVar6 + 8;
          puVar4[-7] = puVar4[-7] ^ uVar7;
          puVar4 = puVar4 + 8;
          iVar9 = iVar10;
        } while (iVar8 < param_4 + -7);
      }
      puVar4 = puVar3 + iVar10;
      puVar6 = puVar5 + iVar10;
      do {
        uVar7 = (*puVar4 ^ *puVar6) & uVar2;
        *puVar4 = uVar7 ^ *puVar4;
        *puVar6 = *puVar6 ^ uVar7;
        bVar1 = iVar8 < param_4;
        puVar4 = puVar4 + 1;
        iVar8 = iVar8 + 1;
        puVar6 = puVar6 + 1;
      } while (bVar1);
    }
  }
  uVar7 = (puVar5[9] ^ puVar3[9]) & uVar2;
  puVar3[9] = puVar3[9] ^ uVar7;
  puVar5[9] = uVar7 ^ puVar5[9];
LAB_0009d95c:
  uVar7 = (puVar5[8] ^ puVar3[8]) & uVar2;
  puVar3[8] = puVar3[8] ^ uVar7;
  puVar5[8] = uVar7 ^ puVar5[8];
LAB_0009d96e:
  uVar7 = (puVar5[7] ^ puVar3[7]) & uVar2;
  puVar3[7] = puVar3[7] ^ uVar7;
  puVar5[7] = uVar7 ^ puVar5[7];
LAB_0009d980:
  uVar7 = (puVar5[6] ^ puVar3[6]) & uVar2;
  puVar3[6] = puVar3[6] ^ uVar7;
  puVar5[6] = uVar7 ^ puVar5[6];
LAB_0009d992:
  uVar7 = (puVar5[5] ^ puVar3[5]) & uVar2;
  puVar3[5] = puVar3[5] ^ uVar7;
  puVar5[5] = uVar7 ^ puVar5[5];
LAB_0009d9a4:
  uVar7 = (puVar5[4] ^ puVar3[4]) & uVar2;
  puVar3[4] = puVar3[4] ^ uVar7;
  puVar5[4] = uVar7 ^ puVar5[4];
LAB_0009d9b6:
  uVar7 = (puVar5[3] ^ puVar3[3]) & uVar2;
  puVar3[3] = puVar3[3] ^ uVar7;
  puVar5[3] = uVar7 ^ puVar5[3];
LAB_0009d9c8:
  uVar7 = (puVar5[2] ^ puVar3[2]) & uVar2;
  puVar3[2] = puVar3[2] ^ uVar7;
  puVar5[2] = uVar7 ^ puVar5[2];
LAB_0009d9da:
  uVar7 = (puVar5[1] ^ puVar3[1]) & uVar2;
  puVar3[1] = puVar3[1] ^ uVar7;
  puVar5[1] = uVar7 ^ puVar5[1];
LAB_0009d9ec:
  uVar2 = uVar2 & (*puVar5 ^ *puVar3);
  *puVar3 = *puVar3 ^ uVar2;
  *puVar5 = uVar2 ^ *puVar5;
  return;
}


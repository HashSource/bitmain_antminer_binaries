
void idea_set_decrypt_key(IDEA_KEY_SCHEDULE *ek,IDEA_KEY_SCHEDULE *dk)

{
  int iVar1;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  uint extraout_r1_02;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint (*pauVar6) [6];
  uint (*pauVar7) [6];
  uint uVar8;
  uint uVar9;
  
  pauVar6 = ek->data + 8;
  pauVar7 = (uint (*) [6])dk;
  while( true ) {
    uVar2 = (*(uint (*) [6])*pauVar6)[0];
    uVar3 = uVar2;
    if (uVar2 != 0) {
      __aeabi_idivmod(0x10001,uVar2);
      uVar3 = 1;
      if (extraout_r1 != 0) {
        iVar1 = __aeabi_idiv(0x10001 - extraout_r1,uVar2);
        uVar4 = extraout_r1;
        uVar3 = 1;
        uVar9 = 0;
        do {
          uVar8 = uVar3;
          uVar5 = uVar4;
          uVar3 = uVar9 - uVar8 * iVar1;
          __aeabi_idivmod(uVar2,uVar5);
          iVar1 = __aeabi_idiv(uVar2 - extraout_r1_00,uVar5);
          uVar4 = extraout_r1_00;
          uVar2 = uVar5;
          uVar9 = uVar8;
        } while (extraout_r1_00 != 0);
        if ((int)uVar3 < 0) {
          uVar3 = uVar3 + 0x10001;
        }
      }
    }
    (*(uint (*) [6])*pauVar7)[0] = uVar3;
    (*(uint (*) [6])*pauVar7)[1] = -(*(uint (*) [6])*pauVar6)[2] & 0xffff;
    (*(uint (*) [6])*pauVar7)[2] = -(*(uint (*) [6])*pauVar6)[1] & 0xffff;
    uVar2 = (*(uint (*) [6])*pauVar6)[3];
    uVar3 = uVar2;
    if (uVar2 != 0) {
      __aeabi_idivmod(0x10001,uVar2);
      uVar3 = 1;
      if (extraout_r1_01 != 0) {
        iVar1 = __aeabi_idiv(0x10001 - extraout_r1_01,uVar2);
        uVar4 = extraout_r1_01;
        uVar3 = 1;
        uVar9 = 0;
        do {
          uVar8 = uVar3;
          uVar5 = uVar4;
          uVar3 = uVar9 - uVar8 * iVar1;
          __aeabi_idivmod(uVar2,uVar5);
          iVar1 = __aeabi_idiv(uVar2 - extraout_r1_02,uVar5);
          uVar4 = extraout_r1_02;
          uVar2 = uVar5;
          uVar9 = uVar8;
        } while (extraout_r1_02 != 0);
        if ((int)uVar3 < 0) {
          uVar3 = uVar3 + 0x10001;
        }
      }
    }
    (*(uint (*) [6])*pauVar7)[3] = uVar3;
    if ((IDEA_KEY_SCHEDULE *)pauVar6 == ek) break;
    (*(uint (*) [6])*pauVar7)[4] = pauVar6[-1][4];
    (*(uint (*) [6])*pauVar7)[5] = pauVar6[-1][5];
    pauVar7 = pauVar7 + 1;
    pauVar6 = pauVar6 + -1;
  }
  uVar3 = dk->data[0][2];
  uVar4 = dk->data[8][1];
  uVar2 = dk->data[8][2];
  dk->data[0][2] = dk->data[0][1];
  dk->data[0][1] = uVar3;
  dk->data[8][2] = uVar4;
  dk->data[8][1] = uVar2;
  return;
}


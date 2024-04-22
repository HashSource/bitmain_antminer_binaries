
undefined4 probable_prime(BIGNUM *param_1,int param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  ulong uVar4;
  uint extraout_r1;
  ulong w;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  ushort uStack_1028;
  ushort local_1026 [2049];
  
  puVar2 = DAT_000f3230;
  do {
    iVar3 = BN_rand(param_1,param_2,1,1);
    if (iVar3 == 0) {
      return 0;
    }
    puVar5 = &uStack_1028;
    puVar6 = DAT_000f3230;
    iVar3 = 1;
    do {
      uVar4 = BN_mod_word(param_1,(uint)puVar6[1]);
      puVar5[1] = (ushort)uVar4;
      HintPreloadData(local_1026 + iVar3 + 10);
      uVar4 = BN_mod_word(param_1,(uint)puVar6[2]);
      uVar1 = puVar6[3];
      iVar7 = iVar3 + 0x10;
      puVar5[2] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[4];
      puVar5[3] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[5];
      HintPreloadData(puVar2 + iVar3 + 0xb);
      puVar5[4] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[6];
      w = 0x800 - iVar7;
      puVar5[5] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[7];
      puVar5[6] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[8];
      puVar5[7] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[9];
      puVar5[8] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[10];
      puVar5[9] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[0xb];
      puVar5[10] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[0xc];
      puVar5[0xb] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[0xd];
      puVar5[0xc] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[0xe];
      puVar5[0xd] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar6[0xf];
      puVar5[0xe] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      puVar6 = puVar6 + 0x10;
      uVar1 = *puVar6;
      puVar5[0xf] = (ushort)uVar4;
      uVar4 = BN_mod_word(param_1,(uint)uVar1);
      puVar5 = puVar5 + 0x10;
      *puVar5 = (ushort)uVar4;
      iVar3 = iVar7;
    } while (iVar7 != 0x7f1);
    iVar3 = 0;
    do {
      uVar4 = BN_mod_word(param_1,(uint)*(ushort *)((int)puVar2 + iVar3 + 0xfe2));
      w = w - 1;
      *(short *)((int)local_1026 + iVar3 + 0xfe0) = (short)uVar4;
      iVar3 = iVar3 + 2;
    } while (w != 0);
    do {
      puVar5 = &uStack_1028;
      puVar6 = DAT_000f3230;
      while( true ) {
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
        __aeabi_uidivmod(*puVar5 + w,*puVar6);
        if (extraout_r1 < 2) break;
        if (puVar5 == local_1026 + 0x7fe) {
          iVar3 = BN_add_word(param_1,w);
          if (iVar3 == 0) {
            return 0;
          }
          return 1;
        }
      }
      w = w + 2;
    } while (w != 0xffffba3a);
  } while( true );
}



undefined4 probable_prime(BIGNUM *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  ulong uVar3;
  uint extraout_r1;
  ulong w;
  ushort *puVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  int iVar7;
  ushort uStack_1028;
  ushort local_1026 [2049];
  
  do {
    iVar2 = BN_rand(param_1,param_2,1,1);
    if (iVar2 == 0) {
      return 0;
    }
    puVar5 = (ushort *)&primes;
    puVar4 = &uStack_1028;
    iVar2 = 1;
    do {
      uVar3 = BN_mod_word(param_1,(uint)puVar5[1]);
      puVar4[1] = (ushort)uVar3;
      HintPreloadData(local_1026 + iVar2 + 10);
      uVar3 = BN_mod_word(param_1,(uint)puVar5[2]);
      uVar1 = puVar5[3];
      iVar7 = iVar2 + 0x10;
      puVar4[2] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[4];
      puVar4[3] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[5];
      HintPreloadData(&DAT_0016fbde + iVar2);
      puVar4[4] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[6];
      w = 0x800 - iVar7;
      puVar4[5] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[7];
      puVar4[6] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[8];
      puVar4[7] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[9];
      puVar4[8] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[10];
      puVar4[9] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[0xb];
      puVar4[10] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[0xc];
      puVar4[0xb] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[0xd];
      puVar4[0xc] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[0xe];
      puVar4[0xd] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      uVar1 = puVar5[0xf];
      puVar4[0xe] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      puVar5 = puVar5 + 0x10;
      uVar1 = *puVar5;
      puVar4[0xf] = (ushort)uVar3;
      uVar3 = BN_mod_word(param_1,(uint)uVar1);
      puVar4 = puVar4 + 0x10;
      *puVar4 = (ushort)uVar3;
      iVar2 = iVar7;
    } while (iVar7 != 0x7f1);
    iVar2 = 0;
    do {
      uVar3 = BN_mod_word(param_1,(uint)*(ushort *)((int)&DAT_00170baa + iVar2));
      w = w - 1;
      *(short *)((int)local_1026 + iVar2 + 0xfe0) = (short)uVar3;
      iVar2 = iVar2 + 2;
    } while (w != 0);
    do {
      puVar6 = (undefined2 *)&primes;
      puVar4 = &uStack_1028;
      while( true ) {
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
        __aeabi_uidivmod(*puVar4 + w,*puVar6);
        if (extraout_r1 < 2) break;
        if (puVar4 == local_1026 + 0x7fe) {
          iVar2 = BN_add_word(param_1,w);
          if (iVar2 == 0) {
            return 0;
          }
          return 1;
        }
      }
      w = w + 2;
    } while (w != 0xffffba3a);
  } while( true );
}


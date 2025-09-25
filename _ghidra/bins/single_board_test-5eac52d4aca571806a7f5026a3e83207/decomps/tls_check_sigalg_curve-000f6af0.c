
undefined4 tls_check_sigalg_curve(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  short *psVar5;
  uint uVar6;
  
  puVar4 = *(undefined1 **)(*(int *)(param_1 + 0x404) + 0xd0);
  if (puVar4 == (undefined1 *)0x0) {
    uVar6 = 0x1a;
    puVar4 = tls12_sigalgs;
  }
  else {
    uVar6 = *(uint *)(*(int *)(param_1 + 0x404) + 0xd4);
    if (uVar6 == 0) {
      return 0;
    }
  }
  psVar5 = (short *)(puVar4 + -2);
  uVar3 = 0;
  do {
    psVar5 = psVar5 + 1;
    puVar4 = &sigalg_lookup_tbl;
    do {
      if (*(short *)(puVar4 + 4) == *psVar5) {
        if (*(int *)(puVar4 + 0x10) == 0x198) {
          iVar2 = *(int *)(puVar4 + 0x1c);
          iVar1 = iVar2;
          if (iVar2 != 0) {
            iVar1 = 1;
          }
          if (iVar2 != param_2) {
            iVar1 = 0;
          }
          if (iVar1 != 0) {
            return 1;
          }
        }
        break;
      }
      puVar4 = puVar4 + 0x20;
    } while (puVar4 != legacy_rsa_sigalg);
    uVar3 = uVar3 + 1;
    if (uVar6 <= uVar3) {
      return 0;
    }
  } while( true );
}


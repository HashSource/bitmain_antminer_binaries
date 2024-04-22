
uint pkey_dh_ctrl(int param_1,int param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_1 + 0x14);
  if (param_2 == 0x1007) {
    puVar2[10] = (uint)param_4;
    return 1;
  }
  if (param_2 < 0x1008) {
    if (param_2 == 0x1003) {
      if (param_3 - 1 < 3) {
        puVar2[5] = param_3;
        return 1;
      }
    }
    else if (param_2 < 0x1004) {
      if (param_2 == 0x1001) {
        if (0xff < (int)param_3) {
          *puVar2 = param_3;
          return 1;
        }
      }
      else if (param_2 < 0x1002) {
        if (param_2 == 2) {
          return 1;
        }
      }
      else if (puVar2[2] == 0) {
        puVar2[1] = param_3;
        return 1;
      }
    }
    else if (param_2 == 0x1005) {
      if (param_3 < 3) {
        puVar2[2] = param_3;
        return 1;
      }
    }
    else if (param_2 < 0x1006) {
      if (puVar2[2] != 0) {
        puVar2[3] = param_3;
        return 1;
      }
    }
    else {
      if (param_3 == 0xfffffffe) {
        return (uint)*(byte *)(puVar2 + 8);
      }
      if (param_3 - 1 < 2) {
        *(char *)(puVar2 + 8) = (char)param_3;
        return 1;
      }
    }
  }
  else {
    if (param_2 == 0x100b) {
      if ((void *)puVar2[0xb] != (void *)0x0) {
        CRYPTO_free((void *)puVar2[0xb]);
      }
      puVar2[0xb] = (uint)param_4;
      if (param_4 == (uint *)0x0) {
        puVar2[0xc] = 0;
        return 1;
      }
      puVar2[0xc] = param_3;
      return 1;
    }
    if (param_2 < 0x100c) {
      if (param_2 != 0x1009) {
        if (param_2 < 0x100a) {
          *param_4 = puVar2[10];
          return 1;
        }
        *param_4 = puVar2[0xd];
        return 1;
      }
      if (0 < (int)param_3) {
        puVar2[0xd] = param_3;
        return 1;
      }
    }
    else {
      if (param_2 == 0x100d) {
        if ((ASN1_OBJECT *)puVar2[9] != (ASN1_OBJECT *)0x0) {
          ASN1_OBJECT_free((ASN1_OBJECT *)puVar2[9]);
        }
        puVar2[9] = (uint)param_4;
        return 1;
      }
      if (param_2 < 0x100d) {
        uVar1 = puVar2[0xc];
        *param_4 = puVar2[0xb];
        return uVar1;
      }
      if (param_2 == 0x100e) {
        *param_4 = puVar2[9];
        return 1;
      }
    }
  }
  return 0xfffffffe;
}


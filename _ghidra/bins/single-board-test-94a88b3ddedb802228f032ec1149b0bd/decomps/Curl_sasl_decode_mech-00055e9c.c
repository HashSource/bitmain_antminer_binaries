
undefined4 Curl_sasl_decode_mech(void *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  ushort **ppuVar2;
  char *__s2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  __s2 = "LOGIN";
  puVar3 = &DAT_0013a670;
  do {
    uVar4 = *puVar3;
    if ((uVar4 <= param_2) && (iVar1 = memcmp(param_1,__s2,uVar4), iVar1 == 0)) {
      if (param_3 != (uint *)0x0) {
        *param_3 = uVar4;
      }
      if (uVar4 == param_2) {
LAB_00055efa:
        return (&DAT_0013a674)[iVar5 * 3];
      }
      ppuVar2 = __ctype_b_loc();
      uVar4 = (uint)*(byte *)((int)param_1 + uVar4);
      if ((((*ppuVar2)[uVar4] & 0x900) == 0) && (uVar4 != 0x5f && uVar4 != 0x2d)) goto LAB_00055efa;
    }
    __s2 = (char *)puVar3[2];
    iVar5 = iVar5 + 1;
    puVar3 = puVar3 + 3;
    if (__s2 == (char *)0x0) {
      return 0;
    }
  } while( true );
}


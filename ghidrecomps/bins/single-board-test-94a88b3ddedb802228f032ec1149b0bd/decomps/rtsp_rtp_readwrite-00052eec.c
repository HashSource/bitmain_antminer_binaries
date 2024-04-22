
undefined4 rtsp_rtp_readwrite(int param_1,int *param_2,size_t *param_3,undefined *param_4)

{
  char cVar1;
  int iVar2;
  code **ppcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  void *__dest;
  char *__src;
  size_t __n;
  uint uVar7;
  code *pcVar8;
  
  if (param_2[0xf0] == 0) {
    __src = *(char **)(param_1 + 0xac);
    __n = *param_3;
    pcVar5 = (char *)0x0;
  }
  else {
    iVar4 = (**DAT_000530d4)(param_2[0xf0],param_2[0xf1] + *param_3);
    if (iVar4 == 0) {
      (**DAT_000530e0)(param_2[0xf0]);
      param_2[0xf0] = 0;
      param_2[0xf1] = 0;
      return 0x1b;
    }
    param_2[0xf0] = iVar4;
    memcpy((void *)(iVar4 + param_2[0xf1]),*(void **)(param_1 + 0xac),*param_3);
    pcVar5 = (char *)param_2[0xf0];
    __n = param_2[0xf1] + *param_3;
    param_2[0xf1] = __n;
    __src = pcVar5;
  }
  if ((int)__n < 1) {
LAB_0005302e:
    if (__n != 0) {
      cVar1 = *__src;
      goto LAB_00053064;
    }
  }
  else {
    if (*__src != '$') goto LAB_00053036;
    if (4 < (int)__n) {
      param_2[0xf2] = (uint)(byte)__src[1];
      uVar7 = (uint)CONCAT11(__src[2],__src[3]);
      if ((int)(uVar7 + 3) < (int)__n) {
        iVar4 = *param_2;
        pcVar8 = *(code **)(iVar4 + 0x1b0);
        do {
          iVar2 = uVar7 + 4;
          if (pcVar8 == (code *)0x0) {
            pcVar8 = *(code **)(iVar4 + 0x1a8);
          }
          iVar6 = (*pcVar8)(__src,1,iVar2,*(undefined4 *)(iVar4 + 0x16c));
          if (iVar6 == 0x10000001) {
            Curl_failf(iVar4,DAT_000530e4);
LAB_00052fa0:
            Curl_failf(param_1,DAT_000530dc);
            ppcVar3 = DAT_000530e0;
            iVar4 = param_2[0xf0];
            *param_4 = 0;
            (**ppcVar3)(iVar4);
            param_2[0xf0] = 0;
            param_2[0xf1] = 0;
            return 0x17;
          }
          if (iVar2 != iVar6) {
            Curl_failf(iVar4,DAT_000530d8);
            goto LAB_00052fa0;
          }
          __src = __src + iVar2;
          __n = __n + (-4 - uVar7);
          if (*(int *)(param_1 + 0x40c) == 0xb) {
            *(uint *)(param_1 + 0x130) = *(uint *)(param_1 + 0x130) & 0xfffffffe;
          }
          if ((int)__n < 1) goto LAB_0005302e;
          if (*__src != '$') goto LAB_00053032;
          if ((int)__n < 5) break;
          param_2[0xf2] = (uint)(byte)__src[1];
          uVar7 = (uint)CONCAT11(__src[2],__src[3]);
          if ((int)__n <= (int)(uVar7 + 3)) break;
          iVar4 = *param_2;
          pcVar8 = *(code **)(iVar4 + 0x1b0);
        } while( true );
      }
    }
    *param_4 = 1;
    cVar1 = *__src;
LAB_00053064:
    if (cVar1 == '$') {
      __dest = (void *)(**DAT_000530e8)(__n);
      if (__dest != (void *)0x0) {
        memcpy(__dest,__src,__n);
        (**DAT_000530e0)(param_2[0xf0]);
        param_2[0xf0] = (int)__dest;
        param_2[0xf1] = __n;
        *param_3 = 0;
        return 0;
      }
      (**DAT_000530e0)(param_2[0xf0]);
      param_2[0xf0] = 0;
      param_2[0xf1] = 0;
      return 0x1b;
    }
  }
LAB_00053032:
  pcVar5 = (char *)param_2[0xf0];
LAB_00053036:
  ppcVar3 = DAT_000530e0;
  *(size_t *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + (*param_3 - __n);
  pcVar8 = *ppcVar3;
  *param_3 = __n;
  (*pcVar8)(pcVar5);
  param_2[0xf0] = 0;
  param_2[0xf1] = 0;
  return 0;
}


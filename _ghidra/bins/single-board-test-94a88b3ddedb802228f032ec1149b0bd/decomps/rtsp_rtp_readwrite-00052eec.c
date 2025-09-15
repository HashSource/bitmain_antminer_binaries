
undefined4 rtsp_rtp_readwrite(int param_1,int *param_2,size_t *param_3,undefined1 *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  void *__dest;
  char *__src;
  size_t __n;
  uint uVar6;
  code *pcVar7;
  
  if (param_2[0xf0] == 0) {
    __src = *(char **)(param_1 + 0xac);
    __n = *param_3;
    pcVar4 = (char *)0x0;
  }
  else {
    iVar3 = (*Curl_crealloc)(param_2[0xf0],param_2[0xf1] + *param_3);
    if (iVar3 == 0) {
      (*Curl_cfree)(param_2[0xf0]);
      param_2[0xf0] = 0;
      param_2[0xf1] = 0;
      return 0x1b;
    }
    param_2[0xf0] = iVar3;
    memcpy((void *)(iVar3 + param_2[0xf1]),*(void **)(param_1 + 0xac),*param_3);
    pcVar4 = (char *)param_2[0xf0];
    __n = param_2[0xf1] + *param_3;
    param_2[0xf1] = __n;
    __src = pcVar4;
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
      uVar6 = (uint)CONCAT11(__src[2],__src[3]);
      if ((int)(uVar6 + 3) < (int)__n) {
        iVar3 = *param_2;
        pcVar7 = *(code **)(iVar3 + 0x1b0);
        do {
          iVar2 = uVar6 + 4;
          if (pcVar7 == (code *)0x0) {
            pcVar7 = *(code **)(iVar3 + 0x1a8);
          }
          iVar5 = (*pcVar7)(__src,1,iVar2,*(undefined4 *)(iVar3 + 0x16c));
          if (iVar5 == 0x10000001) {
            Curl_failf(iVar3,"Cannot pause RTP");
LAB_00052fa0:
            Curl_failf(param_1,"Got an error writing an RTP packet");
            iVar3 = param_2[0xf0];
            *param_4 = 0;
            (*Curl_cfree)(iVar3);
            param_2[0xf0] = 0;
            param_2[0xf1] = 0;
            return 0x17;
          }
          if (iVar2 != iVar5) {
            Curl_failf(iVar3,"Failed writing RTP data");
            goto LAB_00052fa0;
          }
          __src = __src + iVar2;
          __n = __n + (-4 - uVar6);
          if (*(int *)(param_1 + 0x40c) == 0xb) {
            *(uint *)(param_1 + 0x130) = *(uint *)(param_1 + 0x130) & 0xfffffffe;
          }
          if ((int)__n < 1) goto LAB_0005302e;
          if (*__src != '$') goto LAB_00053032;
          if ((int)__n < 5) break;
          param_2[0xf2] = (uint)(byte)__src[1];
          uVar6 = (uint)CONCAT11(__src[2],__src[3]);
          if ((int)__n <= (int)(uVar6 + 3)) break;
          iVar3 = *param_2;
          pcVar7 = *(code **)(iVar3 + 0x1b0);
        } while( true );
      }
    }
    *param_4 = 1;
    cVar1 = *__src;
LAB_00053064:
    if (cVar1 == '$') {
      __dest = (void *)(*Curl_cmalloc)(__n);
      if (__dest != (void *)0x0) {
        memcpy(__dest,__src,__n);
        (*Curl_cfree)(param_2[0xf0]);
        param_2[0xf0] = (int)__dest;
        param_2[0xf1] = __n;
        *param_3 = 0;
        return 0;
      }
      (*Curl_cfree)(param_2[0xf0]);
      param_2[0xf0] = 0;
      param_2[0xf1] = 0;
      return 0x1b;
    }
  }
LAB_00053032:
  pcVar4 = (char *)param_2[0xf0];
LAB_00053036:
  *(size_t *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + (*param_3 - __n);
  pcVar7 = Curl_cfree;
  *param_3 = __n;
  (*pcVar7)(pcVar4);
  param_2[0xf0] = 0;
  param_2[0xf1] = 0;
  return 0;
}


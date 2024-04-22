
int Curl_sasl_decode_ntlm_type2_message(undefined4 param_1,char *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  size_t __n;
  uint uVar4;
  void *__dest;
  undefined4 uVar5;
  size_t sVar6;
  void *local_30;
  uint local_2c [2];
  
  local_30 = (void *)0x0;
  local_2c[0] = 0;
  if (*param_2 != '=' && *param_2 != '\0') {
    iVar2 = Curl_base64_decode(param_2,&local_30,local_2c);
    pvVar3 = local_30;
    if (iVar2 != 0) {
      return iVar2;
    }
    if (local_30 != (void *)0x0) {
      *(undefined4 *)(param_3 + 4) = 0;
      if (((local_2c[0] < 0x20) || (iVar2 = memcmp(local_30,DAT_00054c50,8), iVar2 != 0)) ||
         (iVar2 = memcmp((void *)((int)pvVar3 + 8),DAT_00054c5c,4), iVar2 != 0)) {
        iVar2 = 0x3d;
        goto LAB_00054b98;
      }
      iVar2 = Curl_read32_le((int)pvVar3 + 0x14);
      uVar1 = local_2c[0];
      pvVar3 = local_30;
      *(int *)(param_3 + 4) = iVar2;
      uVar5 = *(undefined4 *)((int)local_30 + 0x1c);
      *(undefined4 *)(param_3 + 8) = *(undefined4 *)((int)local_30 + 0x18);
      *(undefined4 *)(param_3 + 0xc) = uVar5;
      if (iVar2 << 8 < 0) {
        sVar6 = 0;
        if (0x2f < local_2c[0]) {
          __n = Curl_read16_le((int)local_30 + 0x28);
          uVar4 = Curl_read32_le((int)pvVar3 + 0x2c);
          if (__n != 0) {
            if ((uVar1 < __n + uVar4) || (uVar4 < 0x30)) {
              iVar2 = 0x3d;
              Curl_infof(param_1,DAT_00054c60);
              pvVar3 = local_30;
LAB_00054b98:
              (**DAT_00054c54)(pvVar3);
              Curl_infof(param_1,DAT_00054c58);
              return iVar2;
            }
            __dest = (void *)(**DAT_00054c64)(__n);
            *(void **)(param_3 + 0x10) = __dest;
            if (__dest == (void *)0x0) {
              iVar2 = 0x1b;
              pvVar3 = local_30;
              goto LAB_00054b98;
            }
            memcpy(__dest,(void *)((int)pvVar3 + uVar4),__n);
            sVar6 = __n;
          }
        }
        *(size_t *)(param_3 + 0x14) = sVar6;
      }
      (**DAT_00054c54)(local_30);
      return 0;
    }
  }
  Curl_infof(param_1,DAT_00054c4c);
  return 0x3d;
}


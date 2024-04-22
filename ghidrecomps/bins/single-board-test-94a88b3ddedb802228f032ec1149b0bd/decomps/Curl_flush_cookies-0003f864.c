
void Curl_flush_cookies(int param_1,int param_2)

{
  bool bVar1;
  code **ppcVar2;
  int iVar3;
  int *piVar4;
  char *__filename;
  FILE *__s;
  
  if (*(int *)(param_1 + 0x34c) == 0) {
    if ((param_2 != 0) && (*(int *)(param_1 + 0x460) != 0)) {
      curl_slist_free_all();
      *(undefined4 *)(param_1 + 0x460) = 0;
    }
    Curl_share_lock(param_1,2,2);
  }
  else {
    if (*(int *)(param_1 + 0x460) != 0) {
      Curl_cookie_loadfiles();
    }
    Curl_share_lock(param_1,2,2);
    piVar4 = *(int **)(param_1 + 0x468);
    __filename = *(char **)(param_1 + 0x34c);
    if ((piVar4 != (int *)0x0) && (piVar4[3] != 0)) {
      remove_expired(piVar4);
      iVar3 = curl_strequal(DAT_0003f974,__filename);
      if (iVar3 == 0) {
        __s = fopen64(__filename,DAT_0003f98c);
        bVar1 = false;
        if (__s == (FILE *)0x0) {
LAB_0003f948:
          Curl_infof(param_1,DAT_0003f988,*(undefined4 *)(param_1 + 0x34c));
          goto LAB_0003f896;
        }
      }
      else {
        bVar1 = true;
        __s = *DAT_0003f978;
      }
      fwrite(DAT_0003f97c,1,0x88,__s);
      ppcVar2 = DAT_0003f990;
      for (piVar4 = (int *)*piVar4; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        if (piVar4[5] != 0) {
          iVar3 = get_netscape_format(piVar4);
          if (iVar3 == 0) {
            curl_mfprintf(__s,DAT_0003f984);
            if (!bVar1) {
              fclose(__s);
            }
            goto LAB_0003f948;
          }
          curl_mfprintf(__s,DAT_0003f980,iVar3);
          (**ppcVar2)(iVar3);
        }
      }
      if (!bVar1) {
        fclose(__s);
      }
    }
  }
LAB_0003f896:
  if (param_2 != 0) {
    if (*(int *)(param_1 + 0x48) == 0) {
      iVar3 = *(int *)(param_1 + 0x468);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x468);
      if (iVar3 == *(int *)(*(int *)(param_1 + 0x48) + 0x2c)) goto LAB_0003f8b0;
    }
    Curl_cookie_cleanup(iVar3);
  }
LAB_0003f8b0:
  Curl_share_unlock(param_1,2);
  return;
}


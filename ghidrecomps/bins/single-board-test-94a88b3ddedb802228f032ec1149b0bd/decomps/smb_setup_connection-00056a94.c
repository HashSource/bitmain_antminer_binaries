
int smb_setup_connection(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *local_14;
  
  iVar5 = *param_1;
  iVar2 = (**DAT_00056b4c)(1,0x14);
  *(int *)(iVar5 + 0x14c) = iVar2;
  if (iVar2 == 0) {
    iVar2 = 0x1b;
  }
  else {
    iVar2 = *param_1;
    iVar5 = *(int *)(iVar2 + 0x14c);
    iVar2 = Curl_urldecode(iVar2,*(undefined4 *)(iVar2 + 0x868c),0,&local_14,0,1);
    if (iVar2 == 0) {
      pcVar3 = local_14;
      if (*local_14 == '/' || *local_14 == '\\') {
        pcVar3 = local_14 + 1;
      }
      pcVar3 = (char *)(**DAT_00056b50)(pcVar3);
      *(char **)(iVar5 + 4) = pcVar3;
      if (pcVar3 == (char *)0x0) {
        iVar2 = 0x1b;
        (**DAT_00056b54)(local_14);
      }
      else {
        pcVar4 = strchr(pcVar3,0x2f);
        if ((pcVar4 == (char *)0x0) && (pcVar4 = strchr(pcVar3,0x5c), pcVar4 == (char *)0x0)) {
          iVar2 = 3;
          (**DAT_00056b54)(local_14);
        }
        else {
          *pcVar4 = '\0';
          *(char **)(iVar5 + 8) = pcVar4 + 1;
          cVar1 = pcVar4[1];
          pcVar3 = pcVar4 + 2;
          while (cVar1 != '\0') {
            if (cVar1 == '/') {
              pcVar3[-1] = '\\';
            }
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          }
          (**DAT_00056b54)(local_14);
        }
      }
    }
  }
  return iVar2;
}


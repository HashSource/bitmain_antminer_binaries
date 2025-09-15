
undefined4 check_telnet_options(int *param_1)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 local_198;
  undefined1 auStack_194 [124];
  undefined4 local_118;
  undefined4 auStack_114 [63];
  
  local_198 = 0;
  memset(auStack_194,0,0x7c);
  local_118 = 0;
  memset(auStack_114,0,0xfc);
  iVar6 = *param_1;
  iVar5 = *(int *)(iVar6 + 0x14c);
  if (*(char *)((int)param_1 + 0x1f1) != '\0') {
    curl_msnprintf(&local_118,0x100,"USER,%s",param_1[0x48]);
    iVar1 = curl_slist_append(*(undefined4 *)(iVar5 + 0x1cac),&local_118);
    if (iVar1 == 0) {
      curl_slist_free_all(*(undefined4 *)(iVar5 + 0x1cac));
      *(undefined4 *)(iVar5 + 0x1cac) = 0;
      return 0x1b;
    }
    *(int *)(iVar5 + 0x1cac) = iVar1;
    *(undefined4 *)(iVar5 + 0x8a4) = 1;
  }
  puVar3 = *(undefined4 **)(iVar6 + 0x268);
  do {
    while( true ) {
      if (puVar3 == (undefined4 *)0x0) {
        return 0;
      }
      iVar1 = __isoc99_sscanf(*puVar3,"%127[^= ]%*[ =]%255s",&local_198,&local_118);
      if (iVar1 != 2) {
        Curl_failf(iVar6,"Syntax error in telnet option: %s",*puVar3);
        uVar4 = 0x31;
        goto LAB_0004950e;
      }
      iVar1 = Curl_raw_equal(&local_198,"TTYPE");
      if (iVar1 == 0) break;
      strncpy((char *)(iVar5 + 0x1c08),(char *)&local_118,0x1f);
      *(undefined1 *)(iVar5 + 0x1c27) = 0;
      *(undefined4 *)(iVar5 + 0x868) = 1;
LAB_0004940e:
      puVar3 = (undefined4 *)puVar3[1];
    }
    iVar1 = Curl_raw_equal(&local_198,"XDISPLOC");
    if (iVar1 == 0) {
      iVar1 = Curl_raw_equal(&local_198,"NEW_ENV");
      if (iVar1 == 0) {
        iVar1 = Curl_raw_equal(&local_198,&DAT_00137400);
        if (iVar1 == 0) {
          iVar1 = Curl_raw_equal(&local_198,"BINARY");
          if (iVar1 == 0) {
            Curl_failf(iVar6,"Unknown telnet option %s",*puVar3);
            uVar4 = 0x30;
LAB_0004950e:
            curl_slist_free_all(*(undefined4 *)(iVar5 + 0x1cac));
            *(undefined4 *)(iVar5 + 0x1cac) = 0;
            return uVar4;
          }
          lVar2 = strtol((char *)&local_118,(char **)0x0,10);
          if (lVar2 != 1) {
            *(undefined4 *)(iVar5 + 0x808) = 0;
            *(undefined4 *)(iVar5 + 0x1408) = 0;
          }
        }
        else {
          iVar1 = __isoc99_sscanf(&local_118,"%hu%*[xX]%hu",iVar5 + 0x1ca8,iVar5 + 0x1caa);
          if (iVar1 != 2) {
            uVar4 = 0x31;
            Curl_failf(iVar6,"Syntax error in telnet option: %s",*puVar3);
            goto LAB_0004950e;
          }
          *(undefined4 *)(iVar5 + 0x884) = 1;
        }
      }
      else {
        iVar1 = curl_slist_append(*(undefined4 *)(iVar5 + 0x1cac),&local_118);
        if (iVar1 == 0) {
          uVar4 = 0x1b;
          goto LAB_0004950e;
        }
        *(int *)(iVar5 + 0x1cac) = iVar1;
        *(undefined4 *)(iVar5 + 0x8a4) = 1;
      }
      goto LAB_0004940e;
    }
    strncpy((char *)(iVar5 + 0x1c28),(char *)&local_118,0x7f);
    *(undefined1 *)(iVar5 + 0x1ca7) = 0;
    puVar3 = (undefined4 *)puVar3[1];
    *(undefined4 *)(iVar5 + 0x894) = 1;
  } while( true );
}

